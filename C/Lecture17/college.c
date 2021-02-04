#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****** Constants ************/
#define MAX_DEPT 25
#define MAX_INSTRUCTORS 30
#define MAX_COURSES 100
#define MAX_CLASSROOMS 100
/*****************************/

/**** Struct definitions *****/
struct locationT
{
	char strBuilding[100]; /* Building name */
	char strRoom[10]; /* Room number */
};

struct instructorRecT
{
	char strName[50]; /* Instructor name */
	struct locationT office; /* Instructor office */
};

struct courseRecT
{
	char strName[50]; /* Course name */
	char strCourseNumber[10]; /* Course number */
	int nUnits; /* Course units/credits */
	struct locationT *pCourseLoc; /* Course location */
	struct instructorRecT *pInstructor; /* Course instructor */
};

struct departmentRecT
{
	char strName[50]; /* Department name */
	struct instructorRecT *pInstructors[MAX_INSTRUCTORS]; /* Instructors array */
	struct courseRecT *pCourses[MAX_COURSES]; /* Courses array*/
	int nInstructors, nCourses; /* number of instructors and courses */
};

struct schoolDBT
{
	struct departmentRecT *pDepts[MAX_DEPT];
	struct locationT *pClassrooms[MAX_CLASSROOMS];
	int nDepts, nClassrooms;
};
/*****************************/

/**** Functions **************/

/*** Function Declarations ***/
struct locationT* schoolDBT_FindClassroom(struct schoolDBT *db,
	const char* bldg,
	const char* room);

/*** Functions related to departmentRecT ***/
void departmentRecT_ReadInstructors(struct departmentRecT *pDept, const char* instrFileName)
{
	char line[256];
	FILE *fp;

	if ((fp = fopen(instrFileName, "r")) == NULL) return; /* error */
	pDept->nInstructors = 0;
	while (fgets(line, 256, fp)) // read line by line
	{
		pDept->pInstructors[pDept->nInstructors] = (struct instructorRecT*)malloc(sizeof(struct instructorRecT));
		sscanf(line, "%s %s %s",
			pDept->pInstructors[pDept->nInstructors]->strName,
			pDept->pInstructors[pDept->nInstructors]->office.strBuilding,
			pDept->pInstructors[pDept->nInstructors]->office.strRoom);
		pDept->nInstructors++;
	}
	fclose(fp);
}

struct instructorRecT* departmentRecT_FindInstructor(struct departmentRecT *pDept, const char* instrName)
{
	int i;
	for (i = 0; i<pDept->nInstructors; i++)
	if (strcmp(pDept->pInstructors[i]->strName, instrName) == 0)
		return pDept->pInstructors[i];
	return NULL; // cannot find instructor
}

void departmentRecT_ReadCourses(struct departmentRecT *pDept, const char* coursesFileName, struct schoolDBT *db)
{
	char line[256], bldg[100], room[10], instrName[50];
	FILE *fp;

	if ((fp = fopen(coursesFileName, "r")) == NULL) return; /* error */
	pDept->nCourses = 0;
	while (fgets(line, 256, fp)) // read line by line
	{
		pDept->pCourses[pDept->nCourses] = (struct courseRecT*)malloc(sizeof(struct courseRecT));
		sscanf(line, "%s %s %d %s %s %s",
			pDept->pCourses[pDept->nCourses]->strName,
			pDept->pCourses[pDept->nCourses]->strCourseNumber,
			&(pDept->pCourses[pDept->nCourses]->nUnits),
			bldg, room, instrName);
		pDept->pCourses[pDept->nCourses]->pCourseLoc = schoolDBT_FindClassroom(db, bldg, room);
		pDept->pCourses[pDept->nCourses]->pInstructor = departmentRecT_FindInstructor(pDept, instrName);
		pDept->nCourses++;
	}
	fclose(fp);
}

int departmentRecT_CountUnits(struct departmentRecT *pDept)
{
	int i, sum;

	for (i = 0, sum = 0; i < pDept->nCourses; i++)
		sum += pDept->pCourses[i]->nUnits;
	return sum;
}

void departmentRecT_free(struct departmentRecT *pDept)
{
	int i;
	/* free memory of instructors */
	for (i = 0; i < pDept->nInstructors; i++)
	{
		free(pDept->pInstructors[i]);
	}
	/* free memory of courses */
	for (i = 0; i < pDept->nCourses; i++)
	{
		free(pDept->pCourses[i]);
	}
}

/*** Functions related to schoolDBT ***/
void schoolDBT_InitDepartment(struct schoolDBT *db,
							const char* deptName,
							const char* instrFileName,
							const char* coursesFileName)
{
	db->pDepts[db->nDepts] = (struct departmentRecT*)malloc(sizeof(struct departmentRecT));
	strcpy(db->pDepts[db->nDepts]->strName, deptName);
	departmentRecT_ReadInstructors(db->pDepts[db->nDepts], instrFileName);
	departmentRecT_ReadCourses(db->pDepts[db->nDepts], coursesFileName, db);
	db->nDepts++;
}

struct locationT* schoolDBT_FindClassroom(struct schoolDBT *db,
										const char* bldg,
										const char* room)
{
	int i;
	for (i = 0; i < db->nClassrooms; i++)
	if (strcmp(db->pClassrooms[i]->strBuilding, bldg) == 0 &&
		strcmp(db->pClassrooms[i]->strRoom, room) == 0)
		return db->pClassrooms[i];
	db->pClassrooms[db->nClassrooms] = (struct locationT*)malloc(sizeof(struct locationT));
	strcpy(db->pClassrooms[db->nClassrooms]->strBuilding, bldg);
	strcpy(db->pClassrooms[db->nClassrooms]->strRoom, room);
	db->nClassrooms++;
	return db->pClassrooms[db->nClassrooms - 1];
}

void schoolDBT_UnitsByDepartment(struct schoolDBT *db)
{
	int i;
	for (i = 0; i<db->nDepts; i++)
	{
		printf("\n%s is teaching %d units\n",
			db->pDepts[i]->strName,
			departmentRecT_CountUnits(db->pDepts[i]));
	}
}

void schoolDBT_ListInstructors(struct schoolDBT *db)
{
	int i, j, k;
	char instName[50];

	for (i = 0; i<db->nDepts; i++)
	{
		printf("\n%s\n", db->pDepts[i]->strName);
		for (j = 0; j < db->pDepts[i]->nInstructors; j++)
		{
			printf("     %s\n",
				db->pDepts[i]->pInstructors[j]->strName);
			for (k = 0; k < db->pDepts[i]->nCourses; k++)
			if (strcmp(instName,
				db->pDepts[i]->pCourses[k]->pInstructor->strName) == 0)
				printf("  %s  %s\n",
				  db->pDepts[i]->pCourses[k]->strCourseNumber,
				  db->pDepts[i]->pCourses[k]->strName);
		}
	}
}

void schoolDBT_free(struct schoolDBT *db)
{
	int i;
	/* free memory of departments */
	for (i = 0; i < db->nDepts; i++)
	{
		departmentRecT_free(db->pDepts[i]);
		free(db->pDepts[i]);
	}
	/* free memory of classrooms */
	for (i = 0; i < db->nClassrooms; i++)
	{
		free(db->pClassrooms[i]);
	}
}

/**********************************/
main()
{
	struct schoolDBT sDB;

	sDB.nDepts = 0;
	sDB.nClassrooms = 0;

	schoolDBT_InitDepartment(&sDB, "ECE",
						"ECE_Instructors.txt",
						"ECE_Courses.txt");
	schoolDBT_ListInstructors(&sDB);
	schoolDBT_UnitsByDepartment(&sDB);
	schoolDBT_free(&sDB); /* free memory */
}

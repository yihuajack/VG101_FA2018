#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct book {
	int id;
	char title[1000];
	char status[9];
};
struct customer {
	int id,nown;
	char name[100];
	struct book *bookown[1000];
};
struct library {
	struct book *booklib[1000];
	struct customer *custlib[100];
	int nbook,ncust;
};
void listbook(struct library *lib);
void listcustomer(struct library *lib);
void addbook(struct library *lib,const char*command);
void addcustomer(struct library *lib,const char*command);
void checkb1(struct library *lib, const char*command);
void checkb2(struct library *lib, const char*command);
void borrow(struct library *lib, const char*command);
void _return(struct library *lib, const char*command);
void checkc(struct library *lib, const char*command);
int main(){
	int i,j,exit = 0;
    char command[1014];
	struct library lib;
	lib.nbook = 0; lib.ncust = 0;
    printf("Welcome to the library management system, please type your commands.\n> ");
	while (1) {
		scanf("%[^\n]", command); getchar();
		if (strcmp(command,"exit")==0){exit = 1;break;}
		else if (strcmp(command,"listbook")==0) listbook(&lib);
		else if (strcmp(command,"listcustomer")==0) listcustomer(&lib);
		else if (strncmp(command,"addbook",7)==0) addbook(&lib,command);
		else if (strncmp(command,"addcustomer",11)==0) addcustomer(&lib,command);
		else if (strncmp(command, "checkb1", 7) == 0) checkb1(&lib, command);
		else if (strncmp(command, "checkb2", 7) == 0) checkb2(&lib, command);
		else if (strncmp(command, "borrow", 6) == 0) borrow(&lib, command);
		else if (strncmp(command, "return", 6) == 0)_return(&lib, command);
		else if (strncmp(command, "checkc", 6) == 0) {checkc(&lib, command); continue;}
		else printf("Unknown command!");
		printf("\n> ");
	}
	if (exit == 1) printf("Exit the system!\n");
	for (i = 0; i < lib.nbook; i++) free(lib.booklib[i]);
	for (i = 0; i < lib.ncust; i++) {
		for (j = 0; j < lib.custlib[i]->nown; j++) free(lib.custlib[i]->bookown[j]);
		free(lib.custlib[i]);
	}
    return 0;
}
void listbook(struct library *lib){
	int i;
	if (lib->nbook == 0) printf("There is no book in the system.");
	else {
		printf("%d %s %s", lib->booklib[0]->id, lib->booklib[0]->title, lib->booklib[0]->status);
		for (i = 1; i < lib->nbook; i++) {
			printf("\n%d %s %s", lib->booklib[i]->id, lib->booklib[i]->title, lib->booklib[i]->status);
		}
	}
}
void listcustomer(struct library *lib) {
	int i;
	if (lib->ncust == 0) printf("There is no customer in the system.");
	else {
		printf("%d %s", lib->custlib[0]->id, lib->custlib[0]->name);
		for (i = 1; i < lib->ncust; i++) {
			printf("\n%d %s", lib->custlib[i]->id, lib->custlib[i]->name);
		}
	}
}
void addbook(struct library *lib,const char*command) {
	int i,id,quit = 0;
	lib->booklib[lib->nbook] = (struct book*)malloc(sizeof(struct book));
	sscanf(command, "%*s%d%*s", &id);
	for (i = 0; i < lib->nbook; i++) {
		if (lib->booklib[i]->id == id) {
			printf("The book ID already exists."); quit = 1; break;
		}
	}
	if (quit == 0) {
		sscanf(command, "%*s%d%s", &(lib->booklib[lib->nbook]->id), lib->booklib[lib->nbook]->title);
		strcpy(lib->booklib[lib->nbook]->status, "on shelf");
		printf("%s added to the system.", lib->booklib[lib->nbook]->title);
		lib->nbook++;
	}
}
void addcustomer(struct library *lib,const char*command) {
	int i, id, quit = 0;
	lib->custlib[lib->ncust] = (struct customer*)malloc(sizeof(struct customer));
	sscanf(command, "%*s%d",&id);
	for (i = 0; i < lib->ncust; i++) {
		if (lib->custlib[i]->id == id) {
			printf("The customer ID already exists."); quit = 1; break;
		}
	}
	if (quit == 0) {
		sscanf(command, "%*s%d%s", &(lib->custlib[lib->ncust]->id), lib->custlib[lib->ncust]->name);
		printf("%s added to the system.", lib->custlib[lib->ncust]->name);
		lib->custlib[lib->ncust]->nown = 0;
		lib->ncust++;
	}
}
void checkb1(struct library *lib, const char*command) {
	int i,id;
	sscanf(command, "%*s%d", &id);
	for (i = 0; i < lib->nbook; i++) {
		if (lib->booklib[i]->id==id) printf("%d %s %s",lib->booklib[i]->id,lib->booklib[i]->title,lib->booklib[i]->status);
	}
}
void checkb2(struct library *lib, const char*command) {
	char title[1000]; int i;
	sscanf(command, "%*s%s", title);
	for (i = 0; i < lib->nbook; i++) {
		if (strcmp(lib->booklib[i]->title,title)==0) printf("%d %s %s", lib->booklib[i]->id, lib->booklib[i]->title, lib->booklib[i]->status);
	}
}
void borrow(struct library *lib, const char*command) {
	int i,j, bid,cid;
	sscanf(command, "%*s%d%d",&bid,&cid);
	for (i = 0; i < lib->nbook; i++) {
		if (lib->booklib[i]->id == bid) {
			if (*lib->booklib[i]->status == 'b') {printf("Fail! The book was borrowed by another customer."); break;}
			else {
				strcpy(lib->booklib[i]->status, "borrowed");
				for (j = 0; j < lib->ncust; j++) {
					if (lib->custlib[j]->id == cid) {printf("Success! %s is borrowed by %s.", lib->booklib[i]->title, lib->custlib[j]->name);break;}
				}
				lib->custlib[j]->bookown[lib->custlib[j]->nown] = (struct book*)malloc(sizeof(struct book));
				lib->custlib[j]->bookown[lib->custlib[j]->nown]->id = bid;
				strcpy(lib->custlib[j]->bookown[lib->custlib[j]->nown]->title, lib->booklib[i]->title);
				lib->custlib[j]->nown++;break;
			}
		}
	}
}
void _return(struct library *lib, const char*command) {
	int i,j,k,bid;
	sscanf(command, "%*s%d",&bid);
	for (i = 0; i < lib->nbook; i++) {
		if (lib->booklib[i]->id == bid) {
			if (*lib->booklib[i]->status == 'o') { printf("Fail! The book has not been borrowed."); break; }
			else {
				for (j = 0; j < lib->ncust; j++) {
					for (k = 0; k < lib->custlib[j]->nown; k++) {
						if (lib->custlib[j]->bookown[k]->id == bid) {
							strcpy(lib->booklib[i]->status, "on shelf");
							lib->custlib[j]->bookown[k]->id = -bid;
							printf("Success! The following book has been returned:\n%d %s",lib->booklib[i]->id,lib->booklib[i]->title); break;
						}
					}
				}
			}
		}
	}
}
void checkc(struct library *lib, const char*command) {
	int i,j,cid;
	sscanf(command, "%*s%d",&cid);
	for (i = 0; i < lib->ncust; i++) {
		for (j = 0; j < lib->custlib[i]->nown; j++) {
			printf("Book borrowed by %s:\n", lib->custlib[i]->name);
			if (lib->custlib[i]->bookown[j]->id>0&&lib->custlib[i]->id==cid) {
				printf("%d %s\n",lib->custlib[i]->bookown[j]->id,lib->custlib[i]->bookown[j]->title);
			}
		}
	}
	printf("> ");
}

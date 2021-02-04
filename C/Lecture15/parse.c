#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char cmdstr[256], cmd[10], para1[20], para2[20];
    int i, j;
    double result;
    /* 1: read user input */
    printf("> ");
    fgets(cmdstr, 256, stdin);
    cmdstr[strlen(cmdstr)-1] = 0; /* replace '\n' with '\0' */
    /* 2: extract command, para1, and para2 */
    i = 0;
    while (cmdstr[i] != ' ') i++; /* 1st space */
    strncpy(cmd, cmdstr, i);
    cmd[i] = 0; /* end of C-style string */
    j = i+1;
	while (cmdstr[j] != ' ') j++; /* 2nd space */
	strncpy(para1, &cmdstr[i+1], j-i);
	para1[j-i] = 0;
	strncpy(para2, &cmdstr[j+1], strlen(cmdstr)-j);
	para2[strlen(cmdstr)-j] = 0;
	/* 3: process the command */
	if (strcmp(cmd, "add") == 0)
		result = atof(para1) + atof(para2);
	else if (strcmp(cmd, "minus") == 0)
		result = atof(para1) - atof(para2);
	else if (strcmp(cmd, "times") == 0)
		result = atof(para1) * atof(para2);
	else if (strcmp(cmd, "div") == 0)
		result = atof(para1) / atof(para2);
    /* 4: display the result */
    printf("result = %g\n", result);
    return 0;
}

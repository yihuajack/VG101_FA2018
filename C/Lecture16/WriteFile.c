#include <stdio.h>

/* safe version of gets() */
char* vg101_gets(char *str, int count)
{
    int i = 0;
    char ch = getchar();
    
    while (ch != '\n' && i < count-1)
    {
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0'; /* add the null character */
}

int main ()
{
   FILE * pFile;
   int n;
   char name [100];

   pFile = fopen("myfile.txt","w");
   for (n=0 ; n<3 ; n++)
   {
     puts("please, enter a name: ");
     vg101_gets(name, 100);
     fprintf(pFile, "Name %d [%-10.10s]\n",n,name);
   }
   fclose(pFile);

   return 0;
}


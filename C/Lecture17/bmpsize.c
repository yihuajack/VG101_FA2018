#include <stdio.h>

int main()
{
	FILE *fp;
	int width, height;
	if ((fp = fopen("lena_part.bmp", "r")) != NULL)
	{
		fseek(fp, 18, SEEK_SET);
		fread(&width, sizeof(int), 1, fp);
		fread(&height, sizeof(int), 1, fp);
		printf("width = %d, height = %d\n", width, height);
		fclose(fp);
	}
    return 0;
}

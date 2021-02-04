#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "JGPL_Img.h"
#include "JGPL_Plot.h"

void im2bw(const char *bmpfilename, double threshold)
{
	int i, nWidth, nHeight;
	double *pImg = NULL;
	char newfilename[255] = "bw_";

	JGPL_Img_BmpLoad(bmpfilename, &pImg, &nWidth, &nHeight);
	for (i=0; i<nWidth * nHeight; i++)
		if (pImg[i] >= threshold) pImg[i] = 255;
		else pImg[i] = 0;
	strcat(newfilename, bmpfilename);
	JGPL_Img_BmpSave(newfilename, pImg, nWidth, nHeight, 0, 0, 0);

	if(pImg) free(pImg);
}

/* Note: please uncomment each part for testing */
int main()
{
/* Part 1: read in lena_gray.dat, save to bmp file */
/*	FILE *fp;
	int i;
	unsigned char *pImg = (unsigned char*)malloc(65536);
	double *pImg2 = (double*)malloc(sizeof(double)* 65536);

	fp = fopen("lena_gray.dat", "r");
	fread(pImg, 65536, 1, fp);
	fclose(fp);
	for (i = 0; i < 65536; i++) pImg2[i] = pImg[i];

	JGPL_Img_BmpSave("temp.bmp", pImg2, 256, 256, 2, 0, 0);
	free(pImg);
	free(pImg2);
*/

/* Part 2: test the Bmp Load and Save */
/*	int nWidth, nHeight;
	double *pImg = NULL;

	JGPL_Img_BmpLoad("temp.bmp", &pImg, &nWidth, &nHeight);
	printf("Width = %d, Height = %d\n", nWidth, nHeight);
	JGPL_Img_BmpSave("temp2.bmp", pImg, nWidth, nHeight, 2, 0, 0);
	if(pImg) free(pImg);
*/

/* Part 3: test the im2bw */
/*	im2bw("temp.bmp", 127); */

/* Part 4: plot example, sin and circle */
	int i;
	double x[100], y[100];
	for (i = 0; i < 100; i++)
	{
		x[i] = i;
		y[i] = cos(i / 100.0 * 4 * 3.14);
	}
	JGPL_Plot_2d(100, x, y, 640, 480, 0, 1, 0, "cos.bmp");

	
	for (i=0; i<100; i++)
	{
		x[i] = cos(i*2*3.14/99);
		y[i] = sin(i*2*3.14/99);
	}
	JGPL_Plot_2d(100, x, y, 512, 512, 0, 0 ,0 ,"circle.bmp");

}

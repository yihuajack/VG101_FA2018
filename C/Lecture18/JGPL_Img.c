/* Author: Jigang Wu
**************************/
#include <stdio.h>
#include <stdlib.h>
#include "JGPL_Img.h"

/* Please make sure the int length is correct
before using this file, here we assume the compiler
support stdint.h, which is C99 standard */
#include <stdint.h>

typedef struct JGPL_BMPFILEHEADER
{/* BMP File Header */
	uint16_t nMagicNumber;
	uint32_t nSize;
	uint16_t nReserved1;
	uint16_t nReserved2;
	uint32_t nOffset;
} JGPL_tBmpFileHeader;

typedef struct JGPL_BMPINFO
{/* BMP DIB Header, Windows V3 Header */
	uint32_t nHeaderSize;
	int32_t nWidth;
	int32_t nHeight;
	uint16_t nPlanes;
	uint16_t nBitCount;
	uint32_t nCompression;
	uint32_t nImageSize;
	int32_t nXPixelPerMeter;
	int32_t nYPixelPerMeter;
	uint32_t nUsedColor;
	uint32_t nImportantColor;
} JGPL_tBmpInfo;

/* JGPL_Img_BmpSave
Save gray scale (8-bit) bmp file with file name pccFileName, 2D data pData with dimensions nWidth x nHeight
pData (double type) is row by row, start from the upper left corner (Note that bmp data start from the lower left corner by default)
nMode = 0: scale the data to [0 255], then save, in this case, dMin and dMax is not used
nMode = 1: scale the data according to the range [dMin dMax]
nMode = 2: don't scale the data, save as it is
return value: -1 - cannot open file */
int JGPL_Img_BmpSave(const char* pccFileName, double *pData, int nWidth, int nHeight, int nMode, double dMin, double dMax)
{
	FILE *fp;
	JGPL_tBmpFileHeader BmpFileHeader;
	JGPL_tBmpInfo BmpInfo;
	unsigned char temp, *pBmpData; /* 8-bit data for saving */
	unsigned int i, j;
	double tempd;

	/* open file */
	if ((fp=fopen(pccFileName, "wb")) == NULL) return -1; /* cannot open file */
	/* set bmp file header and save */
	BmpFileHeader.nMagicNumber = 0x4D42; /* "BM" */
	BmpFileHeader.nSize = nWidth * nHeight + 54 + 4*256; /* + header size + color palette size */
	BmpFileHeader.nReserved1 = 0;
	BmpFileHeader.nReserved2 = 0;
	BmpFileHeader.nOffset = 54 + 4*256;
	/* avoid using fwrite(&BmpFileHeader, 14, 1, fp) because of saving problem */
	fwrite(&BmpFileHeader.nMagicNumber, 2, 1, fp);
	fwrite(&BmpFileHeader.nSize, 4, 1, fp);
	fwrite(&BmpFileHeader.nReserved1, 2, 1, fp);
	fwrite(&BmpFileHeader.nReserved2, 2, 1, fp);
	fwrite(&BmpFileHeader.nOffset, 4, 1, fp);
	/* set bitmap information and save */
	BmpInfo.nHeaderSize = 40;
	BmpInfo.nWidth = nWidth;
	BmpInfo.nHeight = nHeight;
	BmpInfo.nPlanes = 1;
	BmpInfo.nBitCount = 8; /* gray-scale image */
	BmpInfo.nCompression = 0;
	BmpInfo.nImageSize = nWidth * nHeight;
	BmpInfo.nXPixelPerMeter = 0; /* no real size information */
	BmpInfo.nYPixelPerMeter = 0; /* no real size information */
	BmpInfo.nUsedColor = 256;
	BmpInfo.nImportantColor = 0;
	/* avoid using fwrite(&BmpInfo, 40, 1, fp) because of saving problem */
	fwrite(&BmpInfo.nHeaderSize, 4, 1, fp);
	fwrite(&BmpInfo.nWidth, 4, 1, fp);
	fwrite(&BmpInfo.nHeight, 4, 1, fp);
	fwrite(&BmpInfo.nPlanes, 2, 1, fp);
	fwrite(&BmpInfo.nBitCount, 2, 1, fp);
	fwrite(&BmpInfo.nCompression, 4, 1, fp);
	fwrite(&BmpInfo.nImageSize, 4, 1, fp);
	fwrite(&BmpInfo.nXPixelPerMeter, 4, 1, fp);
	fwrite(&BmpInfo.nYPixelPerMeter, 4, 1, fp);
	fwrite(&BmpInfo.nUsedColor, 4, 1, fp);
	fwrite(&BmpInfo.nImportantColor, 4, 1, fp);
	/* set color palette and save */
	for (i=0; i<256; i++)
	{
		for (j=0; j<3; j++) fwrite(&i, 1, 1, fp);
		j=0; fwrite(&j, 1, 1, fp);
	}
	/* set bitmap data and save
	   when nMode == 0, set dMin and dMax as minimum and maximum value of the data */
	if (nMode == 0)
	{
		dMin = dMax = pData[0];
		for (i=1; i<BmpInfo.nImageSize; i++)
		{
			if (pData[i] < dMin) dMin = pData[i];
			else if (pData[i] > dMax) dMax = pData[i];
		}
		if (dMin == dMax) nMode = 2; /* no variation, save as it is */
	}
	/* scale the data to [dMin dMax], using the 8-bit pBmpData.
	   flip the rows, our data start from upper-left corner,
	   but the bmp file data start from lower-left corner */
	pBmpData = (unsigned char*)malloc(BmpInfo.nImageSize);
	for (i = 0; i < BmpInfo.nHeight; i++)
	{
		for (j = 0; j < BmpInfo.nWidth; j++)
		{
			tempd = pData[(BmpInfo.nHeight - 1 - i)*BmpInfo.nWidth + j];
			if (nMode == 2) temp = (unsigned char)tempd;
			else
			{
				if (tempd < dMin) temp = 0;
				else if (tempd > dMax) temp = 255;
				else temp = (unsigned char)(255 * (tempd - dMin) / (dMax - dMin));
			}
			pBmpData[i*BmpInfo.nWidth + j] = temp;
		}
	}
	/* save pixel data */
	fwrite(pBmpData, 1, BmpInfo.nImageSize, fp);

	/* free data, close file and return */
	free(pBmpData);
	fclose(fp);

	return 0;
}

/* JGPL_Img_BmpLoad
     Load the bmp file saved by JGPL_Img_BmpSave
	 return value: -1 - cannot open file */
int JGPL_Img_BmpLoad(const char* pccFileName, double **pData, int *pWidth, int *pHeight)
{
	int i, j;
	FILE *fp;
	JGPL_tBmpFileHeader BmpFileHeader;
	JGPL_tBmpInfo BmpInfo;
	unsigned char *pBmpData;

	if ((fp = fopen(pccFileName, "rb")) == NULL) return -1; /* cannot open file */
	/* load bmp file header */
	fread(&BmpFileHeader.nMagicNumber, 2, 1, fp);
	fread(&BmpFileHeader.nSize, 4, 1, fp);
	fread(&BmpFileHeader.nReserved1, 2, 1, fp);
	fread(&BmpFileHeader.nReserved2, 2, 1, fp);
	fread(&BmpFileHeader.nOffset, 4, 1, fp);
	/* load bitmap information */
	fread(&BmpInfo.nHeaderSize, 4, 1, fp);
	fread(&BmpInfo.nWidth, 4, 1, fp);
	*pWidth = BmpInfo.nWidth;
	fread(&BmpInfo.nHeight, 4, 1, fp);
	*pHeight = BmpInfo.nHeight;
	fread(&BmpInfo.nPlanes, 2, 1, fp);
	fread(&BmpInfo.nBitCount, 2, 1, fp);
	fread(&BmpInfo.nCompression, 4, 1, fp);
	fread(&BmpInfo.nImageSize, 4, 1, fp);
	fread(&BmpInfo.nXPixelPerMeter, 4, 1, fp);
	fread(&BmpInfo.nYPixelPerMeter, 4, 1, fp);
	fread(&BmpInfo.nUsedColor, 4, 1, fp);
	fread(&BmpInfo.nImportantColor, 4, 1, fp);
	/* skip color table */
	fseek(fp, 4*256, SEEK_CUR);
	/* load pixel data */
	pBmpData = (unsigned char*)malloc(BmpInfo.nImageSize);
	fread(pBmpData, 1, BmpInfo.nImageSize, fp);
	/* convert into double as output */
	*pData = (double*)malloc(sizeof(double)*BmpInfo.nImageSize);
	for (i = 0; i < BmpInfo.nHeight; i++)
		for (j = 0; j < BmpInfo.nWidth; j++)
			(*pData)[i*BmpInfo.nWidth + j] = pBmpData[(BmpInfo.nHeight - 1 - i)*BmpInfo.nWidth + j];
	
	free(pBmpData);
}

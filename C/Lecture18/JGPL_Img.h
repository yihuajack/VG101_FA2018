/* Author: Jigang Wu
   Functions: JGPL_Img_BmpSave - save a 2D data set as bmp file
***********************/
#ifndef __JGPL_IMG_H__
#define __JGPL_IMG_H__

/* JGPL_Img_BmpSave
     Save gray scale (8-bit) bmp file with file name pccFileName, 2D data pData with dimensions nWidth x nHeight
     pData (double type) is row by row, start from the upper left corner (Note that bmp data start from the lower left corner by default)
     nMode = 0: scale the data to [0 255], then save, in this case, dMin and dMax is not used
     nMode = 1: scale the data according to the range [dMin dMax]
     nMode = 2: don't scale the data, save as it is
     return value: -1 - cannot open file */
int JGPL_Img_BmpSave(const char* pccFileName, double *pData, int nWidth, int nHeight,
	int nMode, double dMin, double dMax);

/* JGPL_Img_BmpLoad
     Load the bmp file saved by JGPL_Img_BmpSave
	 return value: -1 - cannot open file */
int JGPL_Img_BmpLoad(const char* pccFileName, double **pData, int *pWidth, int *pHeight);

#endif

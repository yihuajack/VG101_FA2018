/* Author: Jigang Wu (jigang.wu@gmail.com)
   - Adapted for vg101
*************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "JGPL_Plot.h"
#include "JGPL_MatrixFont.h"
#include "JGPL_Img.h"

/* internal function: draw a line */
void JGPL_Plot_internal_line(int x1, int y1, int x2, int y2, double* pData, int nWidth, int nStyle)
{/* plot a line from (x1, y1) to (x2, y2) in image describe by pData with width of nWidth
    pData start from upper-left corner
    the coordinates won't exceed the image boundary
    nStyle = 0: solid line, = 1: dashed line */

	int temp, x, y;

	if (abs(x2 - x1) > abs(y2 - y1)) /* draw along x axis */
	{
		/* make sure x1 <= x2, otherwise swap the two end points */
		if (x1 > x2)
		{
			temp = x1; x1 = x2; x2 = temp;
			temp = y1; y1 = y2; y2 = temp;
		}
		/* set points along the line */
		for (x = x1; x < x2; x++)
		{
			y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			if (nStyle == 0) pData[y*nWidth + x] = 0;
			else if (nStyle == 1)
			{
				if (x % 8  < 4) pData[y*nWidth + x] = 0;
			}
			else pData[y*nWidth + x] = 0; /* everything else is solid line */
		}
		pData[y2*nWidth + x2] = 0; /* the last point, to avoid divided by zero in the above equation */
	}
	else /* draw along y axis */
	{
		/* make sure y1 <= y2, otherwise swap the two end points */
		if (y1 > y2)
		{
			temp = x1; x1 = x2; x2 = temp;
			temp = y1; y1 = y2; y2 = temp;
		}
		// set points along the line
		for (y = y1; y < y2; y++)
		{
			x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			if (nStyle == 0) pData[y*nWidth + x] = 0;
			else if (nStyle == 1)
			{
				if (y % 8  < 4) pData[y*nWidth + x] = 0;
			}
			else pData[y*nWidth + x] = 0; /* everything else is solid line */
		}
		pData[y2*nWidth + x2] = 0; /* the last point, to avoid divided by zero in the above equation */
	}
}

/* internal function: draw text */
void JGPL_Plot_internal_text(int x, int y, const char *str, double* pData, int nWidth)
{/* draw text from upper left coordinate (x, y) in image describe by pData, nWidth
    assume that the text won't exceed the image boundary
    str is ended with \0 */
	int i, j, k, pos;
	for (i = 0; str[i]; i++)
	{
		pos = (str[i] - TPL_chStart) * TPL_nFontWidth * TPL_nFontHeight; // position of the font in Font matrix
		for (j = 0; j < TPL_nFontHeight; j++)
		{
			for (k = 0; k < TPL_nFontWidth; k++)
				pData[(y + j)*nWidth + (x + k)] = 255 * TPL_MatrixFont[pos + j * TPL_nFontWidth + k];
		}
		x += TPL_nFontWidth;
	}
}

/**************************************************/
/* the following is adapted from Heckbert's algorithm to find ticks
   http://tog.acm.org/resources/GraphicsGems/gems/Label.c
***************************************************/
/*
* nicenum: find a "nice" number approximately equal to x.
* Round the number if round=1, take ceiling if round=0
*/

double JGPL_Plot_internal_nicenum(double x, int round)
{
	int expv;				/* exponent of x */
	double f;				/* fractional part of x */
	double nf;				/* nice, rounded fraction */

	expv = floor(log10(x));
	f = x / pow(10., expv);		/* between 1 and 10 */
	if (round)
	{
		if (f < 1.5) nf = 1.;
		else if (f < 3.) nf = 2.;
		else if (f < 7.) nf = 5.;
		else nf = 10.;
	}
	else
	{
		if (f <= 1.) nf = 1.;
		else if (f <= 2.) nf = 2.;
		else if (f <= 5.) nf = 5.;
		else nf = 10.;
	}
	return nf*pow(10., expv);
}

void JGPL_Plot_internal_loose_label(double min, double max, int nTicks, double* graphmin, double* graphmax, double* increment)
{
	double range;

	/* we expect min!=max */
	range = JGPL_Plot_internal_nicenum(max - min, 0);
	*increment = JGPL_Plot_internal_nicenum(range / (nTicks - 1), 1);
	*graphmin = floor(min / *increment)*(*increment);
	while (*graphmin < min - *increment * 0.01) *graphmin += *increment; // JG - add to avoid tick smaller than min
	*graphmax = ceil(max / *increment)*(*increment);
	while (*graphmax > max + *increment * 0.2) *graphmax -= *increment; // JG - add to avoid tick much larger than max
}

/***************************************************/
/* plot y against x, where both contain N elements
   output to bmp file with specified file name, width and height
   if pccFileName == NULL, save to temp.bmp
   nStyle = 0: solid line, = 1: dashed line
   nAxes = 0: no axes, = 1: show axes
   nGrid = 1: with grid, = 0: no grid */
void JGPL_Plot_2d(int N, const double* x, const double* y,
	int nWidth, int nHeight, int nStyle, int nAxes,
	int nGrid, const char* pccFileName)
{
	int i, nSize = nWidth * nHeight, tx, ty;
	double* pData = (double*)malloc(sizeof(double)*nSize);
	int nSpace1 = 60; /* space between the axis and the border */
	int nSpace2 = 30; /* space between the maximum value and the axis end */
	double xmin, xmax, ymin, ymax;
	int nTicks = 8; // number of ticks include origin
	char tickstr[16]; // tick string
	double graphmin, graphmax, increment, tick;

	/* set background to white */
	for (i = 0; i < nSize; i++) pData[i] = 255;
	/* get min and max */
	xmin = xmax = x[0];
	ymin = ymax = y[0];
	for (i = 1; i < N; i++)
	{
		if (x[i] < xmin) xmin = x[i];
		if (x[i] > xmax) xmax = x[i];
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	if (nAxes)
	{
		/* plot x axis */
		JGPL_Plot_internal_line(nSpace1, nHeight - nSpace1, nWidth - nSpace1, nHeight - nSpace1, pData, nWidth, nStyle);
		JGPL_Plot_internal_line(nWidth - nSpace1, nHeight - nSpace1, nWidth - nSpace1 - 6, nHeight - nSpace1 - 3, pData, nWidth, nStyle);
		JGPL_Plot_internal_line(nWidth - nSpace1, nHeight - nSpace1, nWidth - nSpace1 - 6, nHeight - nSpace1 + 3, pData, nWidth, nStyle);
		if (nGrid) JGPL_Plot_internal_line(nSpace1, nSpace1 + nSpace2, nWidth - nSpace1 - nSpace2, nSpace1 + nSpace2, pData, nWidth, 1);
		/* plot y axis */
		JGPL_Plot_internal_line(nSpace1, nHeight - nSpace1, nSpace1, nSpace1, pData, nWidth, nStyle);
		JGPL_Plot_internal_line(nSpace1, nSpace1, nSpace1 - 3, nSpace1 + 6, pData, nWidth, nStyle);
		JGPL_Plot_internal_line(nSpace1, nSpace1, nSpace1 + 3, nSpace1 + 6, pData, nWidth, nStyle);
		if (nGrid) JGPL_Plot_internal_line(nWidth - nSpace1 - nSpace2, nHeight - nSpace1, nWidth - nSpace1 - nSpace2, nSpace1 + nSpace2, pData, nWidth, 1);
		/* plot x ticks */
		JGPL_Plot_internal_loose_label(xmin, xmax, nTicks, &graphmin, &graphmax, &increment);
		for (tick = graphmin; tick < graphmax + 0.5*increment; tick += increment)
		{
			tx = nSpace1 + (nWidth - 2 * nSpace1 - nSpace2) * (tick - xmin) / (xmax - xmin);
			if (nGrid) JGPL_Plot_internal_line(tx, nHeight - nSpace1, tx, nSpace1 + nSpace2, pData, nWidth, 1);
			else JGPL_Plot_internal_line(tx, nHeight - nSpace1, tx, nHeight - nSpace1 - 3, pData, nWidth, nStyle);
			sprintf(tickstr, "%G", tick);
			if (abs(tick) < 1e-6) strcpy(tickstr, "0"); /* avoid very small tick display */
			JGPL_Plot_internal_text(tx - TPL_nFontWidth * strlen(tickstr) / 2, nHeight - nSpace1 + 3, tickstr, pData, nWidth);
		}
		/* plot y ticks */
		JGPL_Plot_internal_loose_label(ymin, ymax, nTicks, &graphmin, &graphmax, &increment);
		for (tick = graphmin; tick < graphmax + 0.5*increment; tick += increment)
		{
			ty = nHeight - nSpace1 - (nHeight - 2 * nSpace1 - nSpace2) * (tick - ymin) / (ymax - ymin);
			if (nGrid) JGPL_Plot_internal_line(nSpace1, ty, nWidth - nSpace1 - nSpace2, ty, pData, nWidth, 1);
			else JGPL_Plot_internal_line(nSpace1, ty, nSpace1 + 3, ty, pData, nWidth, nStyle);
			sprintf(tickstr, "%G", tick);
			if (abs(tick) < 1e-6) strcpy(tickstr, "0"); /* avoid very small tick display */
			JGPL_Plot_internal_text(nSpace1 - 3 - TPL_nFontWidth * strlen(tickstr), ty - 5, tickstr, pData, nWidth);
		}
	}
	/* plot data */
	for (i = 0; i < N - 1; i++)
	{
		int tx1, ty1, tx2, ty2;
		tx1 = nSpace1 + (nWidth - 2 * nSpace1 - nSpace2) * (x[i] - xmin) / (xmax - xmin);
		ty1 = nHeight - nSpace1 - (nHeight - 2 * nSpace1 - nSpace2) * (y[i] - ymin) / (ymax - ymin);
		tx2 = nSpace1 + (nWidth - 2 * nSpace1 - nSpace2) * (x[i + 1] - xmin) / (xmax - xmin);
		ty2 = nHeight - nSpace1 - (nHeight - 2 * nSpace1 - nSpace2) * (y[i + 1] - ymin) / (ymax - ymin);
		JGPL_Plot_internal_line(tx1, ty1, tx2, ty2, pData, nWidth, nStyle);
	}
	/* save to bmp file */
	if (pccFileName != NULL) JGPL_Img_BmpSave(pccFileName, pData, nWidth, nHeight, 0, 0, 0);
	else JGPL_Img_BmpSave("temp.bmp", pData, nWidth, nHeight, 0, 0, 0);

	free(pData);
}
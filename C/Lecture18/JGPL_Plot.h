/* Author: Jigang Wu (jigang.wu@gmail.com)
   Functions: TPL_Plot_2d - 2D plot with datasets x and y, output to bmp file
*************************/
#ifndef __JGPL_PLOT_H__
#define __JGPL_PLOT_H__

/* plot y against x, where both contain N elements
   output to bmp file with specified file name, width and height
   if pccFileName == NULL, save to temp.bmp
   nStyle = 0: solid line, = 1: dashed line
   nAxes = 0: no axes, = 1: show axes
   nGrid = 1: with grid, = 0: no grid */
void JGPL_Plot_2d(int N, const double* x, const double* y,
	int nWidth, int nHeight, int nStyle, int nAxes,
	int nGrid, const char* pccFileName);

#endif
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    unsigned char *pData;
    int i, j, tempint;
    char tempch;
    short tempshort;
    /* 1: prepare the data */
    pData = (unsigned char*)malloc(640*256);
    for (i=0; i<256; i++)
        for (j=0; j<640; j++)
            pData[i*640+j] = i;
    /* 2: write the bmp file */
    if( (fp = fopen("test.bmp", "wb")) == NULL) return;
    /* 2.1 Bitmap header */
    tempch = 'B'; fwrite(&tempch, 1, 1, fp);
    tempch = 'M'; fwrite(&tempch, 1, 1, fp);
    tempint = 14 + 40 + 4*256 + 640*256;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 0;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 14 + 40 + 4*256;
    fwrite(&tempint, sizeof(int), 1, fp);
    /* 2.2 DIB header */
    tempint = 40;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 640;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 256;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempshort = 1;
    fwrite(&tempshort, sizeof(short), 1, fp);
    tempshort = 8;
    fwrite(&tempshort, sizeof(short), 1, fp);
    tempint = 0;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 640 * 256;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 0;
    fwrite(&tempint, sizeof(int), 1, fp);
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 256;
    fwrite(&tempint, sizeof(int), 1, fp);
    tempint = 0;
    fwrite(&tempint, sizeof(int), 1, fp);
    /* 2.3 Color table */
    for (i=0; i<256; i++)
    {
        for (j=0; j<3; j++) fwrite(&i, 1, 1, fp);
        j = 0; fwrite(&j, 1, 1, fp);
    }
    /* 2.4 Pixel array */
    fwrite(pData, 1, 640*256, fp);

    fclose(fp);

    free(pData);
    return 0;
}

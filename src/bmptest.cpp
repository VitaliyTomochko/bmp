#include<iostream>
#include <string>
#include <fstream>
#include "structbmp.h"
#include <cmath>
using namespace std;

void main() {
	BITMAPFILEHEADER _FileHeader;
	BITMAPINFOHEADER _Info_Header;
	RGBTRIPLE rgb_l;

	FILE * file1, *file2;

	file1 = fopen("file1.bmp", "rb");
	file2 = fopen("4.bmp", "wb");

	fread(&_FileHeader, sizeof(_FileHeader), 1, file1);
	fwrite(&_FileHeader, sizeof(_FileHeader), 1, file2);   
	fread(&_Info_Header, sizeof(_Info_Header), 1, file1); 
	fwrite(&_Info_Header, sizeof(_Info_Header), 1, file2);   

	system("pause");
}

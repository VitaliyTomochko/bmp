#include<iostream>
#include <string>
#include <fstream>
#include "structbmp.h"
#include <cmath>
using namespace std;

int main() {
	BITMAPFILEHEADER _FileHeader;// _FileHeader
	BITMAPINFOHEADER _Info_Header;//	_Info_Header
	RGBTRIPLE rgb_l;

	RGBTRIPLE **RgbTriple;

	FILE * file1, *file2;

	file1 = fopen("file1.bmp", "rb");
	file2 = fopen("4.bmp", "wb");

	fread(&_FileHeader, sizeof(_FileHeader), 1, file1); //Запихиваем файловый заголовок в структуру BITMAPFILEHEADER
	fwrite(&_FileHeader, sizeof(_FileHeader), 1, file2);   //
	fread(&_Info_Header, sizeof(_Info_Header), 1, file1); //Запихиваем заголовок изображения в структуру BITMAPINFOHEADER
	fwrite(&_Info_Header, sizeof(_Info_Header), 1, file2);   //

	size_t padding = 0;   //смещение байт
	if ((_Info_Header.biWidth * 3) % 4) {
		padding = 4 - (_Info_Header.biWidth * 3) % 4;
	}
///////////////////////выделили память
	RgbTriple = new RGBTRIPLE*[_Info_Header.biHeight];
	for (int i = 0; i < _Info_Header.biHeight; i++) {
		RgbTriple[i] = new RGBTRIPLE[_Info_Header.biWidth];
	}
////////////////////////считали массив пикселей
	for (int i = 0; i < _Info_Header.biHeight; i++) {
		fread(RgbTriple[i], sizeof(RgbTriple), _Info_Header.biWidth, file1);
		if (padding != 0) {
			fread(&rgb_l, padding, 1, file1);
		}
	}

	for (int i = 0; i < _Info_Header.biHeight; i++) {
		fwrite(RgbTriple[i], sizeof(RgbTriple), _Info_Header.biWidth, file2);
		if (padding != 0) {
			fwrite(&rgb_l, padding, 1, file2);
		}
	}

	return 0;
}

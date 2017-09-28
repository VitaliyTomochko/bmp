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
	FILE *file1 = fopen("file_out", "rb");
	FILE *file2 = fopen("file_in", "wb");
	int p = 0;
	while (p)
	{
		cout << "1-Encode" << endl;
		cout << "2-Decode" << endl;
		cin >> p;
		if (p == 1)
		{
			string text;
			cin.get();
			getline(cin, text);
			fread(&_FileHeader, sizeof(_FileHeader), 1, file1);
			fwrite(&_FileHeader, sizeof(_FileHeader), 1, file2);
			fread(&_Info_Header, sizeof(_Info_Header), 1, file1);
			fwrite(&_Info_Header, sizeof(_Info_Header), 1, file2);
			int text_len = text.size(), len1 = text_len, j = 8;
			double num = (int)(text[text_len - len1]);
			for (int i = 0; i< _Info_Header.biWidth; i++)
			{
				for (int j = 0; j <_Info_Header.biHeight; j++)
				{
					fread(&rgb_l, sizeof(rgb_l), 1, file1);
					if (len1)
					{
						if (j >= 0)
						{
							if (num >= pow(2, j))
							{
								num -= pow(2, j);
								rgb_l.rgbtRed = rgb_l.rgbtRed + rgb_l.rgbtRed % 2 - 1;
							}
							else
							{
								rgb_l.rgbtRed = rgb_l.rgbtRed + rgb_l.rgbtRed % 2;
							}
							j--;
						}
					}
					if (j<0)
					{
						j = 8; len1--;
						num = (int)(text[text_len - len1]);
					}
					fwrite(&rgb_l, sizeof(rgb_l), 1, file2);
				}
			}
			cout << "Done";
			fcloseall();
		}
		if (p == 2)
		{
		
		}
		
		

	}
}

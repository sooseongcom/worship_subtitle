#include "kr2utf8.h"

string kr2utf8(string euckr) {
	char* euckr_c = 0, * utf8_c = 0;
	wchar_t* uni_c = 0;
	string result;

	euckr_c = new char[euckr.length() + 1];
	uni_c = new wchar_t[euckr.length() + 1];
	strcpy(euckr_c, euckr.c_str());
	MultiByteToWideChar(CP_ACP, 0, euckr_c, strlen(euckr_c) + 1, uni_c, euckr.length() * 2 + 2);

	utf8_c = new char[euckr.length() * 4 + 4];
	WideCharToMultiByte(CP_UTF8, 0, uni_c, wcslen(uni_c) + 1, utf8_c, euckr.length() * 4 + 4, NULL, NULL);
	result = utf8_c;

	delete[] euckr_c;
	delete[] utf8_c;
	delete[] uni_c;
	return result;
}
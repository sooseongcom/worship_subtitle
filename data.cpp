#include "data.h"

metadata::metadata(string inppath) {
	filepath = inppath;
}

metadata::~metadata(){
	if(fin.is_open()) fin.close();
	if(fout.is_open()) fout.close();
}

string metadata::getDate() {
	int order;
	string src;

	fin.open(filepath);
	if (!fin.is_open()) {
		return "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	//date
	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<div id=\"date\">");
		if (order > 0) {
			getline(fin, src);
			date = src.substr(order + 4);
			break;
		}
	}
	if (date.empty()) {
		return "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	fin.close();
	return date;
}

string metadata::getSermonTitle() {
	int order;
	string src;

	fin.open(filepath);
	if (!fin.is_open()) {
		return "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	//sermon-title
	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<span id=\"sermon-title\">");
		if (order > 0) {
			getline(fin, src);
			sermonTitle = src.substr(order + 4);
			break;
		}
	}
	if (sermonTitle.empty()) {
		return "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	fin.close();
	return sermonTitle;
}

string metadata::getBible() {
	int order;
	string src;

	fin.open(filepath);
	if (!fin.is_open()) {
		return "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	//bible
	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<span id=\"bible\">");
		if (order > 0) {
			getline(fin, src);
			bible = src.substr(order + 4);
			break;
		}
	}
	if (bible.empty()) {
		return "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다.";
	}

	fin.close();
	return bible;
}

int metadata::setDate(string inp) {
	int order = 0, pos = 0;	//order is variable for string src, while pos is variable for fstream
	int lengthtemp = date.length();
	string src;
	
	fin.open(filepath);
	if (!fin.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<div id=\"date\">");
		if (order > 0) {
			getline(fin, src);
			pos = (int)fin.tellg() - lengthtemp - 2;	//-2가 있는 이유: 줄바꿈과 '\0'을 빼야 함.
			break;
		}
	}
	if (date.empty()) {
		cout << "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	fin.close();

	fout.open(filepath, ios::out | ios::in);
	if (!fout.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	date = inp;

	fout.seekp(pos);
	fout << date;

	for (int i = 0; i < lengthtemp - date.length(); i++) {
		fout << ' ';
	}

	fout.close();

	return 0;
}

int metadata::setSermonTitle(string inp) {
	int order = 0, pos = 0;	//order is variable for string src, while pos is variable for fstream
	int lengthtemp = sermonTitle.length();
	string src;

	fin.open(filepath);
	if (!fin.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<span id=\"sermon-title\">");
		if (order > 0) {
			getline(fin, src);
			pos = (int)fin.tellg() - lengthtemp - 2;
			break;
		}
	}
	if (sermonTitle.empty()) {
		cout << "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	fin.close();

	fout.open(filepath, ios::out | ios::in);
	if (!fout.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	sermonTitle = inp;

	fout.seekp(pos);
	fout << sermonTitle;

	for (int i = 0; i < lengthtemp - sermonTitle.length(); i++) {
		fout << ' ';
	}

	fout.close();

	return 0;
}

int metadata::setBible(string inp) {
	int order = 0, pos = 0;	//order is variable for string src, while pos is variable for fstream
	int lengthtemp = bible.length();
	string src;

	fin.open(filepath);
	if (!fin.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	while (!fin.eof()) {
		getline(fin, src);
		order = src.find("<span id=\"bible\">");
		if (order > 0) {
			getline(fin, src);
			pos = (int)fin.tellg() - lengthtemp - 2;
			break;
		}
	}
	if (bible.empty()) {
		cout << "파일이 손상되어 작업을 진행할 수 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	fin.close();

	fout.open(filepath, ios::out | ios::in);
	if (!fout.is_open()) {
		cout << "File Not Found - 파일이 없습니다. 프로그램을 다시 설치하시기 바랍니다." << endl;
		return -1;
	}

	bible = inp;

	fout.seekp(pos);
	fout << bible;

	for (int i = 0; i < lengthtemp - bible.length(); i++) {
		fout << ' ';
	}

	fout.close();

	return 0;
}
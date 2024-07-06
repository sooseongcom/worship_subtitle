#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class metadata {
private:
	string filepath, date, sermonTitle, bible;
	ifstream fin;
	ofstream fout;

public:
	metadata(string inppath);
	virtual ~metadata();
	string getDate();
	string getSermonTitle();
	string getBible();
	int setDate(string inp);
	int setSermonTitle(string inp);
	int setBible(string inp);
};
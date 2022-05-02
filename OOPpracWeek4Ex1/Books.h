#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class TEXTBOOK {
public:
	string Grade;
	string Part;
	string Published;
	string Publisher;
	string Republish;
	void readFileTextbook(ifstream& filein, TEXTBOOK& textbook);
};
class NOVEL {
public:
	string Part;
	string Published;
	string Publisher;
	string Republish;
	string Translator;
	string Author;
	void readFileNovel(ifstream& filein, NOVEL& novel);
};
class MAGAZINE {
public:
	string Published;
	string Publisher;
	string Author;
	void readFileMagazine(ifstream& filein, MAGAZINE& magazine);
};
class BOOK:public TEXTBOOK, public NOVEL, public MAGAZINE {
public:
	string size;
	string numPage;
	string bookKind;
	string nameOfBook;
	void readFilePart1(ifstream& filein, BOOK& book);
};
class Output:public BOOK {
public:
	void readFile(ifstream& filein, vector< BOOK >& list_books);
	void checkNum(vector<BOOK> list);
	void outputOnDemand(BOOK book);
	void findBook(vector<BOOK> list, string name);

};
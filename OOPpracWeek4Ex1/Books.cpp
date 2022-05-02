#include "Books.h"
void BOOK::readFilePart1(ifstream & filein, BOOK & book) {
	getline(filein, book.size, ',');
	getline(filein, book.numPage, ',');
	getline(filein, book.bookKind,',');
	getline(filein, book.nameOfBook, '.');
}
void TEXTBOOK::readFileTextbook(ifstream& filein, TEXTBOOK& textbook) {
	getline(filein, textbook.Grade, ',');
	getline(filein, textbook.Part, ',');
	getline(filein, textbook.Published, ',');
	getline(filein, textbook.Publisher, ',');
	getline(filein, textbook.Republish, '.');
}
void NOVEL::readFileNovel(ifstream & filein, NOVEL & novel) {
	getline(filein, novel.Part, ',');
	getline(filein, novel.Published, ',');
	getline(filein, novel.Publisher, ',');
	getline(filein, novel.Republish, ',');
	getline(filein, novel.Translator, ',');
	getline(filein, novel.Author, '.');
}
void MAGAZINE::readFileMagazine(ifstream& filein, MAGAZINE& magazine) {
	getline(filein, magazine.Published, ',');
	getline(filein, magazine.Publisher, ',');
	getline(filein, magazine.Author, '.');
}
void Output::readFile(ifstream& filein, vector< BOOK >& list_books) {
	while (filein.eof() == false) {
		BOOK book;
		readFilePart1(filein, book);
		string temp;
		getline(filein, temp);
		if (book.bookKind == "Kind of book: Textbook") {
			
			book.TEXTBOOK::readFileTextbook(filein,book);
			getline(filein, temp);
		}
		else if (book.bookKind == "Kind of book: Novel") {
			
			book.NOVEL::readFileNovel(filein, book);
			getline(filein, temp);
		}
		else if (book.bookKind == "Kind of book: Magazine") {
			
			book.MAGAZINE::readFileMagazine(filein, book);
			getline(filein, temp);
		}
		list_books.push_back(book);
	}
}
void Output::outputOnDemand(BOOK book) {
	cout <<"Name: " << book.nameOfBook << ", " << book.size << ", " << book.numPage << ", " << book.bookKind << '\n';
	if (book.bookKind == "Kind of book: Textbook") {
		cout << book.TEXTBOOK::Grade << ", ";
		cout << book.TEXTBOOK::Part << ", ";
		cout << book.TEXTBOOK::Published << ", ";
		cout << book.TEXTBOOK::Publisher << ", ";
		cout << book.TEXTBOOK::Republish << '\n';
	}
	else if (book.bookKind == "Kind of book: Novel") {
		cout << book.NOVEL::Part << ", ";
		cout << book.NOVEL::Published << ", ";
		cout << book.NOVEL::Publisher << ", ";
		cout << book.NOVEL::Republish << ", ";
		cout << book.NOVEL::Translator << ", ";
		cout << book.NOVEL::Author << '\n';
	}
	else if (book.bookKind == "Kind of book: Magazine") {
		cout << book.MAGAZINE::Published << ", ";
		cout << book.MAGAZINE::Publisher << ", ";
		cout << book.MAGAZINE::Author << '\n';
	}
}
void Output::checkNum(vector<BOOK> list) {
	int tb = 0, nvl = 0, mg = 0,x=0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].bookKind == "Kind of book: Textbook")
			tb++;
		if (list[i].bookKind == "Kind of book: Novel")
			nvl++;
		if (list[i].bookKind == "Kind of book: Magazine")
			mg++;
	}
	x = tb + nvl + mg;
	cout << "\n\nNumber of Textbooks: " << tb;
	for (int i = 0; i < x; i++) {
		if (list[i].bookKind == "Kind of book: Textbook") {
			cout<<"\nName: " << list[i].nameOfBook << ", " << list[i].size << ", " << list[i].numPage << ", " << list[i].bookKind <<", ";
			cout << list[i].TEXTBOOK::Grade << ", ";
			cout << list[i].TEXTBOOK::Part << ", ";
			cout << list[i].TEXTBOOK::Published << ", ";
			cout << list[i].TEXTBOOK::Publisher << ", ";
			cout << list[i].TEXTBOOK::Republish << '\n';
		}
	}
	cout << "\n\n\nNumber of Novels: " << nvl;
	for (int i = 0; i < x; i++) {
		if (list[i].bookKind == "Kind of book: Novel") {
			cout << "\nName: " << list[i].nameOfBook << ", " << list[i].size << ", " << list[i].numPage << ", " << list[i].bookKind << ", ";
			cout << list[i].NOVEL::Part << ", ";
			cout << list[i].NOVEL::Published << ", ";
			cout << list[i].NOVEL::Publisher << ", ";
			cout << list[i].NOVEL::Republish << ", ";
			cout << list[i].NOVEL::Translator << ", ";
			cout << list[i].NOVEL::Author << '\n';
		}
	}
	cout << "\n\n\nNumber of Magazines: " << mg;
	for (int i = 0; i < x; i++) {
		
		if (list[i].bookKind == "Kind of book: Magazine") {
			cout << "\nName: " << list[i].nameOfBook << ", " << list[i].size << ", " << list[i].numPage << ", " << list[i].bookKind << ", ";
			cout << list[i].MAGAZINE::Published << ", ";
			cout << list[i].MAGAZINE::Publisher << ", ";
			cout << list[i].MAGAZINE::Author << '\n';
		}
	}
}
void Output::findBook(vector<BOOK> list, string name) {
	for (int i = 0; i <list.size(); i++)
		if (!_stricmp(list[i].nameOfBook.c_str(), name.c_str())) {
			outputOnDemand(list[i]);
		}

}
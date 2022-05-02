#include "Books.cpp"

int main()
{
	ifstream filein;
	filein.open("LIST.txt", ios_base::in);
	vector <BOOK> list_books;
	Output op;
	op.readFile(filein , list_books);
	cout << "Read file completely";
	op.checkNum(list_books);
	string name;
	cout << "\nInsert name of book: ";
	getline(cin, name);
	op.findBook(list_books, name);
	filein.close();
	return 0;

}


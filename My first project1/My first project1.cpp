// My first project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class Book
{
private:
	int Id;
	string Title;
	string Author;
public:
	void Setid(int i) {
		Id = i;
	}
	void Settitle(string t) {
		Title = t;
	}
	void Setauthor(string a) {
		Author = a;
	}
	int Getid() {
		return Id;
	}
	string Gettitle() {
		return Title;
	}
	string Getauthor() {
		return Author;
	}
	void Displayinfo() {
		cout << "Id=" << Id << endl;
		cout << "Title=" << Title << endl;
		cout << "Author=" << Author << endl;
	}
};
int main() {
	Book books[100];
	int count = 0;
	int choice;
	do {
		cout << "\n  welcom to library  \n";
		cout << "1.Add Book\n";
		cout << "2.Display All Books\n";
		cout << "3.Search About Book By Id\n";
		cout << "0.Exist\n";
		cout << "enter Your choice:";
		cin >> choice;
		if (choice == 1) {
			if (count < 100) {
				int id;
				string title, author;
				cout << "Enter Id:";
				cin >> id;
				cin.ignore();
				cout << "Enter Title:";
				getline(cin, title);
				cout << "Enter Author";
				getline(cin, author);

				books[count].Setid(id);
				books[count].Settitle(title);
				books[count].Setauthor(author);
				count++;
				cout << "Book added successfullu!\n";
			}
			else {
				cout << "library is full\n";
			}
		}
		else if (choice == 2) {
			if (count == 0) {
				cout << "No books in the library";
			}
			else {
				for (int i = 0;i < count;i++) {
					cout << "\n  Book:" << i + 1 << " \n";
					books[i].Displayinfo();
				}
			}
		}
		else if (choice == 3) {
			int bookid;
			int f = 0;
			cout << "Enter book Id to search:";
			cin >> bookid;

			for (int i = 0;i < count;i++) {
				if (books[i].Getid() == bookid) {
					cout << "\n Book Found \n";
					books[i].Displayinfo();
					f++;
				}
			}
			if (f == 0) {
				cout << "Book not found!\n";
			}
		}

	} while (choice != 0);
	return 0;
}

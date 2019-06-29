#include "BookShop.h"
#include <iostream>
#include <sstream>
using namespace std;

BookShop::BookShop()
{
}

BookShop::BookShop(string name)
{
	m_name = name;
	//The default vector constructor will create an empty vector
}

BookShop::~BookShop()
{
}

Book* BookShop::SearchBook(string book_name)
{
	/*
	Return the address of the thing pointed to by the iterator:	
	https://stackoverflow.com/questions/641864/returning-a-pointer-to-a-vector-element-in-c

	*/
	if (books.size() == 0)
		return NULL;
	vector <Book>::iterator it = books.begin();
	Book* found = NULL;
	for (auto book : books) {
		if ((book.m_title).compare(book_name) == 0)
		{
			/*found = &book;
			break;*/
			found = &(*it);

			return found;
			//return &(*book);
		}
		it++;
	}
	return found;
}

void BookShop::BuyBook()
{
	 cout << "Enter name of book you want to buy:  ";
	 string b;
	 //cin >> b;
	 std::getline(cin, b);
	 Book* toBuy = SearchBook(b);
	 if (toBuy == NULL) {
		 cout << "\n We are sorry, Book is not in stock" << endl;
	 }
	 else
	 {
		 cout << "the current amount is: " << toBuy->m_amount << ", \n How many you would like to buy? : ";
		 unsigned int num;
		 cin >> num;
		 /*
		Simply check if the input is a number first and then keep proccesing.
		*/
		 while (std::cin.fail())
		 {
			 std::cin.clear();
			 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			 std::cout << "Bad entry.  Enter a NUMBER: ";
			 std::cin >> num;
		 }
		 if (num > toBuy->m_amount) {
			 cout << "Sorry, there is only " << toBuy->m_amount << " copies of this book" << endl;
			 return;
		 }
		 cout << "Thanks for buying "<< num <<" copies of the book: " << toBuy->m_title << endl;
		 toBuy->DecAmount(num);
	 }
}

 void BookShop::AddBook()
 {
	 string b;
	 cout << "Enter name of book you want to Add:  ";
	 
	 //cin >> b;
	 std::getline(cin, b);
	 Book* toBuy = SearchBook(b);
	 if (toBuy != NULL) {
		 cout << "\n this book is already in stock,do you want to add more copies of it ? (y/n): " << endl;
		 char choice;
		 cin >> choice;
		 if (choice == 'y' || choice == 'Y') {
			 cout << "\n How many you would like to add? : ";
			 unsigned int num;
			 cin >> num;
			 toBuy->IncAmount(num);
		 }
	 }
	 else
	 {
		 string author;
		 unsigned int amount;
		 float price;
		 cout << "\nEnter Author:  ";
		 cin >> author;
		 cout << "\nEnter price:  ";
		 cin >> price;
		 cout << "\nEnter amount:  ";
		 cin >> amount;
		 Book book = Book(b, author, price, amount);
		 (this->books).push_back(book);
		 cout << "\nThe book have been added" << endl;
	 }
 }

 void BookShop::DisplayBookDetails()
 {
	 string b;
	 cout << "\nEnter book's name: ";
	 cin >> b;
	 Book* book = SearchBook(b);
	 if (book == NULL) {
		 cout << "Sorry, thi book is not in stock" << endl;		 
	 }
	 else
	 {
		 book->PrintBook();
	 }
 }

void BookShop::PrintBooks()
{
	if ((this->books).size() == 0) {
		cout << "\nthere is no books in shop yet." << endl;
		return;
	}
	for (auto book : books) {
		book.PrintBook();
	}
}

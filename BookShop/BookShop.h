#pragma once
#include "Book.h"
class BookShop
{
public:
	BookShop();
	BookShop(string name);
	~BookShop();
	
	

	string m_name;
	vector <Book> books;
	Book* SearchBook(string book_name);

	void BuyBook();
	void AddBook();
	void DisplayBookDetails();
	void PrintBooks();
	
};




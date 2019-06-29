#include "Book.h"

Book::Book(string title, string author, float price, unsigned int amount)
{
	m_title = title;
	m_amount = amount;
	m_author = author;
	m_price = price;
}

Book::~Book()
{
}

void Book::IncAmount(unsigned int a)
{
	m_amount += a;
}

void Book::DecAmount(unsigned int a)
{
	if (a > m_amount) {
		cout << "Not possible, threr isn't enough books" << endl;
	}
	else
	{
		m_amount -= a;
	}
}

void Book::PrintBook()
{
	cout << "-------------------------------------------------" << endl;
	cout << "Title: " << m_title << endl;
	cout << "Author: " << m_author << endl;
	cout << "Price: " << m_price << endl;
	cout << "Amount: " << m_amount << endl;
	cout << "-------------------------------------------------" << endl;
}

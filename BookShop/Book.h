#pragma once
#include<vector>
#include <iostream>
using namespace std;
class Book
{
public:
	Book(string title,string author,float price,unsigned int amount);
	~Book();
	void IncAmount(unsigned int a);
	void DecAmount(unsigned int a);
	void PrintBook();

//private:
	string m_title;
	string m_author;
	float m_price;
	unsigned int m_amount;
};








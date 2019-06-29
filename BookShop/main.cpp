#include "Book.h"
#include "BookShop.h"
#include <sstream>

void menu(BookShop* shop) {
	int run = 1;
	int selection=1;
	do
	{
		cout << "\n			 Welcome to " << shop->m_name << " shop" << endl;

		printf("\n___________________________________________________________________________________\n");
		printf("|Option Number|                            Description                               |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("|       1       |Print Books                                                         |\n");
		printf("|       2       |Add new Book to shop                                                |\n");
		printf("|       3       |Buy a book                                                          |\n");
		printf("|       4       |Display Book Details                                                |\n");
		printf("|       0       |Exit program                                                        |\n");
		printf("|_______________|____________________________________________________________________|\n");
		printf("\nWhat do you want to do?\n\n");

		cin >> selection;
		/*
		Simply check if the input is a number first and then keep proccesing. 
		*/
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Bad entry.  Enter a NUMBER: ";
			std::cin >> selection;
		}
		getchar();

		switch (selection)
		{
		case 0:
			//free allocated memory end terminate program
			run = 0;
			break;
		case 1:
			shop->PrintBooks();
			break;
		case 2:
			shop->AddBook();
			break;
		case 3:
			shop->BuyBook();
			break;
		case 4:
			shop->DisplayBookDetails();
			break;

		default:
			printf("\nERROR: You did not enter a valid input. Please try again.\n\n");
			break;
		}

	} while (run != 0);
}

int main(void) {
	string shop = "Stimatzki";
	//cout << "Enter name of book you want to buy:  ";
	//string b;
	////cin >> b;
	//std::getline(cin, b);
	//cout << b << endl;
	BookShop myShop = BookShop(shop);
	menu(&myShop);

	return 0;
}
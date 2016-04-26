/// CS 1410 Programming Project #2
// Copyright 2014, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Implementation file for main
// =======================================
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Exception.h"
#include "Book.h"  // the file name for your classes may be different
using namespace std;

void displayBooks(const vector<Book*>& books)
{
	// set up cout to display currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// display heading
	cout << "\nRecommended Reading List\n";

	// you provide the rest of this code
	// display each account
	for (int i = 0; i < books.size(); i++)
	{
		Author* pointer = books[i]->getAuthor();
		cout << books[i]->getTitle() << '\n';
		cout << pointer->getName() << '\n';
		cout << pointer->getAddress() << '\n';
		cout << books[i]->getPages() << " pages\n";

		// use rtti to see what kind of object is being pointed to, and display the 
		// appropriate child class data values
		AudioBook* bp = dynamic_cast<AudioBook*>(books[i]);
		if (bp)
		{
			cout << "The length of this audio book is " << bp->getAudioLength() << " minutes." << endl;
		}
		else
		{
			DigitalBook* bp = dynamic_cast<DigitalBook*>(books[i]);
			if (bp)
			{
				cout << "The format of this digital book is " << bp->getFormat() << endl;
			}
		} // end else

		cout << '$' << books[i]->getPrice() << "\n\n\n";
	}
}

void createTestFile()
{
	// create a vector for storing the account objects
	vector<Book*> myBooks;

	// add the books to the vector
	// create eveything on the heap because we need to work with Book*
	myBooks.push_back(new AudioBook(new Author("J.K.Rowling", "Edinburgh, Scotland"), "Harry Potter and the Sorcerer's Stone", 256, 24.95, 415));
	myBooks.push_back(new DigitalBook(new Author("Suzanne Collins", "Connecticut, USA"), "Mockingjay", 400, 12.99, "PDF"));
	myBooks.push_back(new Book(new Author("J.R.R. Tolkien", "Bournmouth, England"), "The Hobbit", 322, 14.29));

	// write the books to a file
	// the file will be in the same folder as the executable file
	// assume that the file opens
	ofstream outputFile;
	outputFile.open("bookData.txt");

	for (unsigned i = 0; i < myBooks.size(); ++i)
	{
		// Use RTTI to get the type of object being pointed to, cast returns null if cast fails
		// see if it is an audiobook and if it is, output "AUDIOBOOK" to the file to mark the output
		AudioBook* bp = dynamic_cast<AudioBook*>(myBooks[i]);
		if (bp)
		{
			outputFile << "AUDIOBOOK" << endl;
		}
		else
		{
			// see if it is a digital book, if it is output "DIGITALBOOK" to the file
			DigitalBook* bp = dynamic_cast<DigitalBook*>(myBooks[i]);
			if (bp)
			{
				outputFile << "DIGITALBOOK" << endl;
			}
			else // It is not one of the child classes, so it must be a base class (BOOK) object
			{
				outputFile << "BOOK" << endl;
			}
		}
		// now have the book object write itself to the file
		myBooks[i]->writeData(outputFile);
	}
}

void openFile(ifstream& in, const string& _name)
{
	// try to open the file
	in.open(_name);
	
	if (in.is_open()==false)
	{
		throw Exception("file did not open.");
	}
	else
	{ }
}

void readTestFile()
{
	//create vector of pointers to book objects
	vector<Book*> Books;
	//create stream object
	ifstream file;
	//create variable to store object type
	std::string type = "";
	//try to open file
	try
	{
		openFile(file, "bookData.txt");

		//loop
		while (file.is_open())
		{
			//create book object to use to get input
			Book* workbook=nullptr;
			//get object type
			getline(file, type);

			if (file.is_open())
			{
				if (type == "BOOK")
				{
					workbook = new Book();
				}
				else if (type == "AUDIOBOOK")
				{
					workbook = new AudioBook();
				}
				else if (type == "DIGITALBOOK")
				{
					workbook = new DigitalBook();
				}

			}
			try
			{
				workbook->readData(file);
				Books.push_back(workbook);
			}
			catch (Exception Not_Reading)
			{
				cout << endl << Not_Reading.getdescription();
				file.close();

			}
		};
		displayBooks(Books);
	}
	catch (Exception Not_Open)
	{
		cout << endl << Not_Open.getdescription();
	}
	displayBooks(Books);
}


int main()
{
	// Display Menu 
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;

	cout << "\nCS 1410 Project 5";
	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	// run the selected option
	cin >> option;
	if (option == CREATE)
	{
		createTestFile();
		cout << "\nTest file has been created.";
	}
	else if (option == READ)
	{
		readTestFile();
	}
	else
	{
		cout << "\nInvalid option.";
	}

	system("PAUSE");
	return 0;
}
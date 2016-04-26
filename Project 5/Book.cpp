#include "stdafx.h"
#include "Book.h"

//-REGULAR BOOK-
//constructor
Book::Book()
{
	author = new Author();
	title = "";
	pages = 0;
	price = 0;
}
Book::Book(Author* author_, std::string title_, int pages_, double price_)
{
	pages = pages_;
	price = price_;
	author = author_;
	title = title_;
}

//getters
int Book::getPages()
{
	return pages;
}
double Book::getPrice()
{
	return price;
}
Author* Book::getAuthor()
{
	return author;
}
std::string Book::getTitle()
{
	return title;
}


//setters
void Book::setPages(int pages_)
{
	pages = pages_;
}
void Book::setPrice(double price_)
{
	price = price_;
}
void Book::setAuthor(Author* author_)
{
	author = author_;
}
void Book::setTitle(std::string title_)
{
	title = title_;
}

//persistence
void Book::readData(std::ifstream &filename)
{

	if (filename.eof())
	{
		throw Exception("End of file reached");
	}
	if (filename.fail())
	{
		throw Exception("input file has problem. File failed to read.");
	}
	try

	{
		//read author's data
		author->readData(filename);
	}
	catch (Exception authorfail)
	{
		throw;
	}
		getline(filename, title);
		//use i to temp store data to set to member variables
		std::string i;
		getline(filename, i);
		pages = stoi(i);
		getline(filename, i);
		price = stod(i);
	
	
	if (filename.eof())
	{
		throw Exception("End of file reached");
	}
	else if (filename.fail())
	{
		throw Exception("File failed to read.");
	}
	else if (filename.eof() && filename.fail())
	{
		throw Exception("End of file reached");
	}

}
void Book::writeData(std::ofstream &filename)
{
	author->writeData(filename);
	filename << title << std::endl;
	filename << pages << std::endl;
	filename << price << std::endl;

}

Book::~Book()
{
}

//-AUDIO BOOK-
//constructor
AudioBook::AudioBook()
{
	audioLength = 0;
}
AudioBook::AudioBook(Author* author_, std::string title_, int pages_, double price_, double audioLength_) :Book(author_, title_, pages_, price_)
{
	audioLength = audioLength_;
}

//getters
double AudioBook::getAudioLength()
{
	return audioLength;
}

//setters
void AudioBook::setAudioLength(double audioLength_)
{
	audioLength = audioLength_;
}

//persistence
void AudioBook::writeData(std::ofstream &filename)
{
	Book::writeData(filename);
	filename << audioLength << std::endl;
}
void AudioBook::readData(std::ifstream &filename)
{
	Book::readData(filename);
	std::string i;
	getline(filename, i);
	audioLength = stoi(i);
}

//-DIGITAL BOOK-
//constructor
DigitalBook::DigitalBook()
{
	format = "";
}
DigitalBook::DigitalBook(Author* author_, std::string title_, int pages_, double price_, std::string format_):Book(author_, title_, pages_, price_)
{
	format = format_;
}

//getters
std::string DigitalBook::getFormat()
{
	return format;
}

//setters
void DigitalBook::setFormat(std::string format_)
{
	format = format_;
}

//persistence
void DigitalBook::writeData(std::ofstream &filename)
{
	Book::writeData(filename);
	filename << format<<std::endl;
}
void DigitalBook::readData(std::ifstream &filename)
{
	Book::readData(filename);
	getline(filename, format);

}
//-DIGITAL BOOK-
//constructor
//getters
//setters
//persistence
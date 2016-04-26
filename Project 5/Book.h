#pragma once
#include <string>
#include "Author.h"

class Book
{
protected:

	int pages;
	double price;
	Author *author;
	std::string title;

public:

	//constructor
	Book();
	Book(Author* author_, std::string title_, int pages_, double price_);

	//getters
	int getPages();
	double getPrice();
	Author* getAuthor();
	std::string getTitle();

	//setters
	void setPages(int pages_);
	void setPrice(double price_);
	void setAuthor(Author* author_);
	void setTitle(std::string title_);

	//readwrite
	virtual void readData(std::ifstream &filename);
	virtual void writeData(std::ofstream &filename);

	~Book();
};

class AudioBook : public Book
{
private:

	double audioLength;

public:
	//constructor
	AudioBook();
	AudioBook(Author* author_, std::string title_, int pages_, double price_, double audioLength_);

	//getters
	double getAudioLength();

	//setters
	void setAudioLength(double audioLength_);

	//persistence
	void readData(std::ifstream &filename);
	void writeData(std::ofstream &filename);
};

class DigitalBook : public Book
{
private:

	std::string format;

public:
	//constructor
	DigitalBook();
	DigitalBook(Author* author_, std::string title_, int pages_, double price_, std::string format_);

	//getters
	std::string getFormat();

	//setters
	void setFormat(std::string format_);

	//persistence
	void readData(std::ifstream &filename);
	void writeData(std::ofstream &filename);
};
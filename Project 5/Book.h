#pragma once
#include <string>
#include "Author.h"

class Book
{
public:
private:

	int pages;
	double price;
	Author *author;
	std::string title;

public:

	//constructor
	Book();
	Book(int pages_, double price_, Author author_, std::string title_);

	//getters
	int getPages();
	double getPrice();
	Author getAuthor();
	std::string getTitle();

	//setters
	void setPages(int pages_);
	void setPrice(double price_);
	void setAuthor(Author* author_);
	void setTitle(std::string title_);

	//readwrite
	void virtual readData(std::ifstream &filename);
	void virtual writeData(std::ofstream &filename);

	~Book();
};

class AudioBook : public Book
{
private:

	double audioLength;

public:
	//constructor
	AudioBook();
	AudioBook(double audioLength_, int pages_, double price_, Author* author_, std::string title_);

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
	DigitalBook(std::string format_, int pages_, double price_, Author* author_, std::string title_);

	//getters
	double getFormat();

	//setters
	void setFormat(std::string format_);

	//persistence
	void readData(std::ifstream &filename);
	void writeData(std::ofstream &filename);
};
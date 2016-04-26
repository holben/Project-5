#include "stdafx.h"
#include "Author.h"

//constructor
Author::Author()
{
	name = "";
	address = "";
}
Author::Author(std::string name_, std::string address_)
{
	name = name_;
	address = address_;
}

//getters
std::string Author::getName()
{
	return name;
}
std::string Author::getAddress()
{
	return address;
}

//setters
void Author::setName(std::string name_)
{
	name = name_;
}
void Author::setAddress(std::string address_)
{
	address = address_;
}

//persistence
void Author::readData(std::ifstream &filename)
{
	getline(filename, name);
	getline(filename, address);

	if (filename.fail() && !filename.eof())
	{
		throw Exception("file failed to read from author.");
	}

	if (filename.eof())
	{
		throw Exception("end of file reached on author.");
	}
}
void Author::writeData(std::ofstream &filename)
{
	filename << name << std::endl;
	filename << address << std::endl;
}

Author::~Author()
{
}

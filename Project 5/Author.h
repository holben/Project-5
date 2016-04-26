#pragma once
#include <string>
#include <fstream>
#include "Exception.h"
class Author
{
private:
	std::string name;
	std::string address;

public:
	//constructor
	Author();
	Author(std::string name_, std::string address_);

	//getters
	std::string getName();
	std::string getAddress();

	//setters
	void setName(std::string name_);
	void setAddress(std::string address_);

	//persistence
	void readData(std::ifstream &filename);
	void writeData(std::ofstream &filename);

	~Author();
};
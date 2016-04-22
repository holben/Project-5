#pragma once
#include <string>
#include <fstream>
class Author
{
private:
	std::string name, address;

public:
	Author();
	Author(std::string name, std::string address);

	//getters
	std::string getName();
	std::string getAddress();

	//setters
	//persistence
	void readdata(std::ifstream &filename);
	void writedata(std::ofstream &filename);

	~Author();
};
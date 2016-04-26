#pragma once
#include <string>
class Exception
{
private:
	std::string description;
public:
	Exception(std::string description_);
	std::string getdescription();
	~Exception();
};


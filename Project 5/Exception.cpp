#include "stdafx.h"
#include "Exception.h"


Exception::Exception(std::string description_)
{
	description = description_;
}

std::string Exception::getdescription()
{
	return description;
}

Exception::~Exception()
{
}

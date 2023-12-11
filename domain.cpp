#include "domain.h"

std::string courier::getName()
{
	return this->name;
}

std::vector<std::string> courier::getStr()
{
	return this->streets;
}

int courier::getZone()
{
	return this->zone;
}

std::string package::getRec()
{
	return this->recipient;
}

std::string package::getAdr()
{
	return this->address;
}

int package::getLoc()
{
	return this->location;
}

std::string package::getStat()
{
	return this->status;
}

std::string package::toString()
{
	std::string toret;
	toret += this->recipient + " " + this->address + " " + std::to_string(this->location) + " " + this->status;
	return toret;
}

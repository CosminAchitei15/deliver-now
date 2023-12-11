#pragma once
#include "domain.h"
#include <fstream>
#include <sstream>

class repository
{
private:
	std::vector<courier> couriers;
	std::vector<package> packages;
public:
	repository() {
		readCours();
		readPacks();
	}
	void addPack(package p);
	std::vector<courier> getCours();
	std::vector<package> getPacks();
	void readCours();
	void readPacks();
};


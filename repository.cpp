#include "repository.h"

void repository::addPack(package p)
{
	this->packages.push_back(p);
}

std::vector<courier> repository::getCours()
{
	return this->couriers;
}

std::vector<package> repository::getPacks()
{
	return this->packages;
}

void repository::readCours()
{
	std::ifstream f;
	f.open("couriers.txt");
	while (!f.eof()) {
		std::string line;
		std::vector<std::string> tokens;
		std::getline(f, line);
		std::stringstream linie{ line };
		while (!linie.eof()) {
			std::string token;
			std::getline(linie, token, ',');
			tokens.push_back(token);
		}
		std::string n = tokens[0];
		tokens.erase(tokens.begin());
		int l = stoi(tokens[0]);
		tokens.erase(tokens.begin());
		courier c{ n, tokens, l };
		this->couriers.push_back(c);
	}
	f.close();
}

void repository::readPacks()
{
	std::ifstream f;
	f.open("packages.txt");
	while (!f.eof()) {
		std::string rec, adr, sta;
		int loc;
		f >> rec >> adr >> loc >> sta;
		package p{ rec, adr, loc, sta };
		this->packages.push_back(p);
	}
	f.close();
}

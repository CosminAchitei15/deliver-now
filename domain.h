#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class courier
{
private:
	std::string name;
	std::vector<std::string> streets;
	int zone;
public:
	courier(std::string n, std::vector<std::string> s, int z) :name{ n }, streets{ s }, zone{ z }{}
	std::string getName();
	std::vector<std::string> getStr();
	int getZone();
};

class package {
private:
	std::string recipient, address, status;
	int location;
public:
	package(std::string r, std::string a, int l, std::string s):recipient{r},address{a},location{l},status{s}{}
	std::string getRec();
	std::string getAdr();
	int getLoc();
	std::string getStat();
	std::string toString();
};


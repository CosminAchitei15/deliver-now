#pragma once
#include "repository.h"
class service
{
private:
	repository repo;
public:
	service(repository r):repo{r}{}
	void addPackSev(package p);
	std::vector<courier> getCoursServ();
	std::vector<package> getPacksServ();
	void writePacks();
};


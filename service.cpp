#include "service.h"

void service::addPackSev(package p)
{
	this->repo.addPack(p);
}

std::vector<courier> service::getCoursServ()
{
	return this->repo.getCours();
}

std::vector<package> service::getPacksServ()
{
	return this->repo.getPacks();
}

void service::writePacks()
{
	std::ofstream g;
	g.open("packages.txt");
	for (package p : this->repo.getPacks()) {
		g << p.toString() << '\n';
	}
	g.close();
}

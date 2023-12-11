#include "restanta3.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "domain.h"
#include "service.h"
#include "GUI.h"
#include "observer.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    repository repo{};
    service serv{ repo };
    Subject overseer{};
    QObject::connect(&a, &QApplication::aboutToQuit, QApplication::instance(), [&] {
        serv.writePacks();
        });
    std::vector<GUI*>addresses;
    for (courier c : repo.getCours()) {
        GUI* newcour = new GUI{ c.getName(), c.getStr(), c.getZone(), &serv, &overseer };
        addresses.push_back(newcour);
        overseer.addObserver(newcour);
        newcour->show();
    }
    std::vector<std::string> aux;
    GUI* company = new GUI{ "courier company", aux, 0, &serv, &overseer };
    addresses.push_back(company);
    overseer.addObserver(company);
    company->show();
    return a.exec();
}

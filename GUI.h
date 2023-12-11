#pragma once
#include <QtWidgets>
#include "service.h"
#include "observer.h"
#include <string>

class GUI : public QWidget, public Observer
{
	Q_OBJECT
private:
	service* serv;
	Subject* overseer;
	std::string name;
	int zone;
	std::vector<std::string> streets;

	QVBoxLayout* layout;
	QLabel* zon;
	QListWidget* list;
	QFormLayout* add;
	QLabel* rec, * adr, * loc;
	QLineEdit* rectext, * adrtext, * loctext;
	QPushButton* addbutton;
	QComboBox* combo;
public:
	GUI(std::string n, std::vector<std::string> s, int z, service* se, Subject* su, QWidget* parent = 0) :QWidget{ parent } {
		name = n;
		zone = z;
		serv = se;
		overseer = su;
		streets = s;
		initGUI();
	}
	void initGUI();
	void connect();
	void populateList();
	void update() override;
};


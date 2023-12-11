#include "GUI.h"

void GUI::initGUI()
{
	this->setWindowTitle(this->name.c_str());

	this->layout = new QVBoxLayout{ this };
	this->zon = new QLabel{};
	zon->setText(std::to_string(this->zone).c_str());
	layout->addWidget(zon);

	this->list = new QListWidget{};
	populateList();
	layout->addWidget(list);
	if (this->name == "courier company") {
		this->add = new QFormLayout{};
		rec = new QLabel{}; adr = new QLabel{}; loc = new QLabel{};
		rectext = new QLineEdit{}; adrtext = new QLineEdit{}; loctext = new QLineEdit{};
		rec->setText("Recipient: "); adr->setText("Address: "); loc->setText("Location: ");
		add->addRow(rec, rectext);
		add->addRow(adr, adrtext);
		add->addRow(loc, loctext);
		layout->addLayout(add);

		this->addbutton = new QPushButton{};
		addbutton->setText("ADD");
		layout->addWidget(addbutton);
	}
	else {
		this->combo = new QComboBox{};
		combo->addItem("All streets");
		std::vector<std::string> elems;
		for (package p : this->serv->getPacksServ()) {
			if (std::find(elems.begin(), elems.end(), p.getAdr()) == elems.end())
				elems.push_back(p.getAdr());
		}
		for (auto e : elems) {
			combo->addItem(e.c_str());
		}
		combo->setCurrentIndex(0);
		layout->addWidget(combo);
	}
	connect();
}

void GUI::connect()
{
	if(this->name == "courier company")
		QObject::connect(addbutton, &QPushButton::clicked, this, [this] {
			std::string r, a;
			int l;
			r = rectext->text().toStdString();
			a = adrtext->text().toStdString();
			l = atoi(loctext->text().toStdString().c_str());

			package p{ r, a, l, "false" };
			this->serv->addPackSev(p);
			this->overseer->notify();
			});
	else
		QObject::connect(combo, &QComboBox::currentIndexChanged, this, [this] {
			if (combo->currentText().toStdString() == "All streets") {
				populateList();
			}
			else {
				list->clear();
				for (package p : this->serv->getPacksServ()) {
					if (p.getAdr() == combo->currentText().toStdString())
						list->addItem(QString::fromStdString(p.toString()));
				}
			}
			});
}

void GUI::populateList()
{
	list->clear();
	if (this->name == "courier company") {
		for (package p : this->serv->getPacksServ()) {
			QListWidgetItem* itm = new QListWidgetItem{};
			itm->setText(p.toString().c_str());
			if(p.getStat() == "true")
				itm->setBackground(Qt::green);
			list->addItem(itm);
		}
	}
	else {
		for (package p : this->serv->getPacksServ()) {
			if (std::find(this->streets.begin(), this->streets.end(), p.getAdr()) != this->streets.end() || (p.getLoc() >= this->zone - 5 && p.getLoc() <= this->zone + 5))
				list->addItem(QString::fromStdString(p.toString()));
		}
	}
}

void GUI::update()
{
	populateList();
}

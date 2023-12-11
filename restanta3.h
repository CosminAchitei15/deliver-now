#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_restanta3.h"

class restanta3 : public QMainWindow
{
    Q_OBJECT

public:
    restanta3(QWidget *parent = nullptr);
    ~restanta3();

private:
    Ui::restanta3Class ui;
};

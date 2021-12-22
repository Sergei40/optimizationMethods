#include "ss.h"
#include "ui_ss.h"

ss::ss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ss)
{
    ui->setupUi(this);

    //ui->gridLayout->addWidget(wGraphic,1,0,1,1); // ... и устанавливаем
}

ss::~ss()
{
    delete ui;
}

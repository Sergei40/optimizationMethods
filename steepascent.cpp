#include "steepascent.h"
#include "ui_steepascent.h"

SteepAscent::SteepAscent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SteepAscent)
{
    ui->setupUi(this);
    this->setWindowTitle("метод крутого восхождения Бокса-Уилсона");
}

SteepAscent::~SteepAscent()
{
    delete ui;
}

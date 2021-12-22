#include "nilder.h"
#include "ui_nilder.h"

Nilder::Nilder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nilder)
{
    ui->setupUi(this);
    this->setWindowTitle("метод Нельдера-Мидаа");
}

Nilder::~Nilder()
{
    delete ui;
}

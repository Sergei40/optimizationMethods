#include "simplex.h"
#include "ui_simplex.h"

Simplex::Simplex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Simplex)
{
    ui->setupUi(this);
    this->setWindowTitle("симплекс метод");
}

Simplex::~Simplex()
{
    delete ui;
}

#include "hook.h"
#include "ui_hook.h"

Hook::Hook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hook)
{
    ui->setupUi(this);
    this->setWindowTitle("метод Хука и Дживса");
}

Hook::~Hook()
{
    delete ui;
}

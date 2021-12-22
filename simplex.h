#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <QDialog>

namespace Ui {
class Simplex;
}

class Simplex : public QDialog
{
    Q_OBJECT

public:
    explicit Simplex(QWidget *parent = nullptr);
    ~Simplex();

private:
    Ui::Simplex *ui;
};

#endif // SIMPLEX_H

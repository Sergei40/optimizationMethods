#ifndef NILDER_H
#define NILDER_H

#include <QDialog>

namespace Ui {
class Nilder;
}

class Nilder : public QDialog
{
    Q_OBJECT

public:
    explicit Nilder(QWidget *parent = nullptr);
    ~Nilder();

private:
    Ui::Nilder *ui;
};

#endif // NILDER_H

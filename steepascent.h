#ifndef STEEPASCENT_H
#define STEEPASCENT_H

#include <QDialog>

namespace Ui {
class SteepAscent;
}

class SteepAscent : public QDialog
{
    Q_OBJECT

public:
    explicit SteepAscent(QWidget *parent = nullptr);
    ~SteepAscent();

private:
    Ui::SteepAscent *ui;
};

#endif // STEEPASCENT_H

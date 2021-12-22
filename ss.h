#ifndef SS_H
#define SS_H

#include <QMainWindow>

namespace Ui {
class ss;
}

class ss : public QMainWindow
{
    Q_OBJECT

public:
    explicit ss(QWidget *parent = nullptr);
    ~ss();

private:
    Ui::ss *ui;
};

#endif // SS_H

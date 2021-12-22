#ifndef HOOK_H
#define HOOK_H

#include <QDialog>

namespace Ui {
class Hook;
}

class Hook : public QDialog
{
    Q_OBJECT

public:
    explicit Hook(QWidget *parent = nullptr);
    ~Hook();

private:
    Ui::Hook *ui;
};

#endif // HOOK_H

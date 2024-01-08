#ifndef GARAGEMANAGERDIALOG_H
#define GARAGEMANAGERDIALOG_H

#include <QWidget>

namespace Ui {
class GarageManagerDialog;
}

class GarageManagerDialog : public QWidget
{
    Q_OBJECT

public:
    explicit GarageManagerDialog(QWidget *parent = nullptr);
    ~GarageManagerDialog();

private:
    Ui::GarageManagerDialog *ui;
};

#endif // GARAGEMANAGERDIALOG_H

#ifndef GARAGEMANAGERDIALOG_H
#define GARAGEMANAGERDIALOG_H

#include <QWidget>
#include <QDebug>
#include "infodatabase.h"

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

public slots:
    void garage_search_slot();
private slots:
    void close_dialog();
};

#endif // GARAGEMANAGERDIALOG_H

#ifndef REGISTRERDIALOG_H
#define REGISTRERDIALOG_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;
    QMessageBox register_msg;

private slots:
    void close_dialog();
    void show_register_box();
};

#endif // REGISTRATIONCAR_H

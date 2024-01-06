#ifndef USERMODEUI_H
#define USERMODEUI_H

#include <QWidget>

namespace Ui {
class UserModeUI;
}

class UserModeUI : public QWidget
{
    Q_OBJECT

public:
    explicit UserModeUI(QWidget *parent = nullptr);
    ~UserModeUI();

signals:
    void push_back();

private:
    Ui::UserModeUI *ui;
private slots:
    void push_back_button();
};

#endif // USERMODEUI_H

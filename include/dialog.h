#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>
#include <QScrollBar>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void calibHelp();
    void stereoHelp();
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

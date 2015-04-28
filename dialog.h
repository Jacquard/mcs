#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>
#include <QCryptographicHash>
#include <QString>
#include <QLineEdit>
#include <QByteArray>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QCryptographicHash *hash;
};

#endif // DIALOG_H

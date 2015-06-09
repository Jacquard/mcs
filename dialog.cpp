#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString base64_encode(QString string){
    QByteArray ba;
    ba.append(string);
    return ba.toBase64();
}

QString base64_decode(QString string){
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

void Dialog::on_pushButton_clicked()
{
    QString el = ui->lineEdit->text();
    QByteArray TXT = el.toLatin1();

    QString sha1 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha1).toHex());
    QString md4 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Md4).toHex());
    QString md5 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Md5).toHex());

    if(ui->radioButton->isChecked())
    {
        QString sha224 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha224).toHex());
        QString sha256 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha256).toHex());
        QString sha384 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha384).toHex());
        QString sha512 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha512).toHex());

        ui->label_4->setText(sha224);
        ui->label_6->setText(sha256);
        ui->label_14->setText(sha384);
        ui->label_8->setText(sha512);
        ui->label_16->setText(TXT.toBase64());
    }
    else
    {
        QString sha224 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha3_224).toHex());
        QString sha256 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha3_256).toHex());
        QString sha384 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha3_384).toHex());
        QString sha512 = QString(QCryptographicHash::hash(TXT,QCryptographicHash::Sha3_512).toHex());

        ui->label_4->setText(sha224);
        ui->label_6->setText(sha256);
        ui->label_14->setText(sha384);
        ui->label_8->setText(sha512);
        ui->label_16->setText(TXT.toBase64());
    }

    ui->label_2->setText(sha1);
    ui->label_10->setText(md5);
    ui->label_11->setText(md4);
}

void Dialog::on_tabWidget_tabBarClicked(int index)
{
    ui->
}

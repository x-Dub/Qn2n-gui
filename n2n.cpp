#include "n2n.h"
#include "ui_n2n.h"
#include <QMessageBox>

N2N::N2N(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::N2N)
{
    ui->setupUi(this);
}

N2N::~N2N()
{
    delete ui;
}

void N2N::on_pushButton_clicked()
{
    QString server = ui->lineEdit_1->text();
    QString port = ui->lineEdit_2->text();
    QString sit = ui->lineEdit_3->text();
    QString heslo = ui->lineEdit_4->text();
    QString ip = ui->lineEdit_5->text();
    QString maska = ui->lineEdit_6->text();
    if (server == "")
    {
        QMessageBox::warning(0, QString::fromLocal8Bit("Chybí server!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
    }
    else
    {
        if (port == "")
        {
            QMessageBox::warning(0, QString::fromLocal8Bit("Chybí port serveru!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
        }
        else
        {
            if (sit == "")
            {
                QMessageBox::warning(0, QString::fromLocal8Bit("Chybí název sítě!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
            }
            else
            {
                if (heslo == "")
                {
                    QMessageBox::warning(0, QString::fromLocal8Bit("Chybí heslo!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
                }
                else
                {
                    if (ip == "")
                    {
                        QMessageBox::warning(0, QString::fromLocal8Bit("Chybí IP adresa!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
                    }
                    else
                    {
                        if (maska == "")
                        {
                            QMessageBox::warning(0, QString::fromLocal8Bit("Chybí maska sítě!"), QString::fromLocal8Bit("Pole nesmí být prázdné!"));
                        }
                        else
                        {
                            QString edge = "edge -a " + ip + " -s " + maska +  " -c " + sit + " -k " + heslo + " -l " + server +":"+ port;
                            system(edge.toStdString().c_str());
                            ui->lineEdit_1->setEnabled(false);
                            ui->lineEdit_2->setEnabled(false);
                            ui->lineEdit_3->setEnabled(false);
                            ui->lineEdit_4->setEnabled(false);
                            ui->lineEdit_5->setEnabled(false);
                            ui->lineEdit_6->setEnabled(false);
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(true);
                        }
                    }
                }
            }
        }
    }
}

void N2N::on_actionKonec_triggered()
{
    exit(0);
}

void N2N::on_pushButton_2_clicked()
{
    system("killall edge");
    ui->lineEdit_1->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_6->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

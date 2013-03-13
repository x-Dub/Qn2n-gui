#ifndef N2N_H
#define N2N_H

#include <QMainWindow>

namespace Ui {
class N2N;
}

class N2N : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit N2N(QWidget *parent = 0);
    ~N2N();
    
private slots:
    void on_pushButton_clicked();

    void on_actionKonec_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::N2N *ui;
};

#endif // N2N_H

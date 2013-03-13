#include <QtGui/QApplication>
#include "n2n.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    N2N w;
    w.show();
    
    return a.exec();
}

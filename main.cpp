#include "view/militaryservicetestview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MilitaryServiceTestView w;
    w.show();
    
    return a.exec();
}

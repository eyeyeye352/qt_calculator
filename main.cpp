#include "Calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowTitle("计算器！！");
    w.show();
    return a.exec();
}

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QString>

enum btnType{
    //为按钮分类
    NUM,
    OPERATORS,
    EQUAL,
    DOT,
    CLEAR,
    BACK
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    double calc(double,double,QString);
    //num1,num2为两个操作数，QString方便BACK，operates为使用的运算符。
    QString num1,num2,operates;

public slots:
    void onClicked(btnType type,QString btnName);

};
#endif // CALCULATOR_H

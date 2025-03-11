#include "Calculator.h"
#include "./ui_Calculator.h"
#include <QMessageBox>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);


    //connect链接所有按钮
    connect(ui->btn0,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"0");});
    connect(ui->btn1,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"1");});
    connect(ui->btn2,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"2");});
    connect(ui->btn3,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"3");});
    connect(ui->btn4,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"4");});
    connect(ui->btn5,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"5");});
    connect(ui->btn6,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"6");});
    connect(ui->btn7,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"7");});
    connect(ui->btn8,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"8");});
    connect(ui->btn9,&QPushButton::clicked,[this]{onClicked(btnType::NUM,"9");});

    connect(ui->btn_plus,&QPushButton::clicked,[this]{onClicked(btnType::OPERATORS,"+");});
    connect(ui->btn_minus,&QPushButton::clicked,[this]{onClicked(btnType::OPERATORS,"-");});
    connect(ui->btn_multiply,&QPushButton::clicked,[this]{onClicked(btnType::OPERATORS,"*");});
    connect(ui->btn_divide,&QPushButton::clicked,[this]{onClicked(btnType::OPERATORS,"/");});

    connect(ui->btn_dot,&QPushButton::clicked,[this]{onClicked(btnType::DOT,".");});
    connect(ui->btn_back,&QPushButton::clicked,[this]{onClicked(btnType::BACK,"BACK");});
    connect(ui->btnC,&QPushButton::clicked,[this]{onClicked(btnType::CLEAR,"C");});
    connect(ui->btn_equal,&QPushButton::clicked,[this]{onClicked(btnType::EQUAL,"=");});


}


void Calculator::onClicked(btnType type,QString btnName){
    if(type == btnType::NUM){
        operates.isEmpty() ? num1 += btnName : num2 += btnName;
    }
    else if(type == btnType::OPERATORS){
        if(!num1.isEmpty()) {operates = btnName;}
    }
    else if(type == btnType::BACK){
        if(num2.isEmpty()){
            operates.isEmpty() ? num1.chop(1) : operates.chop(1);
        }else{
            num2.chop(1);
        }
    }
    else if(type == btnType::CLEAR){
        num1 = num2 = operates = "";
    }
    else if(type == btnType::DOT){
        if(operates.isEmpty()){
            if(!(num1.contains(btnName) || num1.isEmpty())){ num1 += btnName;}
        }else{
            if(!(num2.contains(btnName) || num2.isEmpty())){ num2 += btnName;}
        }
    }
    else if(type == btnType::EQUAL){
        if(operates == "/" && num2=="0"){
            QMessageBox::warning(this,"你怎么能除0呢","想除0？祛暑！",QMessageBox::Ok);
        }else{
            num1 = QString::number(calc(num1.toDouble(),num2.toDouble(),operates));
            num2 = operates = "";
        }
    }

    ui->lineEdit->setText(num1 + operates + num2);


};

double Calculator::calc(double n1,double n2,QString op){
    if(op == "+"){return n1+n2;}
    else if(op == "-"){return n1-n2;}
    else if(op == "*"){return n1*n2;}
    else if(op == "/"){return n1/n2;}
}



Calculator::~Calculator()
{
    delete ui;
}

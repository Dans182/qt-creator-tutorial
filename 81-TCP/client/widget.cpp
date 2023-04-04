#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    int pos_z;

    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        ui->listWidget->addItem(T.readAll());
        qDebug() << sizeof(T);
    qDebug() << &T;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_conectar_clicked()
{
    ui->conectar->setEnabled(false);
    mSocket->connectToHost(ui->servidor->text(), ui->puerto->value());
}


void Widget::on_quitar_clicked()
{
    close();
}


#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new localServer(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
    //    if (!mLocalServer->listen(ui->servidor->text())) {
    if (!mLocalServer->listen("MiServidorLocal")){
        QMessageBox::critical(this, "Error", mLocalServer->errorString());
    }
    else {
        QMessageBox::information(this, "servidor", "Iniciado...");
    }
}


void Widget::on_enviar_clicked()
{
    mLocalServer->envia(ui->msj->text());
}


void Widget::on_quitar_clicked()
{
    close();
}


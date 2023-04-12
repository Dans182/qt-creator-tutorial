#include "widget.h"
#include "ui_widget.h"

void quitarApp(){
    qApp->closeAllWindows();
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //aca estamos haciendo la conexión y funcionalidad del botón close.
    //conectamos el botón (ui->pushButton) interfaz gráfica, botón.
    //con la señal "CLICKED" hacia esta misma clase (el Widget)
    //al slot CLOSE.
    //aca estamos conectando el botón con el método close que es nativo de Widget.

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));


    //método alternativo
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::close);


    //tercer método
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(cerrarApp()));

    //cuarto método
    //    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::cerrarApp);

    //quinto método
    //    connect(ui->pushButton, &QPushButton::clicked, quitarApp);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::cerrarApp(){
    close();
};

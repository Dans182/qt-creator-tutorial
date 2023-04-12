#include "objeto.h"
#include <QDebug>

Objeto::Objeto(QObject *parent)
    : QObject{parent}
{

    //ahora hacemos las conexiones
    connect(this, SIGNAL(seyal()), this, SLOT(onSeyal()));
    //que objeto es el de origen
    //que señal voy a utilizar, la señal vacia
    //hacia que clase? hacia esta clase
    //al slot onseñal

    connect(this, SIGNAL(seyal(int)), this, SLOT(onSeyal(int)));
    connect(this, SIGNAL(seyal(char)), this, SLOT(onSeyal(char)));
    connect(this, SIGNAL(seyal(QString)), this, SLOT(onSeyal(QString)));
}

//(Prefijo de la clase a la que pertenecen)
Objeto::~Objeto(){

};

void Objeto::emiteTodasLasSeyales(){
    emit seyal();
    emit seyal(-5);
    emit seyal('@');
    emit seyal("Hola, mundo!");
};

void Objeto::onSeyal(){
    qDebug() << "onSeyal()";
};

void Objeto::onSeyal(int e){
    qDebug() << "onSeyal(int e)" << e;
};

void Objeto::onSeyal(char c){
    qDebug() << "onSeyal(char c)" << c;
};

void Objeto::onSeyal(QString s){
    qDebug() << "onSeyal(QString s)" << s;
};

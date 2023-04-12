#include "objeto.h"
#include <QDebug>

Objeto::Objeto(QObject *parent)
    : QObject{parent}
{

    //ahora hacemos las conexiones
    connect(this, SIGNAL(señal()), this, SLOT(onSeñal()));
    //que objeto es el de origen
    //que señal voy a utilizar, la señal vacia
    //hacia que clase? hacia esta clase
    //al slot onseñal

    connect(this, SIGNAL(señal(int)), this, SLOT(onSeñal(2)));

}
//(Prefijo de la clase a la que pertenecen)
Objeto::~Objeto(){

};

void Objeto::onSeñal(){
    qDebug() << "onSeñal()";
};

void Objeto::onSeñal(int e){
    qDebug() << "onSeñal(int e)" << e;
};

void Objeto::onSeñal(char c){
    qDebug() << "onSeñal(char c)" << c;
};

void Objeto::onSeñal(QString &s){
    qDebug() << "onSeñal(QString s)" << s;
};

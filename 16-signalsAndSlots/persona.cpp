#include "persona.h"
#include <QDebug>

//en este archivo suelen estar los constructores implementados

Persona::Persona(QObject *parent)
    : QObject{parent}
{

}
void Persona::escucha(const QString &palabras){
    qDebug() << m_nombre << "ha escuchado " << palabras;
}

void Persona::habla(const QString &palabras){
    emit hablo(palabras);
    //emit es la palabra reservada para emitir la señal.
}

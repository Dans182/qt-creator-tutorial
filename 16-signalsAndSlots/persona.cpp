#include "persona.h"
#include <QDebug>

//en este archivo suelen estar los constructores implementados

Persona::Persona(QObject *parent)
    : QObject{parent}
{

}

//y el método escucha es la ranura(slot) a la que se va llamar cuando se emite el hablar (la señal)
void Persona::escucha(const QString &palabras){
    qDebug() << m_nombre << "ha escuchado " << palabras;
}

//Metodo habla es el que emite la señal de que alguien habló

void Persona::habla(const QString &palabras){
    emit hablo(palabras);
    //emit es la palabra reservada para emitir la señal.
}

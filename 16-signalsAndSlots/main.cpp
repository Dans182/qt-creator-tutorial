#include <QCoreApplication>
#include "persona.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //creamos un objeto principal QObject
    QObject *p = new QObject; //padre
    Persona *daniel = new Persona(p);
    Persona *euge = new Persona(p); //acá estamos indicando que euge y daniel son hijos de QObject
    daniel->setNombre("Daniel");
    euge->setNombre("Euge");
    //así conectamos signals con slots
    QObject::connect(daniel, SIGNAL(hablo(QString)), euge, SLOT(escucha(QString)));
    QObject::connect(euge, SIGNAL(hablo(QString)), daniel, SLOT(escucha(QString)));
    daniel -> habla("Hola Euge");
    euge->habla("Hola Dani, cómo estás?");
    daniel -> habla("bien gracias, y tú?");
    euge->habla("yo también.");
    delete p;

    return a.exec();
}

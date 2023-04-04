#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString contenido;
    QTextStream io; //io=input and output - entrada y salida
    QFile a;
    a.setFileName("/home/userti/Descargas/doc.txt"); //no importa que no exista. Aca le indicamos el directorio donde lo creará
    a.open(QIODevice::ReadWrite | QIODevice::Text); //QIODevice (entrada y salida) ReadWrite lectura y escritura ::Text, de texto
    if(!a.isOpen()){ //acá preguntamos si se abrió o no.
        qDebug() << "Error: archivo no abierto"; //si no está abierto, salta el error.
        return 1;
    }
    //Como en este caso está abierto
    //    io.setDevice(&a); //como el archivo está abierto, escribimos en el. Texto en el archivo. Acá estoy escribiendo en el archivo
    //io << "Texto de prueba"; //escribimos el contenido del archivo
    //    a.flush(); //limpiamos
    //    a.close(); // cerramos

    //ahora para leer contenido, elegimos primero la variable de entrada (indicamos arriba QString contenido)
    //y en vez de introducir contenido, ahora lo extraeremos y leemos
    io.setDevice(&a);
    contenido = io.readAll(); //leer todo
    io << "\n adios";
    qDebug() << contenido; //muestro el contenido
    a.flush(); //limpiamos
    a.close(); // cerramos
    return app.exec();
}

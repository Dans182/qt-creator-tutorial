#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString s;
    QTextStream io;
    io.setString(&s);
    io << "Hola mundo " << 8 << " " << 9.45;
    qDebug() << s;
    return a.exec();
}

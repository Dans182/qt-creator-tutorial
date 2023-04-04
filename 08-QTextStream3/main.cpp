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

    //o se puede hacer de esta manera
    QString s2 = "12 4.05 Yaaa";
    QTextStream io2;
    io2.setString(&s2);
    int g;
    double h;
    QString i;
    io2 >> g >> h >> i;
    qDebug() << g << h << i;

    return a.exec();
}

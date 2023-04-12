#include <QCoreApplication>
#include "objeto.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Objeto o;
    o.emiteTodasLasSeyales();

    return a.exec();
}

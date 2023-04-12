#ifndef OBJETO_H
#define OBJETO_H

#include <QObject>

class Objeto : public QObject
{
    Q_OBJECT
public:
    explicit Objeto(QObject *parent = nullptr);
    ~Objeto();
signals:
    void señal();
    void señal(int);
    void señal(char);
    void señal(QString);
};

#endif // OBJETO_H

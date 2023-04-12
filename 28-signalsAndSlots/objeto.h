#ifndef OBJETO_H
#define OBJETO_H

#include <QObject>

class Objeto : public QObject
{
    Q_OBJECT

public:
    explicit Objeto(QObject *parent = nullptr);
    ~Objeto();
    void emiteTodasLasSeyales();

    //las seyales son métodos que no se deben implementar
signals:
    void seyal();
    void seyal(int);
    void seyal(char);
    void seyal(QString);

    //los slots son métodos que se deben implementar
public slots:
    void onSeyal();
    void onSeyal(int e);
    void onSeyal(char c);
    void onSeyal(QString s);
};



#endif // OBJETO_H

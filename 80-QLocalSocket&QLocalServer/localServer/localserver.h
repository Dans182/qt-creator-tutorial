#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QLocalServer>

class QLocalSocket;

class localServer : public QLocalServer
{
    Q_OBJECT
public:
    explicit localServer(QObject *parent = nullptr);
    void envia(const QString &msj);
private:
    QLocalSocket *mSocket;
signals:

};

#endif // LOCALSERVER_H

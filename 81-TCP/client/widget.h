#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_conectar_clicked();

    void on_quitar_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
    int pos_x;
};
#endif // WIDGET_H

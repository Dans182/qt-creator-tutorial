#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class localServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_clicked();

    void on_enviar_clicked();

    void on_quitar_clicked();

private:
    Ui::Widget *ui;
    localServer *mLocalServer;
};
#endif // WIDGET_H

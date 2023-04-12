#ifndef Persona_H
#define Persona_H

#include <QObject>

//la clase es un objeto de QObject. Es por esto que acepta señales y ranuras.

class Persona : public QObject //clase heredada de QObject
{
    Q_OBJECT //QObject Macro. Este macro permite que podamos tener Signals and Slots
public:
    //tiene un constructor explícito
    explicit Persona(QObject *parent = nullptr);

    //creamos un método llamado setNombre que recibe una constante por
    //referencia llamada nombre
    void setNombre(const QString &nombre){
        m_nombre = nombre;
    }
    void habla(const QString &palabras);

    //los Signals no son ni public/private
    //la señal y los slots son métodos. Pero en los slots se implementan y en las señales no
signals:
    //todas las señales son void. Una señal es una señal que emite el objeto cuando realiza una acción. Cuando el objeto hable, emite la señal de que está hablando. Y debe haber otra que oye.
    //en las señales no se colocan sino el tipo de variable. No se ponen nombres de variables. Tampoco es necesario indicar "const QString"
    //la señal no es un método en si. Es una señal
    void hablo(QString); //acá cuando alguien hable (habla()) se emitirá una señal (habló(QString)) con el string que llega dentro.

    //los Slots si permiten public/private/protected
public slots:
    //el slot es un método que tiene que implementarse.
    void escucha(const QString &palabras); //al tener que implementarse, lo desarrollamos en el archivo .cpp
private:
    QString m_nombre;

};

#endif // Persona_H

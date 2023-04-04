#include <QCoreApplication>
#include <QDebug>

//jerarquía de objetos/clases
//conformado por clases padres y clases derivadas.
//si eliminas el padre, se eliminan los derivados.
//eso es lo que hace el QObject, automaticamente

class Persona : public QObject  //creamos clase persona que hereda de QObject
{
public:
    //a continuación, el constructor de la clase persona
    Persona(QObject *padre = NULL) //el constructor de persona, debe recibir un QObject padre puntero, que será el padre
        : QObject(padre) //y en el constructor de QObject debemos pasar el padre
    {

    }
    void setNombre(const QString &nombre){
        m_nombre = nombre;
    };
    void setEdad(const int edad){
        m_edad = edad;
    };
    void setSalario(const double &salario){
        m_salario = salario;
    };
    QString getNombre() const{
        return m_nombre;
    };
    int getEdad() const{
        return m_edad;
    };
    double getSalario() const{
        return m_salario;
    };
    ~Persona(){
        qDebug() << m_nombre << "se ha eliminado";
    };

    void imprime() const{
        qDebug() << m_nombre << "" << m_edad << "" << m_salario;
    }

private:
    QString m_nombre;
    int m_edad;
    double m_salario;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona *juan = new Persona;
    Persona *pedro = new Persona(juan);
    Persona *luis = new Persona(juan);
    juan->setNombre("juan");
    juan->setEdad(40);
    juan->setSalario(20000.00);
    pedro->setNombre("pedro");
    pedro->setEdad(8);
    pedro->setSalario(0.00);
    luis->setNombre("luis");
    luis->setEdad(15);
    luis->setSalario(0.00);
    juan->imprime();
    pedro->imprime();
    luis->imprime();
    delete juan; //al eliminar a juan, automáticamente se eliminan todos los hijos.

    return a.exec();
}

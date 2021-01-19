#ifndef CALCULARSALARIO_H
#define CALCULARSALARIO_H

#include <QObject>

class CalcularSalario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float salario READ salario)
    Q_PROPERTY(float descuento READ descuento)
    Q_PROPERTY(float salarioNeto READ salarioNeto)
    Q_PROPERTY(float extras READ extras)
private:

    /* CONSTANTES */ // le ponemos con _ a las constantes
    float const VALOR_HORA_MATUTINO         = 5.15;
    float const VALOR_HORA_VESPERTINO       = 8.50;
    float const VALOR_HORA_NOCTURNO         = 12.65;
    float const PORCENTAJE_DESCUENTO        = 9.5;
    float const VALOR_HORA_EXTRA            = 20.10;

    /* VARIABLES MIEMBRO */
    int m_horas;                        //Número de horas trabajadas
    QString m_nombre;                   //Nombre del trabajador
    char m_jornada;                     //Jornada en la que trabaja [v=vespertina; m=matutina; n=nocturna]

    float m_salario;                    //Valor calculado del salario bruto
    float m_descuento;                  //Valor calculado del descuento
    float m_salarioNeto;                //Valor calculado del salaior neto
    float m_extras;                     //Valor calculado del horas extras

public:
    explicit CalcularSalario(QObject *parent = nullptr);
    CalcularSalario(QString nombre, int horas , char jornada);

    void calcular();
    float descuento() const;
    float salarioNeto() const;
    float salario() const;
    float extras() const;

signals:

};

#endif // CALCULARSALARIO_H

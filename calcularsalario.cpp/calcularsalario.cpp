#include "calcularsalario.h"
#include <QString>

float CalcularSalario::descuento() const
{
    return m_descuento;
}

float CalcularSalario::salarioNeto() const
{
    return m_salarioNeto;
}

float CalcularSalario::salario() const
{
    return m_salario;
}

CalcularSalario::CalcularSalario(QObject *parent) : QObject(parent)
{

}

CalcularSalario::CalcularSalario(QString nombre, int horas, char jornada) : QObject(nullptr)
{
    this->m_nombre = nombre;
    this->m_horas = horas;
    this->m_jornada = jornada;

}

void CalcularSalario::calcular()
{
    float valorHora = 0;
    switch (this->m_jornada) {
    case 'v':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'm':
    valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'n':
        valorHora = VALOR_HORA_NOCTURNO;
    default:
        break;
    }

    this->m_salario = this->m_horas * valorHora;
    this->m_descuento = this->m_salario * PORCENTAJE_DESCUENTO / 100;
    this->m_salarioNeto = this->m_salario - m_descuento;



}




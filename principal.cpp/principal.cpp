#include "principal.h"
#include "ui_principal.h"
#include <QDebug>

#include "calcularsalario.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    connect(ui->action_Calcular, SIGNAL(triggered(bool)),
            this, SLOT(on_cmdCalcular_released()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_cmdCalcular_released()
{
    //Obtener datos del UI
    QString nombre = this->ui->inNombre->text();
    int horas = this->ui->inHoras->value();
    char jornada = 'm';

    if(this->ui->inMatutino->isChecked()){
        jornada = 'm';
    }else if (this->ui->inVespertino->isChecked()){
        jornada = 'v';
    }else{
        jornada = 'n';
    }

    //Crear el objecto para calcular
    CalcularSalario rolPagos(nombre, horas, jornada);
    rolPagos.calcular();

    // LIMPIAR LOS WIDGETS DEK NOMBRE Y LAS HORAS
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);

    ui->outResultados->setPlainText((("\tValores a Pagar \n\nNombre:\n \nSalario:\n "
                                      "\nDescuento:\n \nSalario Neto:\n")));

    //COMPROBAR LOS VALORES
    qDebug() << "Su salario es -->"  << this->ui->inNombre->text();
    qDebug() << "Su salario es -->"  << rolPagos.salario();
    qDebug() << "Descuento --> "  << rolPagos.descuento();
    qDebug() << "Salario Neto --> "  << rolPagos.salarioNeto();

}

#include "IntroducirOrdenDeMatricesDialog.h"
#include "ui_IntroducirOrdenDeMatricesDialog.h"

IntroducirOrdenDeMatricesDialog::IntroducirOrdenDeMatricesDialog
      (QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IntroducirOrdenDeMatricesDialog)
{
    ui->setupUi(this);
    setWindowTitle("Órden de las matrices");
    ui->numeroDeFilasSpinBox->setMinimum(1);
    ui->numeroDeFilasSpinBox->setMaximum(INT_MAX);
    ui->numeroDeColumnasSpinBox->setMinimum(1);
    ui->numeroDeColumnasSpinBox->setMaximum(INT_MAX);
}

IntroducirOrdenDeMatricesDialog::~IntroducirOrdenDeMatricesDialog()
{
    delete ui;
}

int IntroducirOrdenDeMatricesDialog::getNumeroDeFilas() const
{
    return ui->numeroDeFilasSpinBox->value();
}

int IntroducirOrdenDeMatricesDialog::getNumeroDeColumnas() const
{
    return ui->numeroDeColumnasSpinBox->value();
}

void IntroducirOrdenDeMatricesDialog::on_buttonBox_accepted()
{
    accept();
}

void IntroducirOrdenDeMatricesDialog::on_buttonBox_rejected()
{
    reject();
}

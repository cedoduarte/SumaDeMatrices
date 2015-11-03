#include "Widget.h"
#include "ui_Widget.h"
#include "NumeroRealSpinBoxDelegate.h"
#include "IntroducirOrdenDeMatricesDialog.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModelA = new QStandardItemModel(this);
    mModelB = new QStandardItemModel(this);
    mModelResultado = new QStandardItemModel(this);

    ui->tableViewA->setModel(mModelA);
    ui->tableViewB->setModel(mModelB);
    ui->tableViewResultado->setModel(mModelResultado);
    ui->tableViewA->setItemDelegate(new NumeroRealSpinBoxDelegate(this));
    ui->tableViewB->setItemDelegate(new NumeroRealSpinBoxDelegate(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_introducirMatricesPushButton_clicked()
{
    mModelA->clear();
    mModelB->clear();
    mModelResultado->clear();
    IntroducirOrdenDeMatricesDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    const int rowCount = d.getNumeroDeFilas();
    const int colCount = d.getNumeroDeColumnas();
    mModelA->setRowCount(rowCount);
    mModelA->setColumnCount(colCount);
    mModelB->setRowCount(rowCount);
    mModelB->setColumnCount(colCount);
}

void Widget::on_calcularSumaDeMatricesPushButton_clicked()
{
    const int rowCount = mModelA->rowCount();
    const int colCount = mModelA->columnCount();
    mModelResultado->setRowCount(rowCount);
    mModelResultado->setColumnCount(colCount);
    for (int ix = 0; ix < rowCount; ++ix) {
        for (int jx = 0; jx < colCount; ++jx) {
            const double aij = getValueAt(mModelA, ix, jx);
            const double bij = getValueAt(mModelB, ix, jx);
            const double rij = aij + bij;
            mModelResultado->setItem(ix, jx,
                new QStandardItem(QString::number(rij)));
        }
    }
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

double Widget::getValueAt(QStandardItemModel *model, int fila, int col) const
{
    auto item = model->item(fila, col);
    if (!item) {
        return 0.0;
    }
    return item->text().toDouble();
}

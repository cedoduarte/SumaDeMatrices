#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_introducirMatricesPushButton_clicked();
    void on_calcularSumaDeMatricesPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
private:
    double getValueAt(QStandardItemModel *model, int fila, int col) const;

    Ui::Widget *ui;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelB;
    QStandardItemModel *mModelResultado;
};

#endif // WIDGET_H

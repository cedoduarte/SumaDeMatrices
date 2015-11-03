#ifndef INTRODUCIRORDENDEMATRICESDIALOG_H
#define INTRODUCIRORDENDEMATRICESDIALOG_H

#include <QDialog>

namespace Ui
{
class IntroducirOrdenDeMatricesDialog;
}

class IntroducirOrdenDeMatricesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit IntroducirOrdenDeMatricesDialog(QWidget *parent = nullptr);
    ~IntroducirOrdenDeMatricesDialog();
    int getNumeroDeFilas() const;
    int getNumeroDeColumnas() const;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::IntroducirOrdenDeMatricesDialog *ui;
};

#endif // INTRODUCIRORDENDEMATRICESDIALOG_H

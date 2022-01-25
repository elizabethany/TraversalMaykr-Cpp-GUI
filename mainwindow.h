#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonClearOutput_clicked();

    void on_inputStartCoords_textChanged(const QString& arg1);

    void on_inputEndCoords_textChanged(const QString& arg1);

    void on_buttonClearCoords_clicked();

    void on_buttonClearOutputChain_clicked();

    void on_buttonClearCoordsAndAnims_clicked();

    void on_buttonGenerateTraversal_released();

    void on_pushButtonAddMidpoint_clicked();

    void on_buttonGenerateTraversalChain_clicked();

    void on_inputEntityNumChain_textChanged(const QString& arg1);

    void on_inputStartCoordsChain_textChanged(const QString &arg1);

    void on_inputMidCoordsChain_textChanged(const QString &arg1);

    void on_inputEndCoordsChain_textChanged(const QString &arg1);

    void on_pushButton_generateHangout_clicked();

    void on_pushButtonForTesting_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

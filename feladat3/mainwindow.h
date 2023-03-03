#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *object, QEvent *event) override;

private slots:
    void ment();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QLabel* l1;
    QLineEdit* nev;
    QLabel* l2;
    QLineEdit* tel;
    QPushButton * saveButton;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QWidget>
#include <QStringList>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QVBoxLayout *hlayout;
    QLabel *label1;
    QLabel *label2;

    QLineEdit *lineEdit;
    QPushButton * button;

    QComboBox *comboBox;

    QStringList *strList;

    QTextEdit *textEdit;

public slots:

    void search();
    void filter(const QString &text);
};
#endif // MAINWINDOW_H

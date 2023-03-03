#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;
    l1 = new QLabel("Nev");
    nev = new QLineEdit();
    l2 = new QLabel("Telefonszam");
    tel = new QLineEdit();
    saveButton = new QPushButton("Save");
    tel->installEventFilter(this);

    connect (saveButton, &QPushButton:: clicked, this, &MainWindow::ment);

    layout->addWidget(l1);
    layout->addWidget(nev);
    layout->addWidget(l2);
    layout->addWidget(tel);
    layout->addWidget(saveButton);

    setLayout(layout);
}

MainWindow::~MainWindow(){
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent * keyEvent = static_cast<QKeyEvent* >(event);
        if(keyEvent->key() <= 57 && keyEvent->key() >= 48 )
        {
            QString content = tel->text();
            tel->setText(content);
            return false;
        }
        if(keyEvent->key() == Qt::Key_Backspace)
        {
            return false;
        }
        return true;
    }
    return false;
}

void MainWindow::ment()
{
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
          return;

    QString i1=nev->text();
    QString i2=tel->text();
    QString str = i1 + " " + i2;
    QTextStream out(&file);
    out << str << "\n";

    file.close();
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    hlayout = new QVBoxLayout();
    label1 = new QLabel ("Filter:");
    lineEdit = new QLineEdit();

    strList = new QStringList("");

    hlayout->addWidget(label1);
    hlayout->addWidget(lineEdit);

    button = new QPushButton("Open file");
    textEdit = new QTextEdit();

    connect (button, &QPushButton:: clicked, this, &MainWindow::search);
    connect(lineEdit, &QLineEdit::textEdited, this, &MainWindow::filter);

    layout = new QVBoxLayout();
    layout->addLayout(hlayout);
    layout->addWidget(textEdit);
    layout->addWidget(button);
    setLayout(layout);
}

void MainWindow::search()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"),"",tr("Txt files(*.txt)"));
    QFile file (filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream in(&file);
    QString line = in.readAll();
    *strList = QStringList::fromList(line.split('\n'));
    QString elem;
    QString str = "";
    foreach(elem,*strList)
    {
        str+= elem + '\n';
    }
    textEdit->setText(str);
}

void MainWindow::filter(const QString &text)
{
    qDebug() << text;
    QString filterKey = text;
    textEdit->clear();
    textEdit->setText(strList->filter(filterKey).join("\n"));
}


MainWindow::~MainWindow()
{
    delete ui;
}


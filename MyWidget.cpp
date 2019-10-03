#include "Listchange.h"
#include "MyWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>
#include <QDebug>
#include <QFileDialog>

MyWidget::MyWidget(QList<QString> l1,QWidget *parent)
    : QWidget(parent)
{
    QPushButton *OK = new QPushButton(tr("OK"));
    OK->setFont(QFont("Times", 18, QFont::Bold));

    // Creating instance of Listchange.
    Listchange *listchange=new Listchange(l1);

    // Creating buttons required
    QPushButton *putright = new QPushButton(tr(">"));
    QPushButton *putleft = new QPushButton(tr("<"));
    QPushButton *putup = new QPushButton(tr("UP"));
    QPushButton *putdown = new QPushButton(tr("DOWN"));
    QPushButton *allright = new QPushButton(tr(">>"));
    QPushButton *allleft = new QPushButton(tr("<<"));
    //Setting up all the connections required.
    connect(listchange->tableWidget1,SIGNAL(cellClicked(int,int)),listchange,SLOT(changeCurentColumn1(int,int)));
    connect(listchange->tableWidget2,SIGNAL(cellClicked(int,int)),listchange,SLOT(changeCurentColumn2(int,int)));
    connect(putright,   SIGNAL(clicked()),listchange,SLOT(rightadd()));
    connect(putleft,    SIGNAL(clicked()),listchange,SLOT(leftadd()));
    connect(putup,      SIGNAL(clicked()),listchange,SLOT(up()));
    connect(putdown,    SIGNAL(clicked()),listchange,SLOT(down()));
    connect(allright,   SIGNAL(clicked()),listchange,SLOT(allrightadd()));
    connect(allleft,    SIGNAL(clicked()),listchange,SLOT(allleftadd()));
    connect(OK, SIGNAL(clicked()), listchange, SLOT(returnlist1()));
    connect(listchange,SIGNAL(returnlist2(QList<QString>)),this,SIGNAL(returnlist(QList<QString>)));

    // Layout
    QVBoxLayout *layout = new QVBoxLayout;
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->setDirection(QBoxLayout::LeftToRight);
    layout2->addWidget(listchange->tableWidget1);
    QVBoxLayout *layout2b = new QVBoxLayout;
    layout2b->addWidget(putright);
    layout2b->addWidget(putleft);
    layout2b->addWidget(allright);
    layout2b->addWidget(allleft);
    layout2->addLayout(layout2b);
    layout2->addWidget(listchange->tableWidget2);
    QVBoxLayout *layout2d = new QVBoxLayout;
    layout2d->addWidget(putup);
    layout2d->addWidget(putdown);
    layout2->addLayout(layout2d);
    layout->addLayout(layout2);
    layout->addWidget(OK);
    setLayout(layout);
}

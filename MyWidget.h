/**
 * \author Dhwaj Agrawal, Mentor: Shiva
 * \version $Id: MyWidget.h,v 1.2 2010/04/14 10:44:07 psr Exp $
 */

#ifndef MYWIDGET_H
 #define MYWIDGET_H

#include <QWidget>
#include<QList>
#include<QTableWidget>
#include<QFileDialog>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QList<QString>,QWidget *parent = 0);

signals:
    /// Return list signal for returning the final list.
    void returnlist(QList<QString> l3);
public slots:

};

#endif


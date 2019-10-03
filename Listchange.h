#ifndef LISTCHANGE_H
 #define LISTCHANGE_H

#include <QWidget>
#include<QList>
#include<QTableWidget>
class Listchange : public QWidget
{
     Q_OBJECT

 public:
     Listchange(QList<QString> listtemp,QWidget *parent = 0);
     /// Table for Option list
     QTableWidget *tableWidget1;
     /// Table for Final list
     QTableWidget *tableWidget2;

 public slots:
     /// This method is for removing an item from option list and adding it to final list
     void rightadd();
     /// This method is for removing an item from final list and adding it to final list
     void leftadd();
     /// This method removes all the items in option list and add them to final list
     void allrightadd();
     /// This method removes all the items in final list and add them to option list
     void allleftadd();
     /// This method handles the click event on option list
     void changeCurentColumn1(int row,int colum);
     /// This method handles the click event on final list
     void changeCurentColumn2(int row,int colum);
     /// This method moves the selected item in final list up
     void up();
     /// This method moves the selected item in final list down
     void down();
     /// This method is for sending the final list to widget
     void returnlist1();

 signals:
     /// This signal will return the final list
     void returnlist2(QList<QString> l3);

 private:
     /// Option list
     QList<QString>l1;
     /// Final list
     QList<QString>l2;
     /// Selected item's index in option list
     int lpos;
     /// Selected item's index in final list
     int rpos;
};
#endif

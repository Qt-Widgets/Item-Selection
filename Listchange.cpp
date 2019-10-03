#include "Listchange.h"
#include <QDebug>
#include <QtDebug>
#include <QHeaderView>

Listchange::Listchange(QList<QString> listtemp,QWidget *parent)
     : QWidget(parent)
{
    // Initialising option list, selected columns on both tables.
    l1=listtemp;
    rpos=-1;
    lpos=-1;
    // Creating tables Option & Final
    tableWidget1 = new QTableWidget(l1.count(), 1, this);
    tableWidget1->verticalHeader()->hide();
    tableWidget1->horizontalHeader()->hide();
    tableWidget2 = new QTableWidget(0, 1, this);
    tableWidget2->verticalHeader()->hide();
    tableWidget2->horizontalHeader()->hide();    
    // Adding items to Option Table
    for (int i = 0; i < l1.size(); ++i) {
       QTableWidgetItem *newItem = new QTableWidgetItem(l1.at(i));
       tableWidget1->setItem(i, 0, newItem);
    }
}
void Listchange::rightadd()
{
    // Handling no item selected cases
    if(lpos<0)return;
    if(lpos>=l1.size()){
        if(l1.isEmpty())
            lpos=-1;
        return;
    }
    // Making changes in the list required
    l2.append(l1.at(lpos));
    l1.erase(l1.begin()+lpos);
    // Making changes in the tables required
    tableWidget1->removeRow(lpos);
    tableWidget2->insertRow(l2.size()-1);
    QTableWidgetItem *newItem = new QTableWidgetItem(l2.back());
    tableWidget2->setItem(l2.size()-1, 0, newItem);
    // Setting 'No selection' in option table.
    lpos=-1;
    return;
}
void Listchange::leftadd()
{
    // Handling no item selected cases
    if(rpos<0)return;
    if(rpos>=l2.size()){
        if(l2.isEmpty())
            rpos=-1;
        return;
    }
    // Making changes in the list required
    l1.append(l2.at(rpos));
    l2.erase(l2.begin()+rpos);
    // Making changes in the tables required
    tableWidget2->removeRow(rpos);
    tableWidget1->insertRow(l1.size()-1);
    QTableWidgetItem *newItem = new QTableWidgetItem(l1.back());
    tableWidget1->setItem(l1.size()-1, 0, newItem);
    // Setting 'No selection' in Final table.
    rpos=-1;
    return;
}
void Listchange::allrightadd()
{
    for(int i=0;i<l1.size();i++){
        l2.append(l1.at(i));
        tableWidget2->insertRow(l2.size()-1);
        QTableWidgetItem *newItem = new QTableWidgetItem(l2.back());
        tableWidget2->setItem(l2.size()-1, 0, newItem);
        tableWidget1->removeRow(0);
    }
    l1.clear();
    tableWidget1->clear();
    // Setting 'No selection' in option table.
    lpos=-1;
    return;
}
void Listchange::allleftadd()
{
    for(int i=0;i<l2.size();i++){
        l1.append(l2.at(i));
        tableWidget1->insertRow(l1.size()-1);
        QTableWidgetItem *newItem = new QTableWidgetItem(l1.back());
        tableWidget1->setItem(l1.size()-1, 0, newItem);
        tableWidget2->removeRow(0);
    }
    l2.clear();
    tableWidget2->clear();
    // Setting 'No selection' in Final table.
    rpos=-1;
    return;
}
void Listchange::up(){
    // Handling no item selected cases
    if(rpos<=0)return;
    if(rpos>=l2.size())return;
    // Making changes in the list required
    l2.move(rpos,rpos-1);
    // Making changes in the tables required
    tableWidget2->insertRow(rpos-1);
    QTableWidgetItem *newitem = new QTableWidgetItem(l2.at(rpos-1));
    tableWidget2->setItem(rpos-1,0,newitem);
    tableWidget2->removeRow(rpos+1);
    // Selecting the same item previously selected.
    tableWidget2->setCurrentCell(rpos-1,0);
    rpos=rpos-1;
    return;
}
void Listchange::down(){
    // Handling no item selected cases
    if(rpos<0)return;
    if(rpos>=l2.size()-1)return;
    // Making changes in the list required
    l2.move(rpos,rpos+1);
    // Making changes in the tables required
    tableWidget2->insertRow(rpos+2);
    QTableWidgetItem *newitem = new QTableWidgetItem(l2.at(rpos+1));
    tableWidget2->setItem(rpos+2,0,newitem);
    tableWidget2->removeRow(rpos);
    // Selecting the same item previously selected.
    tableWidget2->setCurrentCell(rpos+1,0);
    rpos=rpos+1;
    return;
}

void Listchange::changeCurentColumn1(int row,int colum){
    // Saving the row selected
    lpos=row;
    return;
}
void Listchange::changeCurentColumn2(int row,int colum){
    // Saving the row selected
    rpos=row;
    return;
}
void Listchange::returnlist1(){
    // Emiting the signal with the Final list
    emit returnlist2(l2);
    return;
}


#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QList>
#include <QFileDialog>

#include "Listchange.h"
#include "MyWidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QList<QString> l;
    // Add or Modify Required options Here. Here "one","two" and "three" are options.
    l << "one" << "two" << "three";
    MyWidget widget(l);
    // Signal returnlist(QList<QString>) of widget will contain the final list.
    widget.setGeometry(100, 100, 500, 355);
    widget.show();
    return app.exec();
}

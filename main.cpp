#include "GUI.h"
#include <QApplication>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    Item_Combination_App *CombinationApp = new Item_Combination_App(NULL);
    CombinationApp->show();

    return a.exec();
}

//#include <QApplication>
//#include "setfromgui.hpp"
//#include <QtWidgets>
//int main(int argv,char **args){
//
//   QApplication app(argv,args);
//
//   setfromgui::ReadJson readjson(0);
//
//   bool test;
//
//   while(1){
//
//      std::cin >> test;
//      readjson.change_status(0, test);
//   } 
//   QPushButton button;
//   button.show();
//
//
//   return app.exec();
//}
//
//#else
//
//
//
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <qnamespace.h>
#include "window.hpp"
int main(int argc,char **argv)
{
   QApplication app(argc,argv);

   Window window;
   window.show();


   return app.exec();
}


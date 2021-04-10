#ifndef WINDOW_H
#define WINDOW_H
#define sibou
#include "setfromgui.hpp"
#include <QWidget>
#include <QVBoxLayout>
class QPushButton;
class QComboBox;
class Window : public QWidget
{
   Q_OBJECT
   public:
      explicit Window(QWidget *parent = nullptr);

   private:
      QComboBox *combobox; 

      setfromgui::ReadJson *readjson; 
      QVBoxLayout *layout;
      
};

#endif // WINDOW_H

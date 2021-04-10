#include <vector>
#include <QPushButton>
#include <QComboBox>
#include <QDebug>
#include <QStringList>
#include "window.hpp"
#include "setfromgui.hpp"

Window::Window(QWidget *parent) :
QWidget(parent) 
{

   readjson = new setfromgui::ReadJson(false);

   QStringList scheme_list;
   for (const auto& e : readjson->json["list"]["other"]["colorscheme"]["list"].get<std::vector<std::string>>()) {
      scheme_list.append(QString::fromStdString(e));
   }


   layout = new QVBoxLayout;

   for (int i = 0; i < readjson->json["list"]["toggle"].size(); i++) {
      auto button = new QPushButton(QString::fromStdString(readjson->json["list"]["toggle"][i]["name"]), this);
      button->setCheckable(true);
      connect(button, &QPushButton::clicked, this, [=](bool clicked){readjson->change_status(i, clicked);});
      layout->addWidget(button);
   }

   combobox = new QComboBox(this);
   combobox->addItems(scheme_list);
   layout->addWidget(combobox);
   connect(combobox,
         &QComboBox::currentTextChanged,
         this,
         [=](const QString& text){readjson->change_colorscheme(text.toStdString());});

   setLayout(layout);
}

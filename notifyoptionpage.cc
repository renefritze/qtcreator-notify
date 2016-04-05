#include "notifyoptionpage.hh"
#include "ui_optionsform.h"


NotifyOptionPage::NotifyOptionPage(QObject *parent)
: Core::IOptionsPage(parent)
, m_widget(nullptr)
{
   setId(Core::Id("NotifyOptions"));
   setDisplayName(tr("QtCreatorNotify"));

//   setCategory(Constants::MYOPTIONSPAGE_CATEGORY);
//   setDisplayCategory(QLatin1String(
//      Constants::MYOPTIONSPAGE_CATEGORY_TR_CATEGORY));
//   setCategoryIcon(
   //      QLatin1String(Constants::MYOPTIONSPAGE_CATEGORY_CATEGORY_ICON));
}

QWidget *NotifyOptionPage::widget()
{
  if(m_widget)
    return m_widget;

  m_widget = new QWidget;
  m_ui.setupUi(m_widget);

  return m_widget;
}


void NotifyOptionPage::apply(){
    // Implement the apply botton functionality
}

void NotifyOptionPage::finish(){
    // Implement the ok button functionality
}

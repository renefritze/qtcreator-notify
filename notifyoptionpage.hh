#ifndef NOTIFYOPTIONPAGE_HH
#define NOTIFYOPTIONPAGE_HH

#include <QPointer>
#include <QWidget>
#include <coreplugin/dialogs/ioptionspage.h>
#include "ui_optionsform.h"

class NotifyOptionPage : public Core::IOptionsPage
{
  Q_OBJECT
public:
  explicit NotifyOptionPage(QObject *parent = 0);

private:
  QWidget *widget();
  void apply(void);
  void finish();
  QPointer<QWidget> m_widget;
  Ui::OptionsForm m_ui;
};

#endif // NOTIFYOPTIONPAGE_HH

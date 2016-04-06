#include "qtcreatornotifyplugin.hh"
#include "qtcreatornotifyconstants.hh"
#include "notifyoptionpage.hh"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>
#include <projectexplorer/buildmanager.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QtPlugin>
#include <QProcess>

using namespace QtCreatorNotify::Internal;

QtCreatorNotifyPlugin::QtCreatorNotifyPlugin()
{
  // Create your members
}

QtCreatorNotifyPlugin::~QtCreatorNotifyPlugin()
{
  // Unregister objects from the plugin manager's object pool
  // Delete members
}

bool QtCreatorNotifyPlugin::initialize(const QStringList &arguments, QString *errorString)
{
  // Register objects in the plugin manager's object pool
  // Load settings
  // Add actions to menus
  // Connect to other plugins' signals
  // In the initialize function, a plugin can be sure that the plugins it
  // depends on have initialized their members.

  Q_UNUSED(arguments)
  Q_UNUSED(errorString)

  connect(ProjectExplorer::BuildManager::instance(), SIGNAL(buildQueueFinished(bool)),
          this, SLOT(triggerAction(bool)));

  addAutoReleasedObject(new NotifyOptionPage);
  return true;
}

void QtCreatorNotifyPlugin::extensionsInitialized()
{
  // Retrieve objects from the plugin manager's object pool
  // In the extensionsInitialized function, a plugin can be sure that all
  // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag QtCreatorNotifyPlugin::aboutToShutdown()
{
  // Save settings
  // Disconnect from signals that are not needed during shutdown
  // Hide UI (if you add UI that is not in the main window directly)
  return SynchronousShutdown;
}

void QtCreatorNotifyPlugin::triggerAction(bool success)
{
  std::string cmd("notify-send -u ");
  if(success)
    cmd += "normal ";
  else
    cmd += "critical ";
  cmd += "COMPILE";

  QProcess::execute( QString::fromStdString(cmd));
}


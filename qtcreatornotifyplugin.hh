#ifndef QTCREATORNOTIFY_HH
#define QTCREATORNOTIFY_HH

#include "qtcreatornotify_global.hh"

#include <extensionsystem/iplugin.h>

namespace QtCreatorNotify {
namespace Internal {

class QtCreatorNotifyPlugin : public ExtensionSystem::IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorNotify.json")

public:
  QtCreatorNotifyPlugin();
  ~QtCreatorNotifyPlugin();

  bool initialize(const QStringList &arguments, QString *errorString);
  void extensionsInitialized();
  ShutdownFlag aboutToShutdown();

private slots:
  void triggerAction(bool success);
};

} // namespace Internal
} // namespace QtCreatorNotify

#endif // QTCREATORNOTIFY_HH


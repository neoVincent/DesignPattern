#include "event/switch_widget_event.h"

#include <QCoreApplication>

SwitchWidgetEvent::SwitchWidgetEvent(StateModel::SwitchState state)
    : QEvent(type())
    , m_state(state)
{

}

SwitchWidgetEvent::~SwitchWidgetEvent()
{

}

StateModel::SwitchState SwitchWidgetEvent::getSwitchState()
{
    return m_state;
}

void SwitchWidgetEvent::disptach()
{
    //Please differenitate notify(),sendEvent()
    QCoreApplication::instance()->postEvent(QCoreApplication::instance(),this);
}

QEvent::Type SwitchWidgetEvent::type()
{
    static int type = QEvent::registerEventType();
    return static_cast<QEvent::Type>(type);
}

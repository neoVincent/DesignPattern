#ifndef SWITCHWIDGETEVENT_H
#define SWITCHWIDGETEVENT_H

#include <QEvent>
#include "model/state_model.h"

class SwitchWidgetEvent : public QEvent
{
    Q_GADGET

public:
    SwitchWidgetEvent(StateModel::SwitchState state);
    virtual ~SwitchWidgetEvent();

    StateModel::SwitchState getSwitchState();
    void disptach();

    static QEvent::Type type();

private:
    StateModel::SwitchState m_state;
};

#endif // SWITCHWIDGETEVENT_H

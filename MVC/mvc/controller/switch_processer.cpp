#include "switch_processer.h"
#include "event/switch_widget_event.h"
#include "model/state_model.h"

#include <QCoreApplication>
#include <QDebug>

SwitchProcesser::SwitchProcesser(QObject *parent)
    : QObject(parent)
    , m_threadPool(new QThreadPool)
{
    setAutoDelete(false);
    QCoreApplication::instance()->installEventFilter(this);
}

SwitchProcesser::~SwitchProcesser()
{

}

void SwitchProcesser::setStateModel(QSharedPointer<StateModel> stateModel)
{
    m_stateModel = stateModel;
}

void SwitchProcesser::run()
{
    bool haveItemInQueue = false;
    StateModel::SwitchState transitionTo;
    {
        QMutexLocker locker(&m_mutex);
        haveItemInQueue = !m_changeQueue.isEmpty();
        if (haveItemInQueue)
        {
            transitionTo = m_changeQueue.dequeue();
        }
    }

    if (haveItemInQueue)
    {
        bool transitioned = false;

        switch (transitionTo) {
        case StateModel::SwitchState::DESKTOP:
            qDebug() << "SwitchState::DESKTOP";
            m_stateModel->setSwtichState(StateModel::SwitchState::DESKTOP);
            transitioned = true;
            break;
        case StateModel::SwitchState::LIGHTON:
            qDebug() << "SwitchState::LIGHTON";
            m_stateModel->setSwtichState(StateModel::SwitchState::LIGHTON);
            transitioned = true;
            break;
        case StateModel::SwitchState::LIGHTOFF:
            qDebug() << "SwitchState::LIGHTOFF";
            m_stateModel->setSwtichState(StateModel::SwitchState::LIGHTOFF);
            transitioned = true;
            break;
        default:
            break;
        }
    }
}

bool SwitchProcesser::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == SwitchWidgetEvent::type())
    {
        bool processed;
        auto e = dynamic_cast<SwitchWidgetEvent*>(event);

        if (e != nullptr)
        {
            {
                QMutexLocker locker(&m_mutex);
                m_changeQueue.enqueue(e->getSwitchState());
            }

            processNextChange();

            processed = true;
        }

        return processed ? processed : QObject::eventFilter(watched, event);
    }
    return false;
}

void SwitchProcesser::processNextChange()
{
    m_threadPool->start(this);
}

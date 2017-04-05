#ifndef SWITCHPROCESSER_H
#define SWITCHPROCESSER_H

#include <QObject>
#include <QSharedPointer>
#include <QRunnable>
#include <QThreadPool>
#include <QSharedPointer>
#include <QMutex>
#include <QQueue>

#include "model/state_model.h"

class SwitchProcesser : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit SwitchProcesser(QObject *parent = 0);
    virtual ~SwitchProcesser();

    void setStateModel(QSharedPointer<StateModel> stateModel);
    void run();

private slots:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void processNextChange();

private:
    QSharedPointer<StateModel> m_stateModel;
    QMutex m_mutex;
    QQueue<StateModel::SwitchState> m_changeQueue;
    QSharedPointer<QThreadPool> m_threadPool;
};

#endif // SWITCHPROCESSER_H

#ifndef STATEMODEL_H
#define STATEMODEL_H

#include <QObject>

class StateModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(StateModel::SwitchState swtichState READ swtichState WRITE setSwtichState NOTIFY swtichStateChanged)

public:
    explicit StateModel(QObject *parent = 0);

    enum class SwitchState
    {
        DESKTOP,
        LIGHTON,
        LIGHTOFF,
        INITIAL
    };
    Q_ENUM(SwitchState)


signals:
    void swtichStateChanged(StateModel::SwitchState state);

public:
    void setSwtichState(StateModel::SwitchState state);
    StateModel::SwitchState swtichState();

private:
    StateModel::SwitchState m_state;
};

Q_DECLARE_METATYPE(StateModel::SwitchState)

#endif // STATEMODEL_H

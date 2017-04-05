#include "state_model.h"

static struct Initialize
{
    Initialize()
    {
        qRegisterMetaType<StateModel::SwitchState>();
    }
} initialize;

StateModel::StateModel(QObject *parent)
    : QObject(parent)
    , m_state(SwitchState::INITIAL)
{

}

void StateModel::setSwtichState(SwitchState state)
{
    if (m_state == state) return;

    m_state = state;

    emit swtichStateChanged(m_state);
}

StateModel::SwitchState StateModel::swtichState()
{
    return m_state;
}

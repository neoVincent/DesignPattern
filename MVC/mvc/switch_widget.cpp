#include "switch_widget.h"
#include "ui_switch_widget.h"
#include "event/switch_widget_event.h"

#include <QDebug>
#include <QPropertyAnimation>

SwitchWidget::SwitchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchWidget)
{
    ui->setupUi(this);

}

SwitchWidget::~SwitchWidget()
{
}

void SwitchWidget::setStateModel(QSharedPointer<StateModel> stateModel)
{
    m_stateModel = stateModel;

    connect(m_stateModel.data(), &StateModel::swtichStateChanged, this, &SwitchWidget::onSwitchStateChanged);

}

void SwitchWidget::onSwitchStateChanged(StateModel::SwitchState state)
{
    qDebug() << "SwitchWidget onSwitchStateChanged";
    switch (state) {
    case StateModel::SwitchState::DESKTOP:
        moveBall(ui->desktopButton);
        break;
    case StateModel::SwitchState::LIGHTOFF:
        moveBall(ui->lampOff);
        break;
    case StateModel::SwitchState::LIGHTON:
        moveBall(ui->lampOn);
        break;
    default:
        break;
    }
}

void SwitchWidget::on_desktopButton_clicked(bool checked)
{
    auto event = new SwitchWidgetEvent(StateModel::SwitchState::DESKTOP);
    event->disptach();
}

void SwitchWidget::on_lightOffButton_clicked(bool checked)
{
    auto event = new SwitchWidgetEvent(StateModel::SwitchState::LIGHTOFF);
    event->disptach();
}

void SwitchWidget::on_lightOnButton_clicked(bool checked)
{
    auto event = new SwitchWidgetEvent(StateModel::SwitchState::LIGHTON);
    event->disptach();
}

void SwitchWidget::moveBall(QWidget *target)
{
    QPropertyAnimation* animation = new QPropertyAnimation(ui->highLight, "pos");
    animation->setDuration(300);
    animation->setStartValue(QPoint(ui->highLight->x(), ui->highLight->y()));
    animation->setEndValue(QPoint(target->x(), target->y()));
    animation->start();
}

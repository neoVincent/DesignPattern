#ifndef SWITCH_WIDGET_H
#define SWITCH_WIDGET_H

#include "model/state_model.h"

#include <QWidget>

namespace Ui {
class SwitchWidget;
}

class SwitchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchWidget(QWidget *parent = 0);
    ~SwitchWidget();

    void setStateModel(QSharedPointer<StateModel> stateModel);

public Q_SLOTS:
    void onSwitchStateChanged(StateModel::SwitchState state);

private Q_SLOTS:
    void on_desktopButton_clicked(bool checked);
    void on_lightOffButton_clicked(bool checked);
    void on_lightOnButton_clicked(bool checked);

private:
    void moveBall(QWidget* target);

private:
    Ui::SwitchWidget *ui;
    QSharedPointer<StateModel> m_stateModel;
};

#endif // SWITCH_WIDGET_H

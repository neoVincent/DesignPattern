#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller/switch_processer.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_stateModel(new StateModel)
    , m_switchProcesser(new SwitchProcesser)
{
    ui->setupUi(this);
    setup();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setup()
{

    m_switchProcesser->setStateModel(m_stateModel);

    //Update UI
    ui->switchWidget->setStateModel(m_stateModel);

    connect(m_stateModel.data(), &StateModel::swtichStateChanged, this, [=](StateModel::SwitchState state){
        QString stateString = QVariant::fromValue(state).toString();
        ui->label->setText(stateString);
        qDebug() << "MainWindow: StateModel state changed " << stateString;
    });

}

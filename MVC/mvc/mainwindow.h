#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

class StateModel;
class SwitchProcesser;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setup();

private:
    Ui::MainWindow *ui;
    QSharedPointer<StateModel> m_stateModel;
    QSharedPointer<SwitchProcesser> m_switchProcesser;
};

#endif // MAINWINDOW_H

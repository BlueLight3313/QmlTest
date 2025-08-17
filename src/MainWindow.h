#pragma once

#include <QtWidgets/QWidget>
#include <QQuickWidget>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QQuickWidget* qmlWidget;
};

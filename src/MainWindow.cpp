#include "MainWindow.h"
#include <QVBoxLayout>
#include <QQmlContext>
#include <QMessageBox>
#include <QQmlError>
#include <QFile>
#include <QJsonObject>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent),
    qmlWidget(new QQuickWidget(this))
{
    // Set up layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    this->setLayout(layout);


    // Load the QML file form the resource system
    qmlWidget->setSource(QUrl(QStringLiteral("qrc:/qml/MainWindow.qml")));

    // Check if QML loaded successfully
    if (qmlWidget->status() != QQuickWidget::Ready) {
        // Show an error message box
        QString errorDetails;
        for (const auto& error : qmlWidget->errors()) {
            errorDetails += error.toString() + "\n";
        }
        QMessageBox::critical(this, "QML Load Error",
            "Failed to load QML file:\n" + errorDetails);

        // Optionally, close the application or the window
        QCoreApplication::exit(-1);
        return;
    }

    // Set the QML widget content margins to 0
    qmlWidget->setContentsMargins(0, 0, 0, 0);

    // Make the QML widget fil the available space
    qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    // Add the QML widget to the layout
    layout->addWidget(qmlWidget);

    // Optionally set context properties to interact with QML
    qmlWidget->rootContext()->setContextProperty("cppObject", this);

    //ui.setupUi(this);
}

MainWindow::~MainWindow()
{
    delete qmlWidget;
}

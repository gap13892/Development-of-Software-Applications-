/*! \mainpage Homework assignment - Developement of software Application
 *
 * \section intro_sec Introduction
 *
 * Basic application that shows multiple time series in a chart (using Qt QML and C++)
 * This program demonstrates the use of:
 * \li Qt QNetworkAccessManager to make and receive http requests
 * \li Design a basic UI/front-end using Qt QML
 * \li Implement the backend logic in C++
 * \li Integration of C++ in QML (two-way communication between Qt QML and C++)
 * \n \n \n
 * \section how_sec Working:
 * The program will retrieve stock information from Alpha Vantage by using one of their APIs
 * \li \c https://www.alphavantage.co/documentation/
 * \li \c https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=demo
 *
 * The stock data retrieved, is JSON object containing time series with the stock's open, high, low prices.
 * \n \n \n
 * \section gui_sec The GUI / Front end
 * The GUI is built using QML. It has three buttons and one chart view
 * Three buttons shows the symbol of the Stock that we want to view
 * Chart view shows each stock chart when the respective button is pressed
 * \image html "application.jpg"
 */



#include <QApplication>
#include "networkmanager.h"
#include <QtQml>
#include <QQmlApplicationEngine>

/*!
 * \brief qMain Entry point of ANY C++ program
 * \param argc Number of arguments passed to the function
 * \param argv Argument vector/strings that were passed to the function
 * \return app.exec() causes the actual application to run in an endless loop
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Register the class as a QML object
    qmlRegisterType<NetworkManager>("backend", 0, 1, "MyStock");

    // Create an QML application engine object in order to load the QML file from C++
    QQmlApplicationEngine engine;

    // Load the QML file
    engine.load(QUrl(QStringLiteral("qrc:/qml.qml")));

    return a.exec();
}

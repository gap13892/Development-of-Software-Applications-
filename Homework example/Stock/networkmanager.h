#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QtCharts/QLineSeries>

using namespace QtCharts;

class NetworkManager : public QObject
{


    Q_OBJECT

    QNetworkAccessManager* manager;

public:

        /*!
        * \brief NetworkManager Class Constructor - Initializes a NetworkManager object
        * \param parent QObject
        */
    explicit NetworkManager(QObject *parent = 0);

        /*!
         * \brief loadWebPage gets the JSon format data of the stock from the https://www.alphavantage.co, do all the processing and plot on the graph
         * \param Open data, High Data, low data and symbol
         */

    Q_INVOKABLE void loadWebPage(QLineSeries *open, QLineSeries *high, QLineSeries *low, QString);

private:
signals:
public slots:

};

#endif // NETWORKMANAGER_H

#include "networkmanager.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QtCharts/QLineSeries>
#include <QObject>

using namespace QtCharts;

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{
    
    manager = new QNetworkAccessManager();

}

QString urlString;

void NetworkManager::loadWebPage(QLineSeries *open, QLineSeries *high, QLineSeries *low, QString symbol)
{
    QNetworkRequest request;
    QString apiKey = "RRBIF3AKQYSRUGIR";

    if(symbol=="Microsoft")
    {
         urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=%0").arg(apiKey);
    }
    else if(symbol=="Apple")
    {
         urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=AAPL&apikey=%0").arg(apiKey);
    }
    else if(symbol=="Tesla")
    {
        urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=TSLA&apikey=%0").arg(apiKey);
    }

    QUrl url(urlString);

    request.setUrl(url);

    QNetworkReply *reply = manager->get(request);


            QEventLoop loop;
            connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
            loop.exec();

            QByteArray webData = reply->readAll();
            QString webDataString = QString(webData);
             QJsonDocument jsonResponse = QJsonDocument::fromJson(webDataString.toUtf8());

            QJsonObject jsonObject = jsonResponse.object();


            QJsonObject dailyValues = jsonObject.value("Time Series (Daily)").toObject();
            QStringList dailyValuesKeys = dailyValues.keys();

            for(int i=0; i< dailyValuesKeys.length(); i++)
            {
                QDateTime date;
                date.setDate(QDate::fromString(dailyValuesKeys[i], "yyyy-MM-dd"));

                qDebug() << date.toMSecsSinceEpoch() << dailyValues[dailyValuesKeys[i]].toObject().value("1. open").toString().toDouble();

                open->append(date.toMSecsSinceEpoch(),dailyValues[dailyValuesKeys[i]].toObject().value("1. open").toString().toDouble());
                high->append(date.toMSecsSinceEpoch() ,dailyValues[dailyValuesKeys[i]].toObject().value("2. high").toString().toDouble());
                low->append(date.toMSecsSinceEpoch() ,dailyValues[dailyValuesKeys[i]].toObject().value("3. low").toString().toDouble());

            }


}




import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick 2.9
import QtCharts 2.2
import backend 0.1


ApplicationWindow {
    id: root
    width: 700
    height: 700
    visible: true


    Button {
        id: button
        x: 28
        y: 21
        text: qsTr("Microsoft")
        onClicked: {

            myChart.removeAllSeries();

            axisCommon.min = 60;
            axisCommon.max = 100;
            var openseries = myChart.createSeries(ChartView.SeriesTypeLine, "Open Series",time,axisCommon);
            var highseries = myChart.createSeries(ChartView.SeriesTypeLine, "High Series",time,axisCommon);
            var lowseries = myChart.createSeries(ChartView.SeriesTypeLine, "Low Series",time,axisCommon);

            stock.loadWebPage(openseries,highseries,lowseries,"Microsoft");
        }
    }

    MyStock {
        id: stock
    }

    ValueAxis{
      id: axisCommon
      min : 60
      max : 100
    }

    DateTimeAxis {
    id: time
    format: "yyyy-MM-dd"
    min: "2017-07-13"
    max: "2017-12-04"

    }

    ChartView {
        id: myChart
        x: 76
        y: 82
        title: "My Stock"
        width: 555
        height: 584
        antialiasing: true
    }

    Button {
        id: button1
        x: 156
        y: 21
        text: qsTr("Apple")
        onClicked: {

            myChart.removeAllSeries();

            axisCommon.min = 120;
            axisCommon.max = 190;

            var openseries = myChart.createSeries(ChartView.SeriesTypeLine, "Open Series",time,axisCommon);
            var highseries = myChart.createSeries(ChartView.SeriesTypeLine, "High Series",time,axisCommon);
            var lowseries = myChart.createSeries(ChartView.SeriesTypeLine, "Low Series",time,axisCommon);

            stock.loadWebPage(openseries,highseries,lowseries,"Apple");
        }
    }

    Button {
        id: button2
        x: 289
        y: 21
        text: qsTr("Tesla")
        onClicked: {

            myChart.removeAllSeries();

            axisCommon.min = 250;
            axisCommon.max = 400;

            var openseries = myChart.createSeries(ChartView.SeriesTypeLine, "Open Series",time,axisCommon);
            var highseries = myChart.createSeries(ChartView.SeriesTypeLine, "High Series",time,axisCommon);
            var lowseries = myChart.createSeries(ChartView.SeriesTypeLine, "Low Series",time,axisCommon);

            stock.loadWebPage(openseries,highseries,lowseries,"Tesla");
        }
    }

}

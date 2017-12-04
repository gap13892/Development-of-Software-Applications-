/*! \mainpage Bonus Tasks - Developement of software Application
 *
 * \section intro_sec Introduction
 *
 * Basic application that plays a video file of .avi format in the GUI
 * This program demonstrates the use of :
 * \li Qt main window provides a framework for building an application's user interface
 * \li QMedia player class allows playing of a media source
 * \li The QMediaPlayer class is a high level media playback class. It can be used to playback such content as songs, movies and internet radio.
 * \n \n \n
 * \section how_sec Working:
 * \li User can select which videos they want to play fromt the sample folder
 * \li Video selected is played in the main window provided
 * \li Video can be paused or stopped
 * \li Slider can be used to fast forward or backward the video
 * \li Corresponding progress of the video is hsown in the progress bar
 * \image html "videoplayer.jpg"
 */

#include "mainwindow.h"
#include <QApplication>

/*!
 * \brief qMain Entry point of ANY C++ program
 * \param argc Number of arguments passed to the function
 * \param argv Argument vector/strings that were passed to the function
 * \return app.exec() causes the actual application to run in an endless loop
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // creating the object of type Mainwindow
    MainWindow w;
    // Shows the widget and its child widgets
    w.show();

    return a.exec();
}

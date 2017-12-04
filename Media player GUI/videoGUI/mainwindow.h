#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
    * \brief MainWindow Class Constructor - Initializes a MainWindow object
    * \param parent QObject
    */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    /*!
    * \brief When the open button is clicked the on_actionOpen_triggered() function is called in which the folder can be searched for the video to be played
    *
    */

    void on_actionOpen_triggered();

    /*!
    * \brief When the play button is clicked the on_actionplay_triggered() function is called in which plays the video if it is paused or stopped earlier.
    *
    */

    void on_actionplay_triggered();

    /*!
    * \brief When the pause button is clicked the on_actionPause_triggered() function is called in which the video is paused if it is playing.
    *
    */

    void on_actionPause_triggered();

    /*!
    * \brief When the stop button is clicked the on_actionStop_triggered() function is called which stops the current video from playing
    *
    */

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;    /*! ui of type MainWindow */
    QMediaPlayer* player;   /*! player of type QMediaPlayer */
    QVideoWidget* vw;      /*! vw of type QVideoWidget */
    QProgressBar* bar;      /*! bar of type QProgressBar */
    QSlider* slider;        /*! slider of type QSlider */

};

#endif // MAINWINDOW_H

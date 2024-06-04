#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>
#include "room.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // Destructor to clean up dynamically allocated memory

private slots:
    void on_pushButton_clicked(); // Slot for the button click

private:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QGraphicsEllipseItem* currentRoomMarker;
    QGraphicsScene* scene;

    Room* currentRoom;

    Room* roomGrid[5][5];

    void initializeRooms();
    void updateDescription();
    void createMapDisplay(); // Function to create the map display
};

#endif // MAINWINDOW_H

// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentRoom(nullptr) {
    setGeometry(100, 100, 520, 550);

    // Create widgets
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(10, 10, 500, 30);

    pushButton = new QPushButton("Enter", this);
    pushButton->setGeometry(10, 50, 500, 30);

    label = new QLabel("Welcome to the game!", this);
    label->setGeometry(10, 90, 500, 30);

    // Initialize rooms
    initializeRooms();
    currentRoom = roomGrid[0][0];
    updateDescription();

    // Create and display the map
    createMapDisplay();

    // Connect button's clicked signal to slot
    connect(pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

void MainWindow::on_pushButton_clicked() {
    QString direction = lineEdit->text().toLower();

    if (direction.isEmpty()) {
        label->setText("I beg your pardon?");
        return;
    }

    Room* nextRoom = nullptr;

    if (direction == "n" && currentRoom->getRoom(Room::North) != nullptr)
        nextRoom = currentRoom->getRoom(Room::North);
    else if (direction == "s" && currentRoom->getRoom(Room::South) != nullptr)
        nextRoom = currentRoom->getRoom(Room::South);
    else if (direction == "e" && currentRoom->getRoom(Room::East) != nullptr)
        nextRoom = currentRoom->getRoom(Room::East);
    else if (direction == "w" && currentRoom->getRoom(Room::West) != nullptr)
        nextRoom = currentRoom->getRoom(Room::West);

    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        updateDescription();
    } else {
        // Display "Invalid direction!" and current room description side by side
        label->setText("Invalid input! " + currentRoom->getDescription());
    }

    // Clear the input box
    lineEdit->clear();
}
void MainWindow::initializeRooms() {
    // Create a 5x5 grid of rooms
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            QString roomName = QString("Room %1").arg(i * 5 + j + 1);
            QString roomDesc = QString("You are in %1. There are exits in all directions.").arg(roomName);
            roomGrid[i][j] = new Room(roomName, roomDesc);
        }
    }

    // Link rooms in the grid
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i > 0)
                roomGrid[i][j]->setRoom(Room::North, roomGrid[i - 1][j]);
            if (i < 4)
                roomGrid[i][j]->setRoom(Room::South, roomGrid[i + 1][j]);
            if (j > 0)
                roomGrid[i][j]->setRoom(Room::West, roomGrid[i][j - 1]);
            if (j < 4)
                roomGrid[i][j]->setRoom(Room::East, roomGrid[i][j + 1]);
        }
    }

    // Room 1
    roomGrid[0][0]->setName("Northwest Corner of the Castle");
    roomGrid[0][0]->setDescription("You are in the grand entrance hall of the castle. Torches flicker on the walls.");

    // Room 2
    roomGrid[0][1]->setName("Northwest of the Castle");
    roomGrid[0][1]->setDescription("You are in the grand entrance hall of the castle. Torches flicker on the walls.");

    // Room 3
    roomGrid[0][2]->setName("North of the Castle");
    roomGrid[0][2]->setDescription("You are in the grand entrance hall of the castle. Torches flicker on the walls.");

    // Room 4
    roomGrid[0][3]->setName("Northeast of the Castle");
    roomGrid[0][3]->setDescription("You are in the grand entrance hall of the castle. Torches flicker on the walls.");

    // Room 5
    roomGrid[0][4]->setName("Northeast Corner of the Castle");
    roomGrid[0][4]->setDescription("You are in the grand entrance hall of the castle. Torches flicker on the walls.");

    // Room 6
    roomGrid[1][0]->setName("Northwest of the Castle");
    roomGrid[1][0]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 11
    roomGrid[2][0]->setName("West of the Castle");
    roomGrid[2][0]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 16
    roomGrid[3][0]->setName("Southwest of the Castle");
    roomGrid[3][0]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 21
    roomGrid[4][0]->setName("Southwest Corner of the Castle");
    roomGrid[4][0]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 22
    roomGrid[4][1]->setName("Southwest of the Castle");
    roomGrid[4][1]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 23
    roomGrid[4][2]->setName("South of the Castle");
    roomGrid[4][2]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 24
    roomGrid[4][3]->setName("Southeast of the Castle");
    roomGrid[4][3]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 25
    roomGrid[4][4]->setName("Southeast Corner of the Castle");
    roomGrid[4][4]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 20
    roomGrid[3][4]->setName("Southeast of the Castle");
    roomGrid[3][4]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 15
    roomGrid[2][4]->setName("East of the Castle");
    roomGrid[2][4]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");

    //Room 10
    roomGrid[1][4]->setName("Northeast of the Castle");
    roomGrid[1][4]->setDescription("Books line the walls of this vast library. Dusty tomes sit undisturbed on the shelves.");
}

void MainWindow::updateDescription() {
    if (currentRoom != nullptr) {
        label->setWordWrap(true); // Enable word wrapping
        label->setText(currentRoom->getName() + ". " + currentRoom->getDescription());
    }
}

void MainWindow::createMapDisplay() {
    // Create a new QGraphicsScene
    scene = new QGraphicsScene(this);

    // Set the scene bounds
    scene->setSceneRect(0, 0, 500, 400); // Adjust the width as needed, keeping the height constant

    // Create a QGraphicsView to display the scene
    QGraphicsView* mapView = new QGraphicsView(scene, this);
    mapView->setGeometry(10, 130, 500, 400); // Adjust the position and width as needed

    // Disable horizontal and vertical scroll bars
    mapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add rooms to the scene
    const int cellSize = 100; // Adjust as needed
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            QGraphicsRectItem* roomRect = new QGraphicsRectItem(j * cellSize, i * cellSize, cellSize, cellSize);
            roomRect->setBrush(Qt::lightGray); // Adjust color as needed
            scene->addItem(roomRect);

            // Add room name as text
            QGraphicsTextItem* roomText = new QGraphicsTextItem(roomGrid[i][j]->getName());
            roomText->setTextWidth(cellSize); // Set the text width to match the cell width
            roomText->setTextInteractionFlags(Qt::TextEditorInteraction); // Enable text interaction for wrapping
            roomText->setPos(j * cellSize, i * cellSize); // Set position to top-left corner of cell
            roomText->setTextWidth(cellSize); // Set text width to match cell width
            roomText->setFlag(QGraphicsItem::ItemIgnoresTransformations); // Ignore transformations to keep text centered
            roomText->setDefaultTextColor(Qt::black); // Set text color
            roomText->setTextWidth(cellSize); // Set the text width to match the cell width
            roomText->setHtml("<div align='center'>" + roomGrid[i][j]->getName() + "</div>"); // Center text horizontally and vertically
            scene->addItem(roomText);
        }
    }
}

MainWindow::~MainWindow() {
    // Delete dynamically allocated rooms
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            delete roomGrid[i][j];
        }
    }
}

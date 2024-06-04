#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room {
public:
    enum Direction { North, South, East, West };

    Room(const QString& name, const QString& description, Room* north = nullptr, Room* south = nullptr, Room* east = nullptr, Room* west = nullptr);

    QString getName() const;
    void setName(const QString& newName); // New function to set the name of the room
    QString getDescription() const;
    void setDescription(const QString& newDescription); // New function to set the description of the room
    Room* getRoom(Direction direction) const;
    void setRoom(Direction direction, Room* room);

private:
    QString name;
    QString description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
};

#endif // ROOM_H

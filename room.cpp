#include "room.h"

Room::Room(const QString& name, const QString& description, Room* north, Room* south, Room* east, Room* west)
    : name(name), description(description), north(north), south(south), east(east), west(west) {}

QString Room::getName() const {
    return name;
}

void Room::setName(const QString& newName) {
    name = newName;
}

QString Room::getDescription() const {
    return description;
}

void Room::setDescription(const QString& newDescription) {
    description = newDescription;
}

Room* Room::getRoom(Direction direction) const {
    switch(direction) {
    case North:
        return north;
    case South:
        return south;
    case East:
        return east;
    case West:
        return west;
    }
    return nullptr; // Invalid direction
}

void Room::setRoom(Direction direction, Room* room) {
    switch(direction) {
    case North:
        north = room;
        break;
    case South:
        south = room;
        break;
    case East:
        east = room;
        break;
    case West:
        west = room;
        break;
    }
}

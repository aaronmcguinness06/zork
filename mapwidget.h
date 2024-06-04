#include <QWidget>
#include <QPainter>

class MapWidget : public QWidget {
public:
    MapWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    // Set the current location of the player
    void setCurrentLocation(int x, int y) {
        currentX = x;
        currentY = y;
        update(); // Request a repaint
    }

    int currentX = 0; // Current X coordinate of the player's location
    int currentY = 0; // Current Y coordinate of the player's location

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);

        // Set up the grid dimensions
        int gridSize = 20;
        int gridWidth = 5;
        int gridHeight = 5;

        // Draw grid lines
        painter.setPen(Qt::black);
        for (int i = 0; i <= gridWidth; ++i) {
            painter.drawLine(i * gridSize, 0, i * gridSize, gridHeight * gridSize);
        }
        for (int i = 0; i <= gridHeight; ++i) {
            painter.drawLine(0, i * gridSize, gridWidth * gridSize, i * gridSize);
        }

        // Draw current location
        painter.setBrush(Qt::red);
        painter.drawRect(currentX * gridSize, currentY * gridSize, gridSize, gridSize);
    }

private:

};

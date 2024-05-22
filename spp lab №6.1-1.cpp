#include <iostream>
#include "FileName.h"

// Point class methods
Point::Point(double x, double y) : x(x), y(y) {}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::resize(double factor) {
    // Resize doesn't apply to a single point, but can be overridden in derived classes
}

void Point::rotate(double angle) {
    // Rotation doesn't apply to a single point, but can be overridden in derived classes
}

void Point::display() const {
    std::cout << "Point (" << x << ", " << y << ")\n";
}

// Pentagon class methods
Pentagon::Pentagon(double x, double y, double sideLength)
    : Point(x, y), sideLength(sideLength) {}

void Pentagon::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Pentagon::resize(double factor) {
    sideLength *= factor;
}

void Pentagon::rotate(double angle) {
    // Rotate around the center (x, y) by the given angle in degrees
    // For simplicity, rotation is not changing vertices positions, just displaying rotation effect
    std::cout << "Rotating Pentagon around (" << x << ", " << y << ") by " << angle << " degrees\n";
}

void Pentagon::display() const {
    std::cout << "Pentagon at (" << x << ", " << y << ") with side length " << sideLength << "\n";
}

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Move object\n";
    std::cout << "2. Resize object\n";
    std::cout << "3. Rotate object\n";
    std::cout << "4. Display object\n";
    std::cout << "5. Exit\n";
}

int main() {
    Pentagon pentagon(0, 0, 5);

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double dx, dy;
            std::cout << "Enter dx and dy: ";
            std::cin >> dx >> dy;
            pentagon.move(dx, dy);
            break;
        }
        case 2: {
            double factor;
            std::cout << "Enter resize factor: ";
            std::cin >> factor;
            pentagon.resize(factor);
            break;
        }
        case 3: {
            double angle;
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            pentagon.rotate(angle);
            break;
        }
        case 4:
            pentagon.display();
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

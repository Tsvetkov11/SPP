#ifndef GRAPHICS_OBJECTS_H
#define GRAPHICS_OBJECTS_H

#include <iostream>
#include <vector>
#include <cmath>

class Point {
protected:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);
    virtual ~Point() = default;

    virtual void move(double dx, double dy);
    virtual void resize(double factor);
    virtual void rotate(double angle);
    virtual void display() const;
};

class Pentagon : public Point {
private:
    double sideLength;

public:
    Pentagon(double x = 0, double y = 0, double sideLength = 1);

    void move(double dx, double dy) override;
    void resize(double factor) override;
    void rotate(double angle) override;
    void display() const override;
};

#endif // GRAPHICS_OBJECTS_H

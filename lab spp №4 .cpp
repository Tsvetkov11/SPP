
#include <iostream>
using namespace std;

class Figure {
protected:
    int width;
    int height;
public:
    Figure(int w, int h) : width(w), height(h) {}

    int getWidth() { return width; }
    void setWidth(int w) { width = w; }

    int getHeight() { return height; }
    void setHeight(int h) { height = h; }
};

class Rectangle : public Figure {
private:
    string color;
public:
    Rectangle(int w, int h, string c) : Figure(w, h), color(c) {}

    string getColor() { return color; }
    void setColor(string c) { color = c; }

    int area() { return width * height; }
};

int main() {
    Rectangle rect(5, 4, "Red");
    cout << "Width: " << rect.getWidth() << ", Height: " << rect.getHeight() << ", Color: " << rect.getColor() << endl;
    cout << "Area: " << rect.area() << endl;

    return 0;
}

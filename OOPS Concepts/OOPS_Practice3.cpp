/*Objective: Implement single inheritance with an area calculation.
Task: Create a base class Shape with a protected attribute color. Derive a class Circle
that has an additional attribute radius. Implement a method calculateArea() in Circle to
calculate the area of the circle and display it along with the color. */
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
    protected:
    string color;

    public:
    // Constructor to initialize color
    Shape(const string &col) : color(col) {}
};

class Circle : public Shape {
    private:
    double radius;

    public:
    // Constructor to initialize color and radius
    Circle(const string &col, double r) : Shape(col), radius(r) {}

    // Method to calculate and display area
    void calculateArea() const {
        double area = M_PI * radius * radius;
        cout << "Color: " << color << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area of Circle: " << area << endl;
    }
};

int main() {
    // Create a Circle object with color and radius
    Circle circle("Red", 5.0);
    // Calculate and display the area along with color
    circle.calculateArea();
    return 0;
}
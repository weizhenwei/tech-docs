#include <stdio.h>

class Shape {
public:
    enum ShapeColor {Red, Green, Blue};
    virtual void draw(ShapeColor color = Red) const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
    virtual ~Rectangle() {}
    virtual void draw(ShapeColor color = Green) const;
};
void Rectangle::draw(ShapeColor color) const {
    switch(color) {
        case Red:
            printf("color = Red\n");
            break;
        case Green:
            printf("color = Green\n");
            break;
        case Blue:
            printf("color = Blue\n");
            break;
        default:
            printf("unsupported color\n");
            break;
    }
}

class Circle : public Shape {
public:
    virtual ~Circle() {}
    virtual void draw(ShapeColor color) const;
};
void Circle::draw(ShapeColor color) const {
    switch(color) {
        case Red:
            printf("color = Red\n");
            break;
        case Green:
            printf("color = Green\n");
            break;
        case Blue:
            printf("color = Blue\n");
            break;
        default:
            printf("unsupported color\n");
            break;
    }
}

int main() {
    Rectangle rectangle;
    rectangle.draw();  // output is Green, no polymorphic.

    Shape *shape = new Rectangle;
    shape->draw();  // polymorphic, output is Red, which is base class's default parameter!


    Circle circle;
    circle.draw(Shape::Blue);  // must assign parameter here, or compile error!
    Shape *shape2 = new Circle();
    shape2->draw();  // polymorphic, output is Red, which is base class's default parameter!

    return 0;
}


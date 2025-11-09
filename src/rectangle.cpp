#include "../include/rectangle.h"
#include <cmath>

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Rectangle::Rectangle(const Rectangle& other) {
    for (int i = 0; i < 4; i++) {
        vertices[i] = other.vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept {
    for (int i = 0; i < 4; i++) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

Point Rectangle::center() const {
    double x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4;
    double y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4;
    return Point{x, y};
}

Rectangle::operator double() const {
    double width = std::sqrt(
        std::pow(vertices[1].x - vertices[0].x, 2) + 
        std::pow(vertices[1].y - vertices[0].y, 2)
    );
    double height = std::sqrt(
        std::pow(vertices[2].x - vertices[1].x, 2) + 
        std::pow(vertices[2].y - vertices[1].y, 2)
    );
    return width * height;
}

void Rectangle::read(std::istream& is) {
    for (int i = 0; i < 4; i++) {
        is >> vertices[i].x >> vertices[i].y;
    }
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: ";
    for (int i = 0; i < 4; i++) {
        os << "(" << vertices[i].x << "," << vertices[i].y << ") ";
    }
}

bool Rectangle::equal(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (!otherRect) return false;
    
    for (int i = 0; i < 4; i++) {
        if (vertices[i].x != otherRect->vertices[i].x ||
            vertices[i].y != otherRect->vertices[i].y) {
            return false;
        }
    }
    return true;
}
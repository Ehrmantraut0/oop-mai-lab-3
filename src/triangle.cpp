#include "../include/triangle.h"
#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
}

Triangle::Triangle(const Triangle& other) {
    for (int i = 0; i < 3; i++) {
        vertices[i] = other.vertices[i];
    }
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        for (int i = 0; i < 3; i++) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Triangle::Triangle(Triangle&& other) noexcept {
    for (int i = 0; i < 3; i++) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 3; i++) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

Point Triangle::center() const {
    double x = (vertices[0].x + vertices[1].x + vertices[2].x) / 3;
    double y = (vertices[0].y + vertices[1].y + vertices[2].y) / 3;
    return Point{x, y};
}

Triangle::operator double() const {
    double area = std::abs(
        (vertices[0].x * (vertices[1].y - vertices[2].y) +
         vertices[1].x * (vertices[2].y - vertices[0].y) +
         vertices[2].x * (vertices[0].y - vertices[1].y)) / 2.0
    );
    return area;
}

void Triangle::read(std::istream& is) {
    for (int i = 0; i < 3; i++) {
        is >> vertices[i].x >> vertices[i].y;
    }
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: ";
    for (int i = 0; i < 3; i++) {
        os << "(" << vertices[i].x << "," << vertices[i].y << ") ";
    }
}

bool Triangle::equal(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    
    for (int i = 0; i < 3; i++) {
        if (vertices[i].x != otherTriangle->vertices[i].x ||
            vertices[i].y != otherTriangle->vertices[i].y) {
            return false;
        }
    }
    return true;
}



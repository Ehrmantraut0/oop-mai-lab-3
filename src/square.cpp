#include "../include/square.h"
#include <cmath>

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Square::Square(const Square& other) {
    for (int i = 0; i < 4; i++) {
        vertices[i] = other.vertices[i];
    }
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Square::Square(Square&& other) noexcept {
    for (int i = 0; i < 4; i++) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}


Point Square::center() const {
    double x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4;
    double y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4;
    return Point{x, y};
}

Square::operator double() const {
    double side = std::sqrt(
        std::pow(vertices[1].x - vertices[0].x, 2) + 
        std::pow(vertices[1].y - vertices[0].y, 2)
    );
    return side * side;
}

void Square::read(std::istream& is) {
    for (int i = 0; i < 4; i++) {
        is >> vertices[i].x >> vertices[i].y;
    }
}

void Square::print(std::ostream& os) const {
    os << "Square: ";
    for (int i = 0; i < 4; i++) {
        os << "(" << vertices[i].x << "," << vertices[i].y << ") ";
    }
}

bool Square::equal(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    
    for (int i = 0; i < 4; i++) {
        if (vertices[i].x != otherSquare->vertices[i].x ||
            vertices[i].y != otherSquare->vertices[i].y) {
            return false;
        }
    }
    return true;
}
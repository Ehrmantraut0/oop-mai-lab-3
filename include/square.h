#pragma once
#include "../include/figure.h"

class Square : public Figure {
private:
    Point vertices[4];

public:
    Square() = default;
    Square(Point p1, Point p2, Point p3, Point p4);
    
    Point center() const override;
    explicit operator double() const override;

    Square(const Square& other);
    Square& operator=(const Square& other);
    
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;

protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};
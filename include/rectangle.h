#pragma once
#include "../include/figure.h"

class Rectangle : public Figure {
private:
    Point vertices[4];

public:
    Rectangle() = default;
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    Point center() const override;
    explicit operator double() const override;

protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};
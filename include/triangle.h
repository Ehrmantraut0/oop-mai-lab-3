#pragma once
#include "../include/figure.h"

class Triangle : public Figure {
private:
    Point vertices[3];

public:
    Triangle() = default;
    Triangle(Point p1, Point p2, Point p3);
    
    Point center() const override;
    explicit operator double() const override;
    
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;


protected:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};
#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend bool operator==(const Figure& figure1, const Figure& figure2);
    
    virtual Point center() const = 0;
    virtual explicit operator double() const = 0;
    virtual ~Figure() = default;

protected:
    virtual void read(std::istream& is) = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual bool equal(const Figure& other) const = 0;
};

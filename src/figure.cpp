#include "../include/figure.h"

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}

bool operator==(const Figure& figure1, const Figure& figure2) {
    return figure1.equal(figure2);
}
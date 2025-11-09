#include <iostream>
#include <vector>
#include "include/triangle.h"
#include "include/square.h"
#include "include/rectangle.h"

int main() {
    std::vector<Figure*> figures;
    std::string command;
    std::cin >> command;
    
    std::cout << "Commands: triangle, square, rectangle, delete <index>, exit" << std::endl;
    
    while (command != "exit") {
        if (command == "triangle" || command == "square" || command == "rectangle") {
            Figure* figure = nullptr;
            
            if (command == "triangle") figure = new Triangle();
            else if (command == "square") figure = new Square();
            else if (command == "rectangle") figure = new Rectangle();
            
            std::cin >> *figure;
            figures.push_back(figure);
            std::cout << "Added " << command << " as figure " << figures.size()-1 << std::endl;
        }
        else if (command == "delete") {
            int index;
            std::cin >> index;
            
            if (index >= 0 && index < (int)figures.size()) {
                delete figures[index];
                figures.erase(figures.begin() + index); 
                std::cout << "Deleted figure " << index << std::endl;
            } else {
                std::cout << "Invalid index!" << std::endl;
            }
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }
        std::cin >> command;
    }
    
    double totalArea = 0;
    std::cout << "\nFinal figures:" << std::endl;
    for (size_t i = 0; i < figures.size(); i++) {
        std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
        Point center = figures[i]->center();
        double area = static_cast<double>(*figures[i]);
        std::cout << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
        std::cout << "Area: " << area << std::endl;
        std::cout << "---" << std::endl;
        totalArea += area;
    }
    
    std::cout << "Total area: " << totalArea << std::endl;
    
    for (Figure* figure : figures) {
        delete figure;
    }
    
    return 0;
}
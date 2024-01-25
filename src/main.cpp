#include <iostream>
#include "../lib/Curves.h"
#include <utility>
#include <memory>
#include <algorithm>
#include <vector>

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

std::vector<std::shared_ptr<Figure>> GenerateFigures(int size = 5){ //по умолчанию будем создавать 5 элементов
    std::vector<std::shared_ptr<Figure>> result;
    for(int i = 0; i < size; ++i){
        switch(rand() % 3){
            case 0:
                result.push_back( std::make_shared<Circle>( fRand(1., 10.) ) ); //random radius [1; 10]
                break;
            case 1:
                result.push_back( std::make_shared<Ellipse>( fRand(1., 10.), fRand(1., 10.) ) ); //random radiuses [1; 10]
                break;
            default: //case 2
                result.push_back( std::make_shared<Helix>( fRand(1., 10.), fRand(1., 10.) ) ); // random radius and step [1; 10]
                break;
        }
    }
    return result; 
}

void PrintPointsAndDerivatives(const std::vector<std::shared_ptr<Figure>>& figures_vec){
    double t = PI / 4;
    int i = 1;
    for(const auto& figure : figures_vec){
        Point point = figure->getPoint(t);
        Point derivative = figure->derivative(t);
        std::cout << i++ << ":\nCoordinates: " << point << "\nDerivatives: " << derivative << std::endl; 
    }
}

std::vector<std::shared_ptr<Circle>> GetSortedCircles(const std::vector<std::shared_ptr<Figure>>& figures_vec){
    std::vector<std::shared_ptr<Circle>> result;
    
    for(const auto& figure : figures_vec){
        std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(figure);
        if(circle){
            result.push_back(circle);
        }
    }
    
    std::sort(result.begin(), result.end(), [](const std::shared_ptr<Circle>& lhs, const std::shared_ptr<Circle>& rhs){
        return lhs->getRadius() < rhs->getRadius();
    });
    
    return result;
}

double SumOfRadii(const std::vector<std::shared_ptr<Circle>>& circles_vec){
    double sum = 0;
    for(const std::shared_ptr<Circle>& circle : circles_vec){
        sum += circle->getRadius();
    }
    return sum;
}

int main(){
    auto figures = GenerateFigures(20);
    auto circles = GetSortedCircles(figures);
    PrintPointsAndDerivatives(figures);
    std::cout << std::endl;
    int i = 1;
    for(const auto& circle : circles){
        std::cout << "Radius of circle #" << i++ << " is " << circle->getRadius() << std::endl; 
    } 
    std::cout << "Total sum of radii: " << SumOfRadii(circles) << std::endl;
}
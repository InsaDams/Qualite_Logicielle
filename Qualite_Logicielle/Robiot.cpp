#include "Robiot.h"
#include <cmath>
#include <iostream>
using namespace std;


Robiot::Robiot(string pathfile) : path(pathfile)
{
	
}

//void Point::setX(double x)
//{
//    this->x = x;
//}
//
//void Point::setY(double y)
//{
//    this->y = y;
//}
//
//double Point::getX() const
//{
//    return this->x;
//}
//
//double Point::getY() const
//{
//    return this->y;
//}
//
//double Point::distance(const Point& P) const
//{
//    double dx = this->x - P.x;
//    double dy = this->y - P.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//Point Point::milieu(const Point& P) const
//{
//    Point result;
//    result.x = (P.x + this->x) / 2;
//    result.y = (P.y + this->y) / 2;
//    return result;
//}
//
//void Point::saisir()
//{
//    cout << "Tapez l'abscisse : ";  cin >> this->x;
//    cout << "Tapez l'ordonnée : ";  cin >> this->y;
//}
//
//void Point::afficher() const
//{
//    cout << "L'abscisse vaut " << this->x << endl;
//    cout << "L'ordonnée vaut " << this->y << endl;
//}
#pragma once
#include "GeometricSolidCalc.h"
#include "ShapeCalc.h"
#include <cmath>

const double _pi = acos(-1.0);
//立体图形类
double Cuboid::SurfaceArea() { return 2 * (length * width + length * heigth + width * heigth); }
double Cuboid::Volume() { return length * width * heigth; }
double Cube::SurfaceArea() { return 6 * (sidelength * sidelength); }
double Cube::Volume() { return sidelength * sidelength * sidelength; }
double Cylinder::GetPreimeter() { return Circle::Preimeter(); }
double Cylinder::GetArea() { return Circle::Area(); }
double Cylinder::SurfaceArea() { return 2 * GetArea() + GetPreimeter() * heigth; }
double Cylinder::Volume() { return Area() * heigth; }
double Cone::GetArea() { return Circle::Area(); }
double Cone::SurfaceArea() { return GetArea() + _pi * radius * Generatrixlength; }
double Cone::Volume() { return (1 / 3.0) * GetArea() * heigth; }
double CircularTruncatedCone::SurfaceArea() { return _pi * (radius1 * radius1 + radius2 * radius2) + _pi * (radius1 + radius2) * GeneratrixLength; }
double CircularTruncatedCone::Volume() { return _pi * (radius1 * radius1 + radius1 * radius2 + radius2 * radius2) * heigth * (1 / 3.0); }
double Sphere::SurfaceArea() { return 4 * _pi * radius * radius; }
double Sphere::Volume() { return 4 * radius * radius * radius * (1 / 3.0); }
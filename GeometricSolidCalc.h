#pragma once 
#include "ShapeCalc.h"

class GeometricSolid
{
public:
    GeometricSolid() {}
    ~GeometricSolid() {}
    virtual double Volume() = 0;
};
class Pyramid :public GeometricSolid
{
public:
    Pyramid(){}
    ~Pyramid(){}
    virtual double Volume() = 0;
};
class ColumnGeometricSolid :public GeometricSolid
{
public:
    ColumnGeometricSolid() {}
    ~ColumnGeometricSolid() {}
    virtual double Volume() = 0;
    virtual double SurfaceArea() = 0;
};
class Cuboid :public GeometricSolid
{
private:
    double length, width, heigth;
public:
    Cuboid(double l, double w, double h) { length = l; width = w; heigth = h; }
    ~Cuboid(){}
    double SurfaceArea();
    double Volume();
};
class Cube :public Cuboid
{
private:
    double sidelength;
public:
    Cube(double sl, double l, double w, double h) :Cuboid(l, w, h) { sidelength = sl; }
    ~Cube(){}
    double SurfaceArea();
    double Volume();
};
class Cylinder :public ColumnGeometricSolid, public Circle
{
private:
    double radius, heigth;
public:
    Cylinder(double r, double h) :Circle(r) { radius = r; heigth = h; }
    ~Cylinder(){}
    double GetPreimeter();
    double GetArea();
    double SurfaceArea();
    double Volume();
};
class Cone :public Pyramid, public Circle
{
private:
    double radius, heigth, Generatrixlength;
public:
    Cone(double r, double h, double Generatrixl) :Circle(r) { radius = r; heigth = h; Generatrixlength = Generatrixl; }
    ~Cone(){}
    double GetArea();
    double SurfaceArea();
    double Volume();
};
class CircularTruncatedCone :public Cone
{
private:
    double radius1, radius2, heigth, GeneratrixLength;
public:
    CircularTruncatedCone(double r1, double r2, double h, double Gl) :Cone(r1, h, Gl) { radius1 = r1; radius2 = r2; heigth = h; GeneratrixLength = Gl; }
    ~CircularTruncatedCone(){}
    double SurfaceArea();
    double Volume();
};
class Sphere :public GeometricSolid
{
private:
    double radius;
public:
    Sphere(double r) { radius = r; }
    ~Sphere(){}
    double SurfaceArea();
    double Volume();
};
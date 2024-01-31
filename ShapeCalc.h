#pragma once

class Triangle
{
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    ~Triangle() {}
    bool IsTriangle();
    double Preimeter();
    double Area();
};
class Circle
{
private:
    double radius;
public:
    Circle(double r) { radius = r; }
    ~Circle() {}
    double Preimeter();
    double Area();
};
class  CircluarRing :public Circle
{
private:
    double radius1, radius2;
public:
    CircluarRing(double r1, double r2, double r) :Circle(r) { radius1 = r1; radius2 = r2; }
    ~CircluarRing() {}
    bool compareRadius();
    double Preimeter();
    double Area();

};
class Trapezoid
{
private:
    double side1, side2, side3, side4, heigth_parallzed_sides;
public:
    Trapezoid(double s1, double s2, double s3, double s4, double h_s1s2)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
        heigth_parallzed_sides = h_s1s2;
    }
    ~Trapezoid() {}
    double Preimeter();
    double Area();
};
class Parallelogram
{
private:
    double side1, side2, heigthOnSide1;
public:
    Parallelogram(double s1, double s2, double h_s1) { side1 = s1; side2 = s2; heigthOnSide1 = h_s1; }
    ~Parallelogram() {}
    double Preimeter();
    double Area();
};
class Rectangle :public Parallelogram
{
private:
    double length, width;
public:
    Rectangle(double l, double w, double s1, double s2, double h_s1) :Parallelogram(s1, s2, h_s1) { length = l; width = w; }
    ~Rectangle() {}
    double Preimeter();
    double Area();
};
class Square :public Rectangle
{
private:
    double sidelength;
public:
    Square(double sl, double l, double w, double s1, double s2, double h_s1) :Rectangle(l, w, s1, s2, h_s1) { sidelength = sl; }
    ~Square() {}
    double Preimeter();
    double Area();
};

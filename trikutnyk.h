#pragma once

struct Point {
    double x, y;
};

struct Triangle {
    Point a, b, c;
};

double distance(Point p1, Point p2);
double perimeter(Triangle& t);
double area(Triangle& t);
Point centroid(Triangle& t);
bool isDegenerate(Triangle& t);
bool isInside(Triangle& t, Point p);
bool isOnEdge(Triangle& t, Point p);
double areaHeron(Triangle& t);

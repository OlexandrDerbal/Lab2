#include "trikutnyk.h"
#include <cmath>
#include <algorithm>

using namespace std;

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


double perimeter(Triangle& t) {
    return distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
}

double area(Triangle& t) {
    return 0.5 * abs((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x - t.a.x) * (t.b.y - t.a.y));
}

Point centroid(Triangle& t) {
    Point c;
    c.x = (t.a.x + t.b.x + t.c.x) / 3.0;
    c.y = (t.a.y + t.b.y + t.c.y) / 3.0;
    return c;
}

bool isDegenerate(Triangle& t) {
    return area(t) == 0;
}

double cross(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isBetween(Point p, Point q, Point r) {
    return min(p.x, q.x) <= r.x && r.x <= max(p.x, q.x) &&
        min(p.y, q.y) <= r.y && r.y <= max(p.y, q.y);
}


bool isOnEdge(Triangle& t, Point p) {
    double eps = 1e-6;
    double total = abs(cross(t.a, t.b, t.c));

    if (total < eps) {
        return (abs(cross(t.a, t.b, p)) < eps && isBetween(t.a, t.b, p)) ||
            (abs(cross(t.b, t.c, p)) < eps && isBetween(t.b, t.c, p)) ||
            (abs(cross(t.c, t.a, p)) < eps && isBetween(t.c, t.a, p));
    }

    double a1 = abs(cross(t.a, t.b, p));
    double a2 = abs(cross(t.b, t.c, p));
    double a3 = abs(cross(t.c, t.a, p));

    return abs((a1 + a2 + a3) - total) < eps &&
        (a1 < eps || a2 < eps || a3 < eps);
}



bool isInside(Triangle& t, Point p) {
    if (isDegenerate(t)) return false;

    double d1 = cross(p, t.a, t.b);
    double d2 = cross(p, t.b, t.c);
    double d3 = cross(p, t.c, t.a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

double areaHeron(Triangle& t) {
    long double a = distance(t.a, t.b);
    long double b = distance(t.b, t.c);
    long double c = distance(t.c, t.a);
    long double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    if (area < 1e-6) area = 0;
    return area;

}



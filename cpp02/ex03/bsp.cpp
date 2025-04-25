#include "Point.hpp"
#include <iostream>
#include <stdio.h>

float my_abs(float value) {
    return (value < 0.0f) ? -value : value;
}

static float getArea(Point const a, Point const b, Point const c) {
    return my_abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
            b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + 
            c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float area = getArea(a, b, c);
    if(area == 0.0f)
        return false;
    float area1 = getArea(point, b, c);
    float area2 = getArea(a, point, c);
    float area3 = getArea(a, b, point);
    printf("area: %f, area1: %f, area2: %f, area3: %f\n", area, area1, area2, area3);

    if(area1 <= 0.0f || area2 <= 0.0f || area3 <= 0.0f)
        return false;
    float sum = area1 + area2 + area3;
    return (area == sum);
}


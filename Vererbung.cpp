#include <iostream>
#include <exception>

// ============================================================

// Der Compiler kann die Sinnhaftigkeit des Einsatzes der Vererbung
// nicht überprüfen :(

class Point
{
    int m_x;
    int m_y;
};

class Line : public Point
{

};

// ============================================================


class Rectangle
{
public:
    int m_left;
    int m_top;
    int m_width;
    int m_height;
};


class ColoredRectangle : public Rectangle
{
public:
    int m_color;
};


int main()
{
   // Rectangle r;
    
    ColoredRectangle cr;
    cr.m_top = 10;
    cr.m_left = 10;
    cr.m_width = 20;
    cr.m_height = 30;
    cr.m_color = 99;

    return 0;
}

// ============================================================

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

// C++ interface
class IUIObject
{
public:
    virtual void draw() = 0;
    virtual void eraseBackground() = 0;
};

class IPersistence
{
public:
    virtual void save() = 0;
    virtual void load() = 0;
};

// ============================================================

// Abstrakte Klasse 
class Rectangle : public IUIObject, public IPersistence
{
private:
    int m_left;
    int m_top;
    int m_width;
    int m_height;

public:
    //Rectangle(int left, int top, int width, int height)
    //{
    //    m_left = left;
    //    m_top = top;
    //    m_width = width;
    //    m_height = height;
    //}

    // oder 

    Rectangle()
        : m_left(1), m_top(1), m_width(1), m_height(1)
    {}

    Rectangle(int left, int top, int width, int height)
        : m_left(left), m_top(top), m_width(width), m_height(height)
    {}

public:
    // public interface
    virtual void eraseBackground() { std::cout << "eraseBackground: Rectangle" << std::endl; }

    virtual void save() {}
    virtual void load() {}
};

class ColoredRectangle : public Rectangle
{
private:
    int m_color;

public:

    ColoredRectangle()
        : Rectangle(), m_color(0)
    { }

    ColoredRectangle(int left, int top, int width, int height, int color) 
        : Rectangle (left, top, width, height), m_color (color)
    { }

public:
    // public interface
    void draw() override  {
        //Rectangle::draw();
        std::cout << "draw: ColoredRectangle" << std::endl;
    }

    //void drawEx() /* override */ {
    //    // Rectangle::draw();
    //    std::cout << "draw: ColoredRectangle" << std::endl;
    //}
};

class TransparentRectangle : public Rectangle
{
private:
    // int m_color;
    int m_opaque;

public:

    TransparentRectangle()
        : Rectangle(), m_opaque(0)
    { }

    TransparentRectangle(int left, int top, int width, int height, int color)
        : Rectangle(left, top, width, height), m_opaque(color)
    { }

public:
    // public interface
    void draw() override  {
        //Rectangle::draw();
        std::cout << "draw: TransparentRectangle" << std::endl;
    }
};

void vererbung01()
{
    // Rectangle r(20, 20, 5, 5);
    ColoredRectangle cr(10, 10, 20, 30, 99);

    // r.draw();
    cr.draw();
}

void vererbung02()
{
    Rectangle* rp;  // 4 Bytes

    ColoredRectangle cr(10, 10, 20, 30, 99);

    rp = &cr;     // Rectangle* = ColoredRectangle* // is-a // ist-ein

    rp->draw();   // i)  "draw: Rectangle", weil rp vom Typ Rectangle* ist
                  // ii) "draw: ColoredRectangle", weil an rp die Adresse von cr zugewiesen wird
                  //     (Adresse eines ColoredRectangle Objekts)
}

void vererbung03()
{
    // Concrete objects
    TransparentRectangle tr1(10, 10, 20, 30, 99);
    TransparentRectangle tr2(10, 10, 20, 30, 99);

    ColoredRectangle cr1(10, 10, 20, 30, 99);
    ColoredRectangle cr2(10, 10, 20, 30, 99);

    // Array
    IUIObject* rects[4] { &tr1, &cr1, &tr2, &cr2 };

    for (int i = 0; i < 4; ++i)
    {
        rects[i]->draw();   // <====  Polymorphismus
    }

    IPersistence* rects2[4]{ &tr1, &cr1, &tr2, &cr2 };

    for (int i = 0; i < 4; ++i)
    {
        rects2[i]->save();   // <====  Polymorphismus
    }
}

int main_vererbung ()
{
    vererbung03();

    return 0;
}

// ============================================================

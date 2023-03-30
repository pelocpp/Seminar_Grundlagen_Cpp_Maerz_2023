#include <iostream>

//class Calculator
//{
//public:
//    static int add(int n, int m) { return n + m; }
//    static int sub(int n, int m) { return n - m; }
//    static int mul(int n, int m) { return n * m; }
//    static int div(int n, int m) { return n / m; }
//};

template <typename T = int>
class Calculator
{
public:
    static T add(T n, T m) {
        return n + m; 
    }
    static T sub(T n, T m) { return n - m; }
    static T mul(T n, T m) { return n * m; }
    static T div(T n, T m) { return n / m; }
};

class DoubleCalculator
{
public:
    static double add(double n, double m) { return n + m; }
    static double sub(double n, double m) { return n - m; }
    static double mul(double n, double m) { return n * m; }
    static double div(double n, double m) { return n / m; }
};

template <typename T = double>
T minimum(T n, T m)
{
    if (n < m) {
        return n;
    }
    else {
        return m;
    }
}

template <typename T, typename U>
T minimumEx(T n, U m)
{
    if (n < m) {
        return n;
    }
    else {
        return m;
    }
}

// ===============================================
// Modern C++
template <typename T, typename U>
auto minimumExEx(T n, U m) -> decltype ( n + m )
{
    if (n < m) {
        return n;
    }
    else {
        return m;
    }
}

template <typename T, typename U>
auto minimumExExEx(T n, U m)
{
    decltype (n+m) result;

    if (n < m) {
        result = n;
    }
    else {
        result = m;
    }

    return result;
}

void main_templates()
{
    int x = 5;
    int y = 6;
    int result;

    result = minimum<int>(x, y);

    result = minimum(y, x);   // Type Deduction  // Typ Ableitung // Typ Herleitung

    auto aresult = minimumExExEx(100l, 333ll);



    // Modern C++
    // XXX result2 = minimum(111ll, 222ll);
}

void main_templates_with_classes ()
{
    int result = Calculator<>::add(3, 4);

    double dresult = Calculator<double>::add(3.3, 4.4);

    std::cout << result << std::endl;
}

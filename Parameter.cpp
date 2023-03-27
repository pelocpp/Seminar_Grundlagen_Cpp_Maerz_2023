#include <iostream>

int g_global = 123;  // Glob. Variable / außerhalb von Methoden

void swap_01(int n, int m)
{
    int tmp;

    tmp = n;
    n = m;
    m = tmp;
}

// A) C
void swap_02(int* n, int* m)
{
    int tmp;

    tmp = *n;     // Wert-von
    *n = *m;      // Wert-von,  Wert-von
    *m = tmp;
}

// B) C++
void swap_03(int& n, int& m)
{
    int tmp;

    tmp = n;   
    n = m;    
    m = tmp;
}

void test_swap()
{
    int x = 5;
    int y = 6;

    printf("x=%d - y=%d\n", x, y);

    swap_01(x, y);

    printf("x=%d - y=%d\n", x, y);

    swap_02(&x, &y);

    printf("x=%d - y=%d\n", x, y);

    swap_03(x, y);

    printf("x=%d - y=%d\n", x, y);
}

void test_pointer_vs_reference()
{
    int x = 5;

    // Zeiger
    int* ip;
    ip = &x;

    // 6 an x zuweisen - OHNE Bezeichner x zu verwenden
    *ip = 6;

    ip = ip + 1;   // Error: +1 wird auf die Adresse angewendet
    *ip = 999;     //    Dieser Speicherplatz gehört NICHT der Anwendung

    // Referenz / Alias
    int& ri = x; 

    // 6 an x zuweisen - OHNE Bezeichner x zu verwenden
    ri = 7;

    ri = ri + 1;  // Passt: das +1 wird auf die referenzierte Var. angewendet !!!
}
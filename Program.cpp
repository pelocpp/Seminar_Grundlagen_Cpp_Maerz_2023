#include <iostream>

#include "Time.h"

void test_swap();
void test_pointer_vs_reference();
void exercise_time();
void testIncrementSpecial();
void test_accounts();
void main_virtual_destructor();
void main_templates();
void stl_13();
void stl_exercise_fibonacci();
void stl_exercise_teufel();
void stl_exercise_teufel_academic_01();
void stl_exercise_teufel_academic_02();
void stl_exercise_teufel_academic_03();

int main()
{
    stl_exercise_teufel_academic_01 ();

    return 0;
}

void main_with_operators()
{
    Time now(10, 8, 0);

    Time nochAuszuhalten(0, 30, 0);

    Time pause = now + nochAuszuhalten;   //  Infix - Notation / Operatoren

    // Nur zur Erläuterung / zum besseren Verständnis (Operator == Methode):
    // Time pause2 = now.operator+ (nochAuszuhalten);

    // Nur zur Erläuterung / zum besseren Verständnis (Operator == glob. Funktion):
    Time pause2 = operator+ (now, nochAuszuhalten);
}



void main_diverses()
{
    testIncrementSpecial();

    Time leer;

    //test_swap();
    test_pointer_vs_reference();
}

// Einsprungpunkt in das Programm
int main_mutable()
{
    printf("Hallo Seminar\n");

    Time now (13, 0, 0);

    Time abstand(4, 0, 0);

    // Variante 1
    now.add(abstand);

    // Variante 2
    //Time end;
    //end = now.add(abstand);

    return 0;
}


int main_01()
{
    printf("Hallo Seminar\n");

    Time now;

    //now.m_hour = 11;
    
    now.setHour(11);
    //now.m_minute = 0;
    //now.m_second = 0;

    now.print();

    Time pause;
    //pause.m_hour = 10;
    //pause.m_minute = 40;
    //pause.m_second = 30;

    pause.print();

    printf("Stunden von now: %d\n", now.getHour());

    Time mittags_pause (12, 0, 0);

    return 0;
}
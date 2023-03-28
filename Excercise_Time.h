// ===========================================================================
// Time.h
// ===========================================================================

#pragma once

#include <iostream>

namespace ExerciseTime {

    class Time
    {
    private:
        int m_seconds;
        int m_minutes;
        int m_hours;

    public:
        // c'tors
        Time();

        Time(int seconds, int minutes, int hours);
        // oder
        //Time(int, int, int);

        Time(int seconds);  // conversion c'tor:    Konvertierung: int -> Time

        Time(const char*);  // conversion c'tor

        // getter // setter
        int getSeconds() const { return m_seconds; };
        int getMinutes() const { return m_minutes; };
        int getHours() const { return m_hours; };

        void setSeconds(int seconds);
        void setMinutes(int minutes);
        void setHours(int hours);

        // public interface
        void reset();
        void add(const Time& other);    //  mutable / veränderbar
        void sub(const Time& other);
        Time diff(const Time& other) const;   //  immutable / unveränderbar
        void increment();
        void decrement();

        // arithmetic operators
        Time operator+ (const Time&) const;
        Time operator- (const Time&) const;

        // arithmetic-assignment operators
        Time operator+= (const Time&);
        Time operator-= (const Time&);
        Time operator+= (int seconds);
        Time operator-= (int seconds);

        // increment/decrement operators (prefix/postfix version)
        friend Time& operator++ (Time&);           // prefix increment
        friend const Time operator++ (Time&, int); // postfix increment
        friend Time& operator-- (Time&);           // prefix decrement
        friend const Time operator-- (Time&, int); // postfix decrement

        // comparison operators
        friend bool operator== (const Time&, const Time&);
        friend bool operator!= (const Time&, const Time&);
        friend bool operator<= (const Time&, const Time&);
        friend bool operator<  (const Time&, const Time&);
        friend bool operator>= (const Time&, const Time&);
        friend bool operator>  (const Time&, const Time&);

        // conversion operator
        operator int();

        // input / output
        friend std::ostream& operator<< (std::ostream&, const Time&);
        friend std::istream& operator>> (std::istream&, Time&);

    private:
        // helper methods
        int timeToSeconds();
        void secondsToTime(int seconds);
    };
}


// ===========================================================================
// End-of-File
// ===========================================================================

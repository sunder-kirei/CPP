#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void display()
    {
        cout << numerator << '/' << denominator << endl;
        return;
    }

    int gcd(int numerator, int denominator)
    {
        while (denominator != 0)
        {
            int temp = numerator % denominator;
            numerator = denominator;
            denominator = temp;
        }
        return numerator;
    }

    void add(fraction const f2)
    {
        int temp = (denominator)*f2.denominator;
        numerator = (numerator * f2.denominator) + (f2.numerator * denominator);
        denominator = temp;
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
        
        return;
    }

    fraction operator+(fraction const &f2)
    {
        int n = (numerator * f2.denominator) + (f2.numerator * denominator);
        int d = (denominator)*f2.denominator;
        int GCD = gcd(n, d);
        n /= GCD;
        d /= GCD;
        fraction f3(n, d);
        return f3;
    }

    void multiply(fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        int temp = gcd(numerator, denominator);
        numerator /= temp;
        denominator *= temp;
        
        return;
    }

    fraction operator*(fraction const &f)
    {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        int GCD = gcd(n, d);
        n /= GCD;
        d /= GCD;
        fraction f3(n, d);
        return f3;
    }

    bool operator==(fraction const &f)
    {
        if ((numerator == f.numerator) && (denominator == f.denominator))
        {
            return true;
        }
        else
            return false;
    }

    fraction &operator++()
    {
        numerator += denominator;
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
        return *this;
    }

    fraction &operator++(int)
    {
        numerator += denominator;
        fraction f(numerator, denominator);
        return f;
    }

    fraction &operator+=(fraction const &f)
    {
        add(f);
        return *this;
    }
};
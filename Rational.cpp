#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            q = 1;
        } else if ((numerator < 0) && (denominator < 0)) {
            p = abs(numerator);
            q = abs(denominator);
        } else if (((numerator < 0) && (denominator > 0)) || 
                  ((numerator > 0) && (denominator < 0))) {
            p = -abs(numerator);
            q = abs(denominator);
        } 

        int gcd = GCD(numerator, denominator);
        numerator = numerator / gcd;
        denominator = denominator / gcd;

        p = numerator;
        q = denominator;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;

    int GCD(int a, int b) {
        int gcd;
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        gcd = a + b;
        return gcd;
    }
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && 
        (lhs.Denominator() == rhs.Denominator())) {
        return true;
    } else {
        return false;
    }
}

Rational operator+(Rational& lhs, Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator-(Rational& lhs, Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator*(Rational& lhs, Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(Rational& lhs, Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}

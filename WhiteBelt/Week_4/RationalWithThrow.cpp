#include <iostream>
#include <exception>
using namespace std;


int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        if (numerator == 0) {
            p = 0;
            q = 1;
        }
        const int gcd = GCD(numerator, denominator);        
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        if (denominator < 0) {
            p = -numerator;
            q = -denominator;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;    
};

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Domain error");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}

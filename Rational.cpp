#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
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
        if (numerator == 0) {
            p = 0;
            q = 1;
        }
        const int gcd = GCD(numerator, denominator);        
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        if ((numerator > 0) && (denominator > 0)) {
            p = numerator;
            q = denominator;
        } else if ((numerator < 0) && (denominator < 0)) {
            p = abs(numerator);
            q = abs(denominator);
        } else if (((numerator < 0) && (denominator > 0)) || 
                   ((numerator > 0) && (denominator < 0))) {
            p = -abs(numerator);
            q = abs(denominator);
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

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && 
        (lhs.Denominator() == rhs.Denominator())) {
        return true;
    } else {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    const auto lhsNum = lhs.Numerator() * rhs.Denominator();
    const auto rhsNum = rhs.Numerator() * lhs.Denominator();
    return lhsNum < rhsNum;
}
 
istream& operator>>(istream& stream, Rational& rational) {
    int numerator, denominator;
    char div;
    stream >> numerator >> div >> denominator;
    if (stream && div == '/') {
        rational = Rational(numerator, denominator);
    } 
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}

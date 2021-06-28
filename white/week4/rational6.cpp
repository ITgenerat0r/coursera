#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <exception>

using namespace std;


class Rational {
public:
  // Rational();
  Rational(int numerator = 0, int denominator = 1){
    if(denominator == 0){
        throw invalid_argument("");
    }
    p = numerator;
    q = denominator;
    Check();
  };

  int Numerator() const{
    return p;
  };
  int Denominator() const{
    return q;
  };

  void setNumerator(int value){
    p = value;
  };
  void setDenominator(int value){
    q = value;
  };

  void Check(){
    if(q<0){
        p *= -1;
        q *= -1;
    }
    if (p == 0){
        q = 1;
    } else {
        int tmp = abs(__gcd(p, q));
        p /= tmp;
        q /= tmp;
    }
  }

private:
  int p;
  int q;
};




Rational operator+ (const Rational& lhs, const Rational& rhs){
    Rational tmp;
    tmp.setNumerator(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator());
    tmp.setDenominator(lhs.Denominator() * rhs.Denominator());
    tmp.Check();
    return tmp;
}

Rational operator- (const Rational& lhs, const Rational& rhs){
    Rational tmp;
    tmp.setNumerator(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator());
    tmp.setDenominator(lhs.Denominator() * rhs.Denominator());
    tmp.Check();
    return tmp;
}

bool operator== (const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() * rhs.Denominator() == rhs.Numerator() * lhs.Denominator()){
        return true;
    }
    return false;
}

bool operator< (const Rational& lhs, const Rational& rhs){
    if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator()){
        return true;
    }
    return false;
}

Rational operator* (const Rational& lhs, const Rational& rhs){
    Rational tmp;
    tmp.setNumerator(lhs.Numerator() * rhs.Numerator());
    tmp.setDenominator(lhs.Denominator() * rhs.Denominator());
    tmp.Check();
    return tmp;
}

Rational operator/ (const Rational& lhs, const Rational& rhs){
    Rational tmp;
    if (rhs.Denominator() * rhs.Numerator() * lhs.Denominator() == 0){
        throw domain_error("");
    }
    tmp.setNumerator(lhs.Numerator() * rhs.Denominator());
    tmp.setDenominator(lhs.Denominator() * rhs.Numerator());
    tmp.Check();
    return tmp;
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational){
    int tmp;
    stream >> tmp;
    rational.setNumerator(tmp);
    stream.ignore(1);
    stream >> tmp;
    rational.setDenominator(tmp);
    return stream;
}



// Комментарии, которые говорят, что именно нужно реализовать в этой программе

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




// int main() {

//     set<Rational> rationals;
//     rationals.insert(Rational(1, 2));
//     rationals.insert(Rational(1, 3));

//     map<Rational, string> name;
//     name[Rational(1, 2)] = "одна вторая";
//     cout << endl;
//     cout << "OK" << endl;
//     return 0;
// }
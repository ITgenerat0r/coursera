#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;


class Rational {
public:
  // Rational();
  Rational(int numerator = 0, int denominator = 1){
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

    set<Rational> rationals;
    rationals.insert(Rational(1, 2));
    rationals.insert(Rational(1, 3));

    map<Rational, string> name;
    name[Rational(1, 2)] = "одна вторая";
    cout << endl;
    cout << "OK" << endl;
    return 0;
}
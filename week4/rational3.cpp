#include <iostream>
#include <algorithm>
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



// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    // int v1, v2;
    // cin >> v1 >> v2;
    const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
    if (r == Rational(2, 3)) {
      cout << "equal";
    }
    cout << endl;
    cout << "OK" << endl;
    return 0;
}
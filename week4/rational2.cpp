#include <iostream>
// #include <algorithm>
#include <sstream>
using namespace std;


int NOD (int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a;
}



class Rational {
public:
  Rational(){
    p = 0;
    q = 1;
  };
  Rational(int numerator, int denominator){
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


  void Check(){
    if(q<0){
        p *= -1;
        q *= -1;
    }
    if (p == 0){
        q = 1;
    } else {
        int tmp = NOD(p, q);
        if (tmp < 0){
            tmp *= -1;
        }
        p /= tmp;
        q /= tmp;
    }
  }



private:
  int p;
  int q;
};




Rational operator+ (const Rational& lhs, const Rational& rhs){
    int tmp_p, tmp_q;
    tmp_p = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    tmp_q = lhs.Denominator() * rhs.Denominator();
    return Rational(tmp_p, tmp_q);
}

Rational operator- (const Rational& lhs, const Rational& rhs){
    int tmp_p, tmp_q;
    tmp_p = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    tmp_q = lhs.Denominator() * rhs.Denominator();
    return Rational(tmp_p, tmp_q);
}

bool operator== (const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() * rhs.Denominator() == rhs.Numerator() * lhs.Denominator()){
        return true;
    }
    return false;
}




// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    // int v1, v2;
    // cin >> v1 >> v2;
    const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
    if (r == Rational(7, 12)) {
      cout << "equal";
    }
    cout << endl;
    cout << "OK" << endl;
    return 0;
}
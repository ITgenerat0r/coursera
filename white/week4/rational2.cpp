#include <iostream>
// #include <algorithm>
#include <sstream>
using namespace std;


int NOD (int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
          a %= b;
        } else {
          b %= a;
        }
    }
    return a+b;
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
    // int tmp_p, tmp_q;
    // tmp_p = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    // tmp_q = lhs.Denominator() * rhs.Denominator();
    // return Rational(tmp_p, tmp_q);
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
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;


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
        int tmp = abs(__gcd(p, q));
        p /= tmp;
        q /= tmp;
    }

  }

private:
  int p;
  int q;
};
// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    int v1, v2;
    cin >> v1 >> v2;
    Rational r(v1, v2);
    cout << r.Numerator() << '/' << r.Denominator() << endl;

    cout << "OK" << endl;
    return 0;
}
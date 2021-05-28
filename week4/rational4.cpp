#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdlib>

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

Rational operator* (const Rational& lhs, const Rational& rhs){
    int tmp_p, tmp_q;
    tmp_p = lhs.Numerator() * rhs.Numerator();
    tmp_q = lhs.Denominator() * rhs.Denominator();
    return Rational(tmp_p, tmp_q);
}

Rational operator/ (const Rational& lhs, const Rational& rhs){
    int tmp_p, tmp_q;
    tmp_p = lhs.Numerator() * rhs.Denominator();
    tmp_q = lhs.Denominator() * rhs.Numerator();
    return Rational(tmp_p, tmp_q);
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}


// int getNum(const string& ss){
//     int r=0;
//     for (const char& i : ss){
//         r *= 10;
//         r+=(int)i - 48;
//     }
//     return r;
// }

// int not_valid(const string& ss){
//     int stage = 0;
//     if (ss == ""){
//         return 1;
//     }
//     for(const char& i : ss){
//         if ((int) i < 48 || (int)i > 57){
//             if (stage != 1){
//                 return 2;
//             }
//             if (i != '/'){
//                 return 3;
//             } else {
//                 stage++;
//             }
//         } else {
//             if (stage == 0){
//                 stage++;
//             } else if (stage == 2){
//                 stage++;
//             }
//         }
//     }
//     if (stage == 3){
//         return 0;
//     } else {
//         return 4;
//     }
// }

istream& operator>> (istream& stream, Rational& rational){
    int tmp_p, tmp_q;
    // cout << "\n1peek() " << stream.peek() << "   " << (char)stream.peek() << endl;
    stream.peek();
    if((stream.peek() > 47) && (stream.peek() < 58)){ 
        stream >> tmp_p;
    } else {
        return stream;
    };

    // cout << "2peek() " << stream.peek() << "   " << (char)stream.peek() << endl;  
    if (stream.peek() != 47){
        return stream;
    };
    stream.ignore(1);
    // cout << "3peek() " << stream.peek() << "   " << (char)stream.peek() << endl << endl;
    if((stream.peek() > 47) && (stream.peek() < 58)){ 
        stream >> tmp_q;
    } else {
        return stream;
    };

    if (stream.peek() == 32){
        stream.ignore(1);
    }
    rational = {tmp_p, tmp_q};

    return stream;
}



// Комментарии, которые говорят, что именно нужно реализовать в этой программе

// int main() {
//     // Набор юнит-тестов для вашей реализации
//     // int v1, v2;
//     // cin >> v1 >> v2;
//     Rational r;
//     cin >> r;
//     cout << r;
//     cout << endl;
//     cout << "OK" << endl;
//     return 0;
// }

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }
    // cout <<"\nLAST TEST\n\n";
    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
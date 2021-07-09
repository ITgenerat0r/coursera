#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
// #include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Rational {
// public:
//   // Р’С‹ РјРѕР¶РµС‚Рµ РІСЃС‚Р°РІР»СЏС‚СЊ СЃСЋРґР° СЂР°Р·Р»РёС‡РЅС‹Рµ СЂРµР°Р»РёР·Р°С†РёРё,
//   // С‡С‚РѕР±С‹ РїСЂРѕРІРµСЂРёС‚СЊ, С‡С‚Рѕ РІР°С€Рё С‚РµСЃС‚С‹ РїСЂРѕРїСѓСЃРєР°СЋС‚ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РєРѕРґ
//   // Рё Р»РѕРІСЏС‚ РЅРµРєРѕСЂСЂРµРєС‚РЅС‹Р№

//   Rational();
//   Rational(int numerator, int denominator) {
//   }

//   int Numerator() const {
//   }

//   int Denominator() const {
//   }
// };

// class Rational {
// public:
//   // Rational();
//   Rational(int numerator = 0, int denominator = 1){
//     if(denominator == 0){
//         throw invalid_argument("");
//     }
//     p = numerator;
//     q = denominator;
//     Check();
//   };

//   int Numerator() const{
//     return p;
//   };
//   int Denominator() const{
//     return q;
//   };

//   void setNumerator(int value){
//     p = value;
//   };
//   void setDenominator(int value){
//     q = value;
//   };

//   void Check(){
//     if(q<0){
//         p *= -1;
//         q *= -1;
//     }
//     if (p == 0){
//         q = 1;
//     } else {
//         int tmp = abs(__gcd(p, q));
//         p /= tmp;
//         q /= tmp;
//     }
//   }

// private:
//   int p;
//   int q;
// };



void Test1(){
  Rational r;
  AssertEqual(r.Numerator(), 0, "test 1");
  AssertEqual(r.Denominator(), 1, "test 2");
  Rational r2(-2,-4);
  AssertEqual(r2.Numerator(), 1, "test 3");
  AssertEqual(r2.Denominator(), 2, "test 4");
  Rational r3(3,-9);
  AssertEqual(r3.Numerator(), -1, "test 5");
  AssertEqual(r3.Denominator(), 3, "test 6");
  Rational r4(-4,9);
  AssertEqual(r4.Numerator(), -4, "test 7");
  AssertEqual(r4.Denominator(), 9, "test 8");
  Rational r5(5, 6);
  AssertEqual(r5.Numerator(), 5, "test 7");
  AssertEqual(r5.Denominator(), 6, "test 8");
}

void Test2(){
  Rational r(0, 7 );
  AssertEqual(r.Numerator(), 0, "test 1");
  AssertEqual(r.Denominator(), 1, "test 2");
}


int main() {
  TestRunner runner;
  runner.RunTest(Test1, "test");
  runner.RunTest(Test2, "test2");
  runner.~TestRunner();
  // РґРѕР±Р°РІСЊС‚Рµ СЃСЋРґР° СЃРІРѕРё С‚РµСЃС‚С‹
  return 0;
}
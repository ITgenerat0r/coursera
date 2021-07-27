#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <sstream>
#include <vector>
#include <iomanip>



using namespace std;

const double PI = 3.14;



class Figure {
public:
  Figure(const string& n) : name(n) {};
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
protected:
  const string name;
};



class Triangle : public Figure {
public:
  Triangle (const int& a, const int& b, const int& c) : Figure("TRIANGLE"), A(a), B(b), C(c) {};
  string Name() const override {
    return name;
  };
  double Perimeter() const override {
    return A + B + C;
  };
  double Area() const override {
    double p = (A + B + C) / 2.0;
    return sqrt(p * (p - A) * (p - B) * (p - C));
  };

private:
  const int A;
  const int B;
  const int C;
};



class Rect : public Figure {
public:
  Rect(const int a, const int b) : Figure("RECT"), A(a), B(b) {};

  string Name() const override {
    return name;
  };
  double Perimeter() const override {
    return (A + B) * 2;
  };
  double Area() const override {
    return A * B;
  };
private:
  const int A;
  const int B;
};



class Circle : public Figure {
public:
  Circle(const int r) : Figure("CIRCLE"), R(r) {};
  string Name() const override {
    return name;
  };
  double Perimeter() const override {
    return 2 * PI * R;
  };
  double Area() const override {
    return R * R * PI;
  };
public:
  const int R;
};





shared_ptr<Figure> CreateFigure(istringstream& is){
  string name;
  is >> name;
  shared_ptr<Figure> res;
  if (name == "TRIANGLE"){
    int a, b, c;
    is >> a >> b >> c;
    res = make_shared<Triangle>(a, b, c);
  } else if (name == "RECT"){
    int a, b;
    is >> a >> b;
    res = make_shared<Rect>(a, b);
  } else if (name == "CIRCLE"){
    int r;
    is >> r;
    res = make_shared<Circle>(r);
  }
  return res;
}




int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
#pragma once



#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s);

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s);

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {});

void Assert(bool b, const std::string& hint);

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name);

  ~TestRunner();

private:
  int fail_count = 0;
};
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// string AskTimeServer () {
//     // ???
//     // throw runtime_error("exit");
//     // return "12:12:12";
// }


class TimeServer {
public:
    string GetCurrentTime () {
      try {
          last_fetched_time = AskTimeServer();
      }
      catch(const std::system_error& ){}
      return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

// int main () {
//     TimeServer ts;
//     try {
//         cout << ts.GetCurrentTime() << endl;
//     } catch (exception& e) {
//         cout << "Get exception: " << e.what() << endl;
//     }
//     return 0;
// }
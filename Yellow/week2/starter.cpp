#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

using Storage = map<string, vector<string>>;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚Сѓ С„СѓРЅРєС†РёСЋ
  string operation_code;
  cin >> operation_code;
  if(operation_code == "NEW_BUS"){
      q.type = QueryType::NewBus;
      cin >> q.bus;
      int stop_count;
      cin >> stop_count;
      q.stops.resize(stop_count);
      for (string& stop : q.stops) {
        cin >> stop;
      }
    } else if (operation_code == "BUSES_FOR_STOP"){
      q.type = QueryType::BusesForStop;
      cin >> q.stop;
    } else if (operation_code == "STOPS_FOR_BUS"){
      q.type = QueryType::StopsForBus;
      cin >> q.bus;
    } else if(operation_code == "ALL_BUSES"){
      q.type = QueryType::AllBuses;
    }
  
  return is;
}

struct BusesForStopResponse {
  // РќР°РїРѕР»РЅРёС‚Рµ РїРѕР»СЏРјРё СЌС‚Сѓ СЃС‚СЂСѓРєС‚СѓСЂСѓ
  string stop;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚Сѓ С„СѓРЅРєС†РёСЋ
  return os;
}

struct StopsForBusResponse {
  // РќР°РїРѕР»РЅРёС‚Рµ РїРѕР»СЏРјРё СЌС‚Сѓ СЃС‚СЂСѓРєС‚СѓСЂСѓ
  string bus;
  vector<string> stops_v;
  Storage stops_m;

};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚Сѓ С„СѓРЅРєС†РёСЋ
  return os;
}

struct AllBusesResponse {
  // РќР°РїРѕР»РЅРёС‚Рµ РїРѕР»СЏРјРё СЌС‚Сѓ СЃС‚СЂСѓРєС‚СѓСЂСѓ
  Storage buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚Сѓ С„СѓРЅРєС†РёСЋ
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
    BusesForStopResponse r;
    r.stop = stop;
    r.buses = stops_to_buses.at(stop);
    return r;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
    StopsForBusResponse r;
    r.bus = bus;
    for(const string& stop : buses_to_stops.at(bus)){
      r.stops_v.push_back(stop);
      r.stops_m[stop] = stops_to_buses.at(stop);
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
    AllBusesResponse r;
    r.buses = buses_to_stops;
    return r;
  }
private:
  Storage buses_to_stops, stops_to_buses;
};

// РќРµ РјРµРЅСЏСЏ С‚РµР»Р° С„СѓРЅРєС†РёРё main, СЂРµР°Р»РёР·СѓР№С‚Рµ С„СѓРЅРєС†РёРё Рё РєР»Р°СЃСЃС‹ РІС‹С€Рµ

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
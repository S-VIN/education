#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

enum class QueryType { NewBus, BusesForStop, StopsForBus, AllBuses };

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream &operator>>(istream &is, Query &q) {
  q.bus = "empty";
  q.stop = "empty";
  q.stops.clear();
  string operation_code;
  is >> operation_code;
  if (operation_code == "NEW_BUS"){
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count = 0;
    is >> stop_count;
    for(int i = 0; i < stop_count; i++){
      string stop;
      is >> stop;
      q.stops.push_back(stop);
    }
  }
  if(operation_code == "BUSES_FOR_STOP"){
    q.type = QueryType::BusesForStop;
    is >> q.bus;
    is >> q.stop;
  }
  if (operation_code == "STOPS_FOR_BUS"){
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  if (operation_code == "ALL_BUSES"){
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse {
  bool error = false;
  string stop;
  vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
  if(r.error){
    cout << "No stop" << endl;
    return os;
  } 
  cout << r.stop << ": ";
  for(auto item : r.buses){
    cout << item << ' ';
  }
  return os;
}

struct StopsForBusResponse {
  bool error = false;
  string bus;
  vector<string> stops;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
  if(r.error){
    cout << "No bus" << endl;
    return os;
  } 
  cout << r.bus << ": ";
  for(auto item : r.stops){
    cout << item << ' ';
  }
  return os;
}

struct AllBusesResponse {
  bool error = false;
  map<string, vector<string>> buses_to_stops;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r) {
  if(r.error){
    cout << "No bus" << endl;
    return os;
  } 
  for(auto item : r.buses_to_stops){
    cout << item.first << ": ";
    for(auto stop : item.second){
      cout << stop << " ";
    }
    cout << endl;
  }

  return os;
}

class BusManager {
public:
  void AddBus(const string &bus, const vector<string> &stops) {
      buses_to_stops[bus] = stops;
      for (auto stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string &stop) {
    BusesForStopResponse output;
    if(!buses_to_stops.at(stop)){
      output.error = true;
    }
    output.stop = stop;
    output.buses = buses_to_stops[stop];
    return output;
  }

  StopsForBusResponse GetStopsForBus(const string &bus) {
    StopsForBusResponse output;
    if(!stops_to_buses.at(bus)){
      output.error = true;
    }
    output.bus = bus;
    output.stops = stops_to_buses[bus];
    return output;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse output;
    if(! (buses_to_stops.size() == 0)){
      output.error = true;
    }
    output.buses_to_stops = buses_to_stops;
    return output;
  }

private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};


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

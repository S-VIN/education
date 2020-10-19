#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

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

istream &operator>>(istream &is, Query &q) {
    string inputCommand;
    is >> inputCommand;
    if (inputCommand == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string &stop : q.stops) {
            is >> stop;
        }
        q.stop = "";
    } else if (inputCommand == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (inputCommand == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (inputCommand == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    int error;
    string stop;
    vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
    if(r.error == 1){
        os << "No stop";
        return os;
    }
    for(const auto& bus: r.buses){
        os << bus << " ";
    }
    return os;
}

struct StopsForBusResponse {
    int error;
    string bus;
    map<string, vector<string>> stops_for_buses;
    map<string, vector<string>> buses_for_stops;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
    if(r.error == 1){
        os << "No bus";
        return os;
    }

    for(const auto& stop : r.stops_for_buses.at(r.bus)){
        cout << "Stop " << stop << ": ";
        if (r.buses_for_stops.at(stop).size() == 1) {
            cout << "no interchange";
        } else {
            for (const auto& other_bus : r.buses_for_stops.at(stop)) {
                if (r.bus != other_bus) {
                    cout << other_bus << " ";
                }
            }
        }
        cout << endl;
    }
    return os;
}

struct AllBusesResponse {
    int error;
    map<string, vector<string>> stopsForBuses;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r) {
    if(r.error == 1){
        os << "No buses";
        return os;
    }
    for (auto item : r.stopsForBuses) {
        os << "Bus " << item.first << ": ";
        for (auto stop : item.second) {
            os << stop << " ";
        }
        os << endl;
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string &bus, const vector<string> &stops) {
        stops_for_buses[bus] = stops;
        for (const auto& stop: stops) {
            buses_for_stops[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const {
        int error = 0;
        if(buses_for_stops.count(stop) == 0){
            error = 1;
        }
        if(error == 0){
            return {error, stop, buses_for_stops.at(stop)};
        }
        return {error, stop, {}};
    }

    StopsForBusResponse GetStopsForBus(const string &bus) const {
        int error = 0;
        if(stops_for_buses.count(bus) == 0){
            error = 1;
        }
        if(error == 0){
            return {error, bus, stops_for_buses, buses_for_stops};
        }
        return {error, bus, {}};
    }

    AllBusesResponse GetAllBuses() const {
        int error = 0;
        if(stops_for_buses.empty()){
            error = 1;
        }
        if(error == 0){
            return {error, stops_for_buses};
        }
        return {error, {}};
    }


private:
    map<string, vector<string>> buses_for_stops, stops_for_buses;
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
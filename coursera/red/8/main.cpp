#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <set>

using namespace std;

struct Deal{
    int64_t time;
    string hotelName;
    uint64_t clientID;
    int roomCount;
};

class HotelManager{
public:
    void out(){
        cout << endl << endl;


        /*for(auto item : allDeals){
            cout << "--" << item.hotelName << " " << item.time << endl;
        }*/

        for(auto temp : clientsNumber) {
            for (auto item: temp.second) {
                cout << temp.first << ":" << item.first << "---" << item.second << endl;
            }
        }

        cout << endl << endl;
    }

    void book(int64_t time, string hotelName, uint32_t clientID, int roomCount){
        allDeals.push_back({time, hotelName, clientID, roomCount});

        clientsNumber[hotelName][clientID]++;

        roomsStatistic[hotelName] += roomCount;

        while(allDeals[0].time + 86400 <= allDeals[allDeals.size() - 1].time){

            clientsNumber[allDeals[0].hotelName][allDeals[0].clientID]--;
            if(clientsNumber[allDeals[0].hotelName][allDeals[0].clientID] == 0){
                clientsNumber[allDeals[0].hotelName].erase(allDeals[0].clientID);
            }
            roomsStatistic[allDeals[0].hotelName] -= allDeals[0].roomCount;
            allDeals.pop_front();
        }
        //out();
    }

    uint32_t clients(string hotelName){
        /*
        set<uint32_t> result;
        for(auto item : allDeals){
            if(item.hotelName == hotelName)
            result.insert(item.clientID);
        }
        return result.size();
        */
        //out();
        return clientsNumber[hotelName].size();
    }

    int rooms(string hotelName){
        //out();
        return roomsStatistic[hotelName];
    }

private:
    deque<Deal> allDeals;
    map<string, int> roomsStatistic;
    map<string, map<uint64_t, int>> clientsNumber;
};

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        HotelManager manager;

        int query_count;
        cin >> query_count;

        for (int query_id = 0; query_id < query_count; ++query_id) {
            string query_type;
            cin >> query_type;

            if (query_type == "BOOK") {
                int64_t time;
                string hotelName;
                uint64_t clientID;
                int roomCount;
                cin >> time >> hotelName >> clientID >> roomCount;
                manager.book(time, hotelName, clientID, roomCount);
            } else if (query_type == "CLIENTS") {
                string hotelName;
                cin >> hotelName;
                cout << manager.clients(hotelName) << endl;
            }else if (query_type == "ROOMS") {
                string hotelName;
                cin >> hotelName;
                cout << manager.rooms(hotelName) << endl;
            }
        }

        return 0;
}

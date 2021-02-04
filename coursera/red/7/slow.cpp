#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <map>

using namespace std;

class ReadingManager {
private:
    static const int MAX_USER_COUNT_ = 100'000;
    map<int, int> userPageCount;
    vector<int> countOfReaders = vector<int>(1000, 0);

public:

    void Read(int user_id, int page_count) {
        if (userPageCount.find(user_id) == userPageCount.end()) {
            countOfReaders[page_count]++;
        } else {
            countOfReaders[userPageCount[user_id]]--;
            countOfReaders[page_count]++;
        }
        userPageCount[user_id] = page_count;
    }

    double Cheer(int user_id) const {
        if (userPageCount.end() == userPageCount.find(user_id)) {
            return 0;
        }
        if(userPageCount.size() == 1){
            return 1;
        }
        int page = userPageCount.at(user_id);
        int sumOfWorseReaders = 0;
        for (int i = 0; i < page; i++) {
            sumOfWorseReaders += countOfReaders[i];
        }
        return (sumOfWorseReaders * 1.0) / (userPageCount.size() - 1);
    }



};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
      string query_type;
      cin >> query_type;
      int user_id;
      cin >> user_id;

      if (query_type == "READ") {
        int page_count;
        cin >> page_count;
        manager.Read(user_id, page_count);
      } else if (query_type == "CHEER") {
        cout << setprecision(6) << manager.Cheer(user_id) << "\n";
      }
    }

    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stringstream input("12\n"
                       "CHEER 5\n"
                       "READ 1 10\n"
                       "CHEER 1\n"
                       "READ 2 5\n"
                       "READ 3 7\n"
                       "CHEER 2\n"
                       "CHEER 3\n"
                       "READ 3 10\n"
                       "CHEER 3\n"
                       "READ 3 11\n"
                       "CHEER 3\n"
                       "CHEER 1");
    vector<string> output;
    vector<string> rightOutput{"0.000000", "1.000000", "0.000000", "0.500000", "0.500000", "1.000000", "0.500000"};
    ReadingManager manager;

    int query_count;
    input >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        input >> query_type;
        int user_id;
        input >> user_id;

        if (query_type == "READ") {
            int page_count;
            input >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            //cout << setprecision(6) << manager.Cheer(user_id);
            output.push_back(to_string(manager.Cheer(user_id)));
        }

    }

    for (int i = 0; i < output.size(); i++) {
        if (output[i] == rightOutput[i]) {
            cout << output[i] << " " << rightOutput[i] << endl;
        } else {
            cout << output[i] << " " << rightOutput[i] << endl;
        }
    }*/

    return 0;
}
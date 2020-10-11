#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class Date {
public:
  int year;
  int month;
  int day;
};

ostream &operator<<(ostream &stream, const Date date) {
  stream << setfill('0') << setw(4) << date.year << '-' << setw(2) << date.month
         << '-' << setw(2) << date.day;
  return stream;
}

bool operator<(const Date &lhs, const Date &rhs) {
  if (lhs.year != rhs.year) {
    return lhs.year < rhs.year;
  } else if (lhs.month != rhs.month) {
    return lhs.month < rhs.month;
  }
  return lhs.day < rhs.day;
}

class Database {
public:
  void step() {
    string line;
    getline(cin, line);
    if (line == "")
      return;
    string command;
    Date date;
    string action;
    parseLine(line, command, date, action);
    // cout << command << ' ' << date << ' ' << action << '+';
    doCommand(command, date, action);
  }

private:
  map<Date, set<string>> data;

  void doCommand(string commandStr, Date date, string action = "") {
    try {
      if (commandStr == "Add") {
        addEvent(date, action);
      } else if (commandStr == "Print") {
        print();
      } else if (commandStr == "Del") {
        deleteEvent(date, action);
      } else if (commandStr == "Find") {
        find(date);
      } else {
        cout << "Unknown command: " << commandStr << endl;
        exit(0);
      }

    } catch (out_of_range &ex) {
      cout << ex.what() << endl;
      exit(0);
    }
  }

  void parseLine(string &line, string &commandStr, Date &date,
                 string &eventStr) {
    string dateStr;
    stringstream input(line);
    input >> commandStr;

    if (!(input >> dateStr)) {
      return;
    }

    date = parseDate(dateStr);
  }

  void addEvent(Date &date, string &action) { data[date].insert(action); }

  void find(const Date &date) {
    for(auto item: data[date]){
      cout << item << endl;
    }
  }

  void deleteEvent(const Date &date) {
    cout << "Deleted " << data[date].size() << " events" << endl;
    data.erase(date);
  }

  void deleteEvent(const Date &date, string action) {
    if (action == "") {
      deleteEvent(date);
      return;
    }
    if (data[date].find(action) != data[date].end()) {
      data[date].erase(action);
      cout << "Deleted successfully" << endl;
    } else {
      cout << "Event not found" << endl;
    }
  }

  void print() const {
    for (auto item : data) {
      for (auto action : item.second)
        cout << item.first << ' ' << action << endl;
    }
  }

  Date parseDate(string &str) {
    if (!checkDate(str)) {
      cout << "Wrong date format: " << str << endl;
      exit(0);
    }

    try {
      stringstream input(str);
      Date date;
      char def1, def2;
      input >> date.year >> def1 >> date.month >> def2;
      if (!(input >> date.day) || (input.peek() != EOF)) {
        cout << "Wrong date format: " << str << endl;
        exit(0);
      }

      if (date.month < 1 || date.month > 12) {
        string error = "Month value is invalid: " + to_string(date.month);
        cout << error;
        exit(0);
      }
      if (date.day < 1 || date.day > 31) {
        string error = "Day value is invalid: " + to_string(date.day);
        cout << error;
        exit(0);
      }
      return date;

    } catch (invalid_argument &ex) {
      cout << "Wrong date format: " << str << endl;
      exit(0);
    }
  }

  bool checkDate(const string &str) {
    string validChar = "1234567890-+ ";
    for (auto item : str) {
      if (!(validChar.find(item) != std::string::npos)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Database db;

  string command;
  while (cin) {
    db.step();
  }

  return 0;
}
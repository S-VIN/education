#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>

using namespace std;

bool operator<(const Date &d1, const Date &d2) {
    if (d1.year == d2.year) {
        if (d1.month == d2.month) {
            return d1.day < d2.day;
        } else {
            return d1.month < d2.month;
        }
    } else {
        return d1.year < d2.year;
    }
}

bool operator==(const Date &d1, const Date &d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator==(const Time &t1, const Time &t2) {
    return t1.hours == t2.hours && t1.minutes == t2.minutes;
}

bool operator<(const Time t1, const Time t2) {
    if (t1.hours == t2.hours) {
        return t1.minutes < t2.minutes;
    } else {
        return t1.hours < t2.hours;
    }
}

ostream &operator<<(ostream &os, const Time &t) {
    os << t.hours << " " << t.minutes;
    return os;
}

ostream &operator<<(ostream &os, const Date &d) {
    os << d.year << " " << d.month << " " << d.day;
    return os;
}

istream &operator>>(istream &is, Time &t) {
    is>>t.hours;
    is.ignore(1);
    is>>t.minutes;
    is.ignore(1);

    return is;
}

istream &operator>>(istream &is, Date &d) {
    is>> d.year;
    is.ignore(1);
    is>> d.month;
    is.ignore(1);
    is>> d.day;
    is.ignore(1);
    return is;
}


#define UPDATE_FIELD(ticket, field, values)  \
    if (values.find(#field) != values.end()) {                \
       istringstream is(values.find(#field)->second);         \
       is >> ticket.field;                   \
    }


void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
            {"departure_date", "2018-2-28"},
            {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
            {"price",        "12550"},
            {"arrival_time", "20:33"},
    };

    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}


/*
void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {
  map<string, string>::const_iterator it;

  it = updates.find("to");
  if (it != updates.end()) {
    ticket.to = it->second;
  }

  it = updates.find("from");
  if (it != updates.end()) {
    ticket.from = it->second;
  }

  it = updates.find("price");
  if (it != updates.end()) {
    istringstream is(it->second);
    is >> ticket.price;
  }

  ...
}
 */
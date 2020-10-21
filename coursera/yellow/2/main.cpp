#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

/*
class Rational {
public:

    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        p = numerator;
        q = denominator;
        sights();
        reduction();
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    void sights() {
        if ((p < 0 && q < 0) || (p > 0 && q < 0)) {
            p *= -1;
            q *= -1;
        }
        if (p == 0) {
            q = 1;
        }
    }

    void reduction() {
        bool firstS, secondS;
        firstS = (p >= 0);
        secondS = (q >= 0);
        p = abs(p);
        q = abs(q);
        int nod, a = p, b = q;
        while (b > 0 && a > 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        nod = a;
        if (nod > 0) {
            p /= nod;
            q /= nod;
        }
        if(!firstS){
            p*=-1;
        }
        if(!secondS){
            q*=-1;
        }
    }

    int p;
    int q;
};
*/

/*
class Rationaly {
public:

    Rationaly() {
        p = 0;
        q = 1;
    }

    Rationaly(int numerator, int denominator) {
        p = numerator;
        q = denominator;
        sights();
        reduction();
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    void sights() {
        if ((p < 0 && q < 0) || (p > 0 && q < 0)) {
            p *= -1;
            q *= -1;
        }
        if (p == 0) {
            q = 1;
        }
    }

    void reduction() {
        bool firstS, secondS;
        firstS = (p >= 0);
        secondS = (q >= 0);
        p = abs(p);
        q = abs(q);
        int nod, a = p, b = q;
        while (b > 0 && a > 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        nod = a;
        if (nod > 0) {
            p /= nod;
            q /= nod;
        }
        if(!firstS){
            p*=-1;
        }
        if(!secondS){
            q*=-1;
        }
    }

    int p;
    int q;
};*/


void TestGram() {
    AssertEqual(Rational(1, 2).Numerator(), 1, "");
    AssertEqual(Rational(1, 2).Denominator(), 2, "");

    AssertEqual(Rational().Numerator(), 0, "");
    AssertEqual(Rational().Denominator(), 1, "");

    AssertEqual(Rational(-2, -3).Numerator(), 2, "");
    AssertEqual(Rational(-2, -3).Denominator(), 3, "");

    AssertEqual(Rational(4, -6).Numerator(), -2, "");
    AssertEqual(Rational(4, -6).Denominator(), 3, "");

    AssertEqual(Rational(0, -64).Numerator(), 0, "");
    AssertEqual(Rational(0, -64).Denominator(), 1, "");

    AssertEqual(Rational(0, -64).Numerator(), 0, "");
    AssertEqual(Rational(0, -64).Denominator(), 1, "");

    /*for(int i = -1000; i <= 1000; i++){
        for(int j = -1000; j <= 1000; j++){
            AssertEqual(Rational(i, j).Numerator(), Rationaly(i, j).Numerator(), "");
            AssertEqual(Rational(i, j).Denominator(), Rationaly(i, j).Denominator(), "");
        }
    }*/



}

int main() {
    TestRunner runner;
    runner.RunTest(TestGram, "Testgram");

    return 0;
}

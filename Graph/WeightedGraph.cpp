#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    map<char, vector<pair<char, int>>> adj;

    // A --2-- B
    adj['A'].push_back({'B', 2});
    adj['B'].push_back({'A', 2});

    // A --7-- C
    adj['A'].push_back({'C', 7});
    adj['C'].push_back({'A', 7});

    // B --4-- D
    adj['B'].push_back({'D', 4});
    adj['D'].push_back({'B', 4});

    // C --1-- D
    adj['C'].push_back({'D', 1});
    adj['D'].push_back({'C', 1});

    // Print
    for(auto x : adj) {

        cout << x.first << " -> ";

        for(auto y : x.second) {

            cout << "(" << y.first
                 << "," << y.second << ") ";
        }

        cout << endl;
    }

    return 0;
}

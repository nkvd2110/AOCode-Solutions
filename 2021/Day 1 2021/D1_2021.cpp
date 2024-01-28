#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fi("input.txt");
    vector <int> a;
    int count = 0;

    for (int i = 0; i < 2000; i++) {
        int x;
        fi >> x;
        a.push_back(x);
    }

    for (int i = 1; i < 2000; i++) {
        if (a[i] > a[i - 1]) {
            count++;
        }
    }

    // cout << a[2000 - 1] << endl;
    cout << count << endl;
    fi.close();
    return 0;
}
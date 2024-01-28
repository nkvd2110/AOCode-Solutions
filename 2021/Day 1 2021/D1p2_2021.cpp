#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fi("input.txt");
    vector <int> a;
    vector <int> b;
    int count = 0;

    for (int i = 0; i < 2000; i++) {
        int x;
        fi >> x;
        a.push_back(x);
    }

    for (int i = 0; i < 2000; i++) {
        int temp;
        temp = a[i] + a[i + 1] + a[i + 2];
        b.push_back(temp);
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] > b[i - 1]) {
            count++;
        }
    }

    // cout << a[2000 - 1] << endl;
    cout << count << endl;
    fi.close();
    return 0;
}
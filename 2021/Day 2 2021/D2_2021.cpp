#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main() {

    ifstream fi;
    
    vector <string> move = {};
    vector <int> movenum = {};

    int forward_num = 0;
    int dept_num = 0;

    fi.open("input.txt");

    for (int i = 0; i < 2000; i++) {
        string s;
        fi >> s;
        if ( isdigit(s[0]) == false ){
            move.push_back(s);
        }
        else {
            movenum.push_back(stoi(s));
        }
    }
    

    // cout << move[1] << endl;
    // cout << movenum[1] << endl;

    for (int i = 0; i < move.size(); i++) {
        if (move[i] == "forward") {
            forward_num += movenum[i];
        }
        else if (move[i] == "up") {
            dept_num -= movenum[i];
        }
        else if (move[i] == "down") {
            dept_num += movenum[i];
        }
    }

    cout << "forward: " << forward_num << endl;
    cout << "dept: " << dept_num << endl;

    int mul = forward_num * dept_num;
    cout << "mul: " << mul << endl;
    fi.close();


    return 0;
}

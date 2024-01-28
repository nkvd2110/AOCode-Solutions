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
    
    int aim = 0;
    int forward_num = 0;
    int depth_num = 0;

    for (int i = 0; i < move.size(); i++) {
        if (move[i] == "forward") {
            forward_num += movenum[i];
            depth_num += movenum[i] * aim;
        }
        else if (move[i] == "up") {
            aim -= movenum[i];
        }
        else if (move[i] == "down") {
            aim += movenum[i];
        }
    }
   
   cout << "forward: " << forward_num << endl;
   cout << "depth: " << depth_num << endl;

   int result = forward_num * depth_num;
   cout << result << endl;


    fi.close();
    return 0;
}

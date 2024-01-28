#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
//53651

// int dummyF(){
//     return 0;
// }

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    vector<string> input = {};
    for (string line; getline(inFile, line);){
        input.push_back(line);
    }
    cout << input[100] << endl;

    
    int sum = 0;
    vector<int> elementInt = {};
    // input.size()
    for (int i = 0; i < input.size(); i++){
        int firstDigit = 0;
        int secondDigit = 0;
        int take1 = 0;
        for (int j = 0; j < input[i].size(); j++){
            if ((input[i][j] - 0) <= 57 && (input[i][j] - 0) >= 48 ){
                firstDigit = int(input[i][j]) - int('0');
                take1 = j;
                break;
            }
        }
        for (int j = input[i].size(); j >= take1; j--){
            if ((input[i][j] - 0) <= 57 && (input[i][j] - 0) >= 48 ){
                secondDigit = int(input[i][j]) - int('0');
                break;
            }
        }
        cout << firstDigit << " " << secondDigit << endl;
        
    
        sum += firstDigit * 10 + secondDigit;
        
    }
    cout << sum << endl;
    inFile.close();
}
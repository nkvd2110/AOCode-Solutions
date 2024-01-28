#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void isSubstring(string s1, string s2, vector<int>& vt, vector<int>& vt2, int indexE)
{
    int index = 0;
    while ((index = s2.find(s1, index)) != string::npos) {
        vt.push_back(index);
        vt2.push_back(indexE+1);
        index += s1.length();
    }
}



int main() {
    ifstream inFile;
    inFile.open("input.txt");
    vector<string> input = {};
    for (string line; getline(inFile, line);) {
        input.push_back(line);
    }

    int sum = 0;
    string element[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 1000; i++) {
        cout << input[i] << endl;
        int firstDigit = 0;
        int secondDigit = 0;
        string test = "";
        // vector<string> elementString = {};
        vector<int> elementStringValue;
        vector<int> elementFirstIndex = {};
        vector<int> intIndex = {};
        vector<int> elementInt = {};
        for (int j = 0; j < input[i].size(); j++) {
            if ((input[i][j] - 0) <= 57 && (input[i][j] - 0) >= 48) {
                elementInt.push_back((int(input[i][j]) - int('0')));
                intIndex.push_back(j);
            }
        }
        for (int k = 0; k < 9; k++) {
            isSubstring(element[k], input[i], elementFirstIndex, elementStringValue, k);
        }

        // if (elementStringValue.empty()) {
        //     cout << "Empty";
        // }
        // else {
        //     for (int k = 0; k < elementStringValue.size(); k++) {
        //         cout << elementStringValue[k] << " ";
        //     }
        // }
        

        if (elementStringValue.empty() && elementFirstIndex.empty()) {
            firstDigit = elementInt[0];
            secondDigit = elementInt[intIndex.size() - 1];
        }
        else {
            int minIndex = 0;
            int maxIndex = 0;
            for (int l = 0; l < elementFirstIndex.size(); l++) {
                if (elementFirstIndex[l] < elementFirstIndex[minIndex]) {
                    minIndex = l;
                }
                if (elementFirstIndex[l] > elementFirstIndex[maxIndex]) {
                    maxIndex = l;
                }
            }
            if (elementFirstIndex[minIndex] < intIndex[0]) {
                firstDigit = elementStringValue[minIndex];
            }
            else {
                firstDigit = elementInt[0];
            }
            if (elementFirstIndex[maxIndex] > intIndex[intIndex.size() - 1]) {
                secondDigit = elementStringValue[maxIndex];
            }
            else {
                secondDigit = elementInt[intIndex.size() - 1];
            }
        }
        // cout << endl;
        cout << firstDigit << endl;
        cout << secondDigit << endl;
        sum += firstDigit * 10 + secondDigit;
    }
    cout << sum << endl;
    inFile.close();
}
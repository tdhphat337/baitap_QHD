#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool isValid(string &currentNumber, string &lowerBound) {
    int n=currentNumber.size();
    for (int i=0;i<n;i++) {
        if (currentNumber[i]<lowerBound[i])return false;
        else if(currentNumber[i]>lowerBound[i])return true;
    }return true;
}
string findNumber(string &digits, string &lowerBound) {
    int n=digits.size();
    string currentNumber=digits.substr(0, 1);
    for (int i=1;i<n;i++) {
        string tempNumber=digits[i]+currentNumber;
        if (isValid(tempNumber, lowerBound))currentNumber=tempNumber;
        else currentNumber+=digits[i];
    }
    if (isValid(currentNumber, lowerBound))return currentNumber;
    else {
        string tempNumber = digits[n - 1] + currentNumber;
        if (isValid(tempNumber, lowerBound)) {
            currentNumber = tempNumber;
            return currentNumber;
        } else return "-1";
    }
}

int main() {
    freopen("LRGAME.INP", "r", stdin);
    freopen("LRGAME.OUT", "w", stdout);
    string digits, lowerBound;cin>>digits>>lowerBound;
    string result=findNumber(digits, lowerBound);
    cout<<result;
    return 0;
}


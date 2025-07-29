#include<bits/stdc++.h>

using namespace std ; 

std::string decimalToBinary(int decimalNum) {
    if (decimalNum == 0) {
        return "0"; 
    }

    string binaryString = "";
    while (decimalNum > 0) {
        int remainder = decimalNum % 2;
        binaryString += to_string(remainder);
        decimalNum /= 2;
    }

    reverse(binaryString.begin(), binaryString.end()); 
    return binaryString;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    string binaryResult = decimalToBinary(number);
    cout << "The binary equivalent of " << number << " is: " << binaryResult << std::endl;

    return 0;
}
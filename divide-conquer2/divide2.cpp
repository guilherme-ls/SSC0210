#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

string add_bin(string bin1, string bin2) {
    string result;
    bool carry = false;

    while(bin1.length() > bin2.length()) bin2 = "0" + bin2;
    while(bin1.length() < bin2.length()) bin1 = "0" + bin1;

    for(int i = bin1.length() - 1; i >= 0; i--) {
        if(bin1[i] == bin2[i]) {
            result = to_string(carry) + result;
            carry = (bin1[i] - '0');
        }
        else {
            result = to_string(!carry) + result;
        }
    }
    if(carry)
        result = "1" + result;

    return result;
}

string sub_bin(string bin1, string bin2) {
    string temp;

    while(bin1.length() > bin2.length()) bin2 = "0" + bin2;
    while(bin1.length() < bin2.length()) bin1 = "0" + bin1;

    string result = bin2;
    int n = bin2.length();

    for(int i = 0; i < n; i++) {
        temp = temp + "0";
        if(result[i] == '0')
            result[i] = '1';
        else
            result[i] = '0';
    }
    temp[n-1] = '1';
    
    result = add_bin(result, temp);
    result = add_bin(bin1, result);
    result = result.substr(1, n);

    return result;
}

string mult_bin(string bin1, string bin2) {
    string result;
    
    while(bin1.length() > bin2.length()) bin2 = "0" + bin2;
    while(bin1.length() < bin2.length()) bin1 = "0" + bin1;
    
    int n = bin2.length();

    for(int i = n - 1; i >= 0; i--) result += "0";

    for(int i = n - 1; i >= 0; i--) {
        if(bin2[i] == '1') {
            result = add_bin(result, bin1);
        }
        bin1 += "0";
    }

    return result;
}

string shift(string bin, int shift) {
    for(int i = 0; i < shift; i++) {
        bin += '0';
    }
    return bin;
}

string Karatsuba(string bin1, string bin2) {
    while(bin1.length() > bin2.length()) bin2 = "0" + bin2;
    while(bin1.length() < bin2.length()) bin1 = "0" + bin1;
    int n = bin2.length();

    string bin1L = bin1.substr(0, n/2);
    string bin1R = bin1.substr(n/2, n);

    string bin2L = bin2.substr(0, n/2);
    string bin2R = bin2.substr(n/2, n);

    string part1;
    string part2;
    string part3;
    string result;

    if(n%2 == 0 && (n/2)%2 == 0) {
        part1 = Karatsuba(bin1L, bin2L);
        part2 = Karatsuba(bin1R, bin2R);
        part3 = Karatsuba(add_bin(bin1L, bin1R), add_bin(bin2L, bin2R));
        result = add_bin(shift(part1, 2 * (n-(n/2))), add_bin(shift(sub_bin(part3, add_bin(part1, part2)), n-(n/2)), part2));
    }
    else {
        part1 = mult_bin(bin1L, bin2L);
        part2 = mult_bin(bin1R, bin2R);
        part3 = mult_bin(add_bin(bin1L, bin1R), add_bin(bin2L, bin2R));
        result = add_bin(shift(part1, 2 * (n-(n/2))), add_bin(shift(sub_bin(part3, add_bin(part1, part2)), n-(n/2)), part2));
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    string bin1, bin2;
    cin >> bin1;
    cin >> bin2;

    string result = Karatsuba(bin1, bin2);

    cout << result << endl;

    return 0;
}
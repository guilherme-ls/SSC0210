#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

string calculate(string str1, string str2);

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << calculate(str1, str2) << endl;

    return 0;
}

string calculate(string str1, string str2) {
    int length1 = str1.length();
    int length2 = str2.length();

    if(length2 > length1) {
        int templ = length2;
        string temp = str2;

        str2 = str1;
        length2 = length1;

        length1 = templ;
        str1 = temp;
    }

    string modulo;
    string best_modulo = "";
    for(int i = 1; i <= length2; i++) {
        if((length2 % i != 0) || (length1 % i != 0))
            continue;

        modulo = str2.substr(0, i);

        // checks if modulo applies to str2
        bool valid = true;
        for(int j = i; j <= length2 - i; j += i) {
            if(modulo != str2.substr(j, i)) {
                valid = false;
                break;
            }
        }
        if(!valid)
            continue;

        // checks if modulo applies to str1
        valid = true;
        for(int j = 0; j <= length1 - i; j += i) {
            if(modulo != str1.substr(j, i)) {
                valid = false;
                break;
            }
        }
        if(!valid)
            continue;

        // valid
        best_modulo = modulo;
    }

    return best_modulo;
}
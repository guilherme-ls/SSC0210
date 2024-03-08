#include<cstdio>
#include<cstring>
#include<map>
#include<iostream>

using namespace std;

int main() {
    int n_entries;
    scanf("%d", &n_entries);
    map<const string, int> entries;

    for(int i = 0; i < n_entries; i++) {
        string name;
        cin >> name;

        int number = entries[name];
        if(number == 0) {
            entries[name] = 1;
            cout << "OK\n";
        } else {
            cout << name << entries[name]++ << '\n';
        }
    }

    return 0;
}
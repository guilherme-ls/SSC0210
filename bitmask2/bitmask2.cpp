#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

bool calculate(int n, vector<int> sticks, int value, long bitmask, long begin, int count);

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int g;
        cin >> g;

        vector<int> sticks;
        int sum = 0;
        for(int j = 0; j < g; j++) {
            int c;
            cin >> c;
            sum += c;
            sticks.push_back(c);
        }

        if(sum % 4 != 0)
            cout << "nao" << endl;
        else {
            sum /= 4;
            if(calculate(g, sticks, sum, 0UL, 0UL, 1))
                cout << "sim" << endl;
            else
                cout << "nao" << endl;
        }
    }

    return 0;
}

bool calculate(int n, vector<int> sticks, int value, long bitmask, long begin, int count) {
    long nSubSet = 1UL << n;
    bool found = false;
    
    for(long sub = begin + 1; sub < nSubSet; ++sub) {
        int sum = 0;

        if((sub & bitmask) == 0) {
            for (int elem = 0; elem < n; ++elem){
                int mask = 1 << elem;

                if ((sub & mask) != 0)
                    sum += sticks[elem];
            }
            
            if(sum == value) {
                if(count == 4) {
                    found = true;
                    break;
                }
                else {
                    found = calculate(n, sticks, value, sub + bitmask, sub, count + 1);
                    if(found)
                        break;
                }
            }
        }
    }

    return found;
}
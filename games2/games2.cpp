#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_set>

using namespace std;

// A Function to calculate Mex of all the values in that set
int Mex(unordered_set<int> set) {
    int mex = 0;
    while(set.find(mex) != set.end()) mex++;
    return mex;
}
 
// A function to Compute Grundy Number of 'n'
void calculateGrundy(int n, int *grundy) {
    grundy[0] = grundy[1] = grundy[2] = 0;
    grundy[3] = 1;
    for(int s = 2000; s < n; s++) {
        grundy[s] = 1;
    }
    n = min(n, 2000);

    for(int s = 0; s < n; s++) {
        unordered_set<int> set;

        // Armazena possibilidades de insercao no set
        for(int i = 1; i < (s + 1)/2; i++) {
            set.insert(grundy[s - i] ^ grundy[i]);
        }

        // Armazena o mex
        grundy[s] = Mex(set);
    }
}

int main() {
    int n, p;
    cin >> n;

    int stacks[n];
    int maximum = 3;

    for(int i = 0; i < n; i++) {
        cin >> stacks[i];
        maximum = max(maximum, stacks[i]);
    }

    int grundy[maximum + 1];
    for(int i = 0; i <= maximum; i++) grundy[i] = -1;    
    calculateGrundy(maximum, grundy);

    for(int i = 0; i < n; i++) {
        int result = grundy[stacks[i]];

        if(result != 0)
            cout << "primeiro" << endl;
        else
            cout << "segundo" << endl;
    }

    return 0;
}


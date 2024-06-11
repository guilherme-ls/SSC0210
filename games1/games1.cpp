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
int calculateGrundy(int n, int *grundy) {
    grundy[0] = 0;
    grundy[1] = 1;
    grundy[2] = 2;
    grundy[3] = 3;

    if(grundy[n] != -1) return grundy[n];

    unordered_set<int> set;
    // Armazena 3 possibilidades de insercao no set
    for(int i = 1; i <= 3; i++) set.insert(calculateGrundy(n - i, grundy));

    // Armazena o mex
    grundy[n] = Mex(set);

    return grundy[n];
}

int main() {
    int n, p;
    cin >> n >> p;

    int stacks[n];
    int maximum = 0;

    for(int i = 0; i < n; i++) {
        cin >> stacks[i];
        maximum = max(maximum, stacks[i]);
    }

    int grundy[maximum + 1];
    for(int i = 0; i <= maximum; i++) grundy[i] = -1;
    calculateGrundy(maximum, grundy);

    int result = grundy[stacks[n-1]];
    for(int i = 0; i < n - 1; i++) {
        result = result ^ grundy[stacks[i]];
    }

    if(result != 0) {
        if(p == 1)
            cout << "Jogador 1 ganhou o jogo!" << endl;
        else
            cout << "Jogador 2 ganhou o jogo!" << endl;
    }
    else {
        if(p == 1)
            cout << "Jogador 1 perdeu o jogo!" << endl;
        else
            cout << "Jogador 2 perdeu o jogo!" << endl;
    }

    return 0;
}


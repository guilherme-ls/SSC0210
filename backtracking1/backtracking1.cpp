#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<list>

using namespace std;

void permute(std::list<string> *permutations, string dna, int N, int k, int pos);

char amino[4] = {'A', 'G', 'C', 'T'};

int main() {
    int T, N, k;
    string dna;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> k;
        cin >> dna;
        
        std::list<string> permutations;

        permute(&permutations, dna, N, k, 0);

        cout << permutations.size() + 1 << endl;

        permutations.push_back(dna);
        permutations.sort();
        while(permutations.size() != 0) {
            cout << permutations.front() << endl;
            permutations.pop_front();
        }
    }

    return 0;
}

void permute(std::list<string> *permutations, string dna, int N, int k, int pos) {
    if(k == 0) {
        return;
    }
    for(int i = pos; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            if(dna[i] == amino[j]) {
                continue;
            }
            char store = dna[i];
            dna[i] = amino[j];
            (*permutations).push_back(dna);
            permute(permutations, dna, N, k-1, i+1);
            dna[i] = store;
        }
    }
}
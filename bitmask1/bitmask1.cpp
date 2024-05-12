#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
#define MAX 1000000007

int calculate(int n, int m, int* people_per_shirt, int** shirt_repetitions, int shirt, int mask);

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    // start bitmask
    int* people_per_shirt = (int*)calloc(m, sizeof(int));
    
    // deals with repetitions
    int** shirt_repetitions = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) shirt_repetitions[i] = (int*)calloc(m, sizeof(int));

    for(int i = 0; i < n; i++) {
        int m_ind;
        cin >> m_ind;

        for(int j = 0; j < m_ind; j++) {
            int num;
            cin >> num;

            int bitmask = 1 << i;
            ++(shirt_repetitions[i][num - 1]);
            if(!(people_per_shirt[num - 1] & bitmask))
                people_per_shirt[num - 1] += bitmask;
        }
    }

    cout << calculate(n, m, people_per_shirt, shirt_repetitions, 0, 0U) << endl;

    return 0;
}

int calculate(int n, int m, int* people_per_shirt, int** shirt_repetitions, int shirt, int mask) {
    if(mask == (int)((1UL << n) - 1UL)) {
        return 1;
    }
    if(shirt >= m) {
        return 0;
    }

    int total = calculate(n, m, people_per_shirt, shirt_repetitions, shirt + 1, mask);
    for(int i = 0; i < n; i++) {
        int bitmask = 1 << i;
        if((bitmask & people_per_shirt[shirt]) && !(bitmask & mask)) {
            total += shirt_repetitions[i][shirt] * calculate(n, m, people_per_shirt, shirt_repetitions, shirt + 1, mask + bitmask);
        }
    }

    return total % MAX;
}
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

#define MAX 99999

int calculate(int n, int *list, int* nstep);

int main() {
    int n;
    int *list, *nstep;

    // reads inputs
    cin >> n;
    list = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        cin >> list[i];
    }

    nstep = (int*)malloc(n * sizeof(int));
    for(int i = 1; i < n; i++) {
        nstep[i] = MAX;
    }
    nstep[0] = 0;

    int value = calculate(n, list, nstep);
    if(value != MAX) {
        cout << value << endl;
    }
    else {
        cout << "Salto impossivel" << endl;
    }
    return 0;
}

int calculate(int n, int *list, int *nstep) {
    for(int i= 0; i < n; i++) {
        for(int j = 1; j < n - i && j <= list[i]; j++) {
            if(nstep[i + j] > nstep[i] + 1) {
                nstep[i + j] = nstep[i] + 1;
            }
        }
    }

    return nstep[n-1];
}
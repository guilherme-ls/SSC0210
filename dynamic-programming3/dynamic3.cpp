#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int calculate(int n, int *gomos, int* memory);

int main() {
    int n;
    cin >> n;


    return 0;
}

int calculate(int n, int *list, int *nstep) {
    for(int i= 0; i < n; i++) {
        for(int j = 1; j < n - i && j <= list[i]; j++) {
            
        }
    }

    return nstep[n-1];
}
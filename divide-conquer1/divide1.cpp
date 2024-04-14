#include<iostream>
#include<cstdlib>
#include<math.h>

#define ERROR 0.000000001

using namespace std;

double p, q, r, s, t, u;

double function(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> p >> q >> r >> s >> t >> u;

        double inicio = 0, meio, fim = 1;
        double error = 1;

        if(function(inicio) * function(fim) > 0) {
            cout << "Sem solucao" << endl;
            continue;
        }

        while(error > ERROR) {
            meio = (inicio + fim) / 2;
            if(function(inicio) * function(meio) <= 0) {
                fim = meio;
            }
            else if (function(meio) * function(fim) <= 0) {
                inicio = meio;
            }
            error = fim - inicio;
        }

        printf("%.4lf\n", meio);
    }

    return 0;
}
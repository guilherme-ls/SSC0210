#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int main() {
    int bach, spin, count = 1;

    while(1) {
        scanf("%d %d", &bach, &spin);
        int temp, young = 999999999;
        for(int i = 0; i < bach; i++) {
            scanf("%d", &temp);
            if(temp < young)
                young = temp;
        }
        for(int i = 0; i < spin; i++){
            scanf("%d", &temp);
        }

        if(bach == 0 && spin == 0) {
            break;
        }

        int diff = bach - spin;
        printf("Case %d: ", count++);

        if(diff <= 0) {
            printf("0\n");
        }
        else {
            printf("%d %d\n", diff, young);
        }
    }

    return 0;
}
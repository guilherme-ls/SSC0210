#include <stdlib.h>
#include <stdio.h>

int main() {
    int n_entry;
    scanf("%d", &n_entry);

    for(int i = 0; i < n_entry; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if((x + 2*y) % 2 == 0 ) {
            if(y%2 == 0) {
                printf("YES\n");
            }
            else if(x > 1) {
                printf("YES\n");
            }
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}

#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

struct ltstr {
    bool operator() (char* s1, char* s2) {
        return strcmp(s1, s2) < 0;
    }
};

int main() {
    int n_tests;
    scanf("%d", &n_tests);

    for(int i = 0; i < n_tests; i++) {
        int n_options;
        map<char*, int, ltstr> entries;
        scanf("%d", &n_options);

        for(int j = 0; j < n_options; j++) {
            char string[21];
            int days;
            scanf("%s %d", string, &days);
            entries.insert(make_pair(string, days));
        }
        int num_days;
        scanf("%d", &num_days);
        char searched[21];
        scanf("%s", searched);

        int final_days = entries[searched];

        if(final_days <= num_days) {
            printf("final: %d", final_days);
            printf("Case %d: Yesss\n", i+1);
        }
        else if(final_days <= num_days + 5) {
            printf("final: %d", final_days);
            printf("Case %d: Late\n", i+1);
        }
        else {
            printf("final: %d", final_days);
            printf("Case %d: Do your own homework!\n", i+1);
        }
    }

    return 0;
}
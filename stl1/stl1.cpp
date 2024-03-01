#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int main() {
    int n_tests;
    scanf("%d", &n_tests);

    for(int i = 0; i < n_tests; i++) {
        int n_options;
        map<string, int> entries;
        scanf("%d", &n_options);

        for(int j = 0; j < n_options; j++) {
            string entry;
            int days;
            cin >> entry;
            scanf("%d", &days);
            entries.insert(make_pair(entry, days));
        }
        int num_days;
        scanf("%d", &num_days);
        string searched;
        cin >> searched;

        int final_days = entries[searched];

        if(final_days == 0) {
            printf("Case %d: Do your own homework!\n", i+1);
        }
        else if(final_days <= num_days) {
            printf("Case %d: Yesss\n", i+1);
        }
        else if(final_days <= num_days + 5) {
            printf("Case %d: Late\n", i+1);
        }
        else {
            printf("Case %d: Do your own homework!\n", i+1);
        }
    }

    return 0;
}
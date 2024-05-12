#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<list>

using namespace std;

int calculate(int n, int m, pair<unsigned long long, unsigned long long> current_bitmask, vector<list<pair<unsigned long long, unsigned long long>>> shirts);

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<list<int>> repetitions;
    vector<list<pair<unsigned long long, unsigned long long>>> shirts;
    for(int i = 0; i < n; i++) {
        int m_ind;
        cin >> m_ind;
        
        list<pair<unsigned long long, unsigned long long>> current_shirts;

        for(int j = 0; j < m_ind; j++) {
            int num;
            cin >> num;

            pair<unsigned long long, unsigned long long> bitmask = make_pair(0ULL, 0ULL);
            if(num > 50)
                bitmask.second = 1ULL << (num - 51);
            else
                bitmask.first = 1ULL << (num - 1);

            current_shirts.emplace_front(bitmask);
        }
        current_shirts.sort();

        shirts.emplace_back(current_shirts);
    }

    pair<unsigned long long, unsigned long long> current_bitmask = make_pair(0ULL, 0ULL);
    int count = calculate(n-1, m, current_bitmask, shirts);
    cout << count << endl;

    return 0;
}

int calculate(int n, int m, pair<unsigned long long, unsigned long long> current_bitmask, vector<list<pair<unsigned long long, unsigned long long>>> shirts) {
    int count = 0;
    int shirts_size = shirts[n].size();
    auto list_iter = shirts[n].begin();
    
    for(int i = 0; i < shirts_size; i++) {
        pair<unsigned long long, unsigned long long> bitmask = *list_iter;

        // Continues checking if there is no correspondence between bitmasks
        if(!((current_bitmask.first & bitmask.first) || (current_bitmask.second & bitmask.second))) {
            // Increases count if this is the last bitmask
            if(n == 0) {
                ++count;
            }
            else {
                current_bitmask.first += bitmask.first;
                current_bitmask.second += bitmask.second;
                count += calculate(n - 1, m, current_bitmask, shirts);
                current_bitmask.first -= bitmask.first;
                current_bitmask.second -= bitmask.second;
            }
        }
        ++list_iter;
    }

    if(n == 2) {
        cout << count << endl;
    }
    return count % 999999993;
}
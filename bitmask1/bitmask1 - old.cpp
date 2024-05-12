#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#include<list>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    list<pair<unsigned long long, unsigned long long>> lista;
    pair<unsigned long long, unsigned long long> start_pair = make_pair(1ULL << 50, 1ULL << 50);
    lista.emplace_front(start_pair);

    for(int i = 0; i < n; i++) {
        list<pair<unsigned long long, unsigned long long>> new_list;

        int m_ind;
        cin >> m_ind;

        for(int j = 0; j < m_ind; j++) {
            int num;
            cin >> num;
            
            pair<unsigned long long, unsigned long long> bitmask = make_pair(0ULL, 0ULL);
            if(num > 50)
                bitmask.second = 1ULL << (num - 51);
            else
                bitmask.first = 1ULL << (num - 1);

            int tamanho = lista.size();
            auto list_iter = lista.begin();
            for(int pos = 0; pos < tamanho; pos++) {
                pair<unsigned long long, unsigned long long> new_pair = (*list_iter);
                if(!((new_pair.first & bitmask.first) || (new_pair.second & bitmask.second))) {
                    new_pair.first += bitmask.first;
                    new_pair.second += bitmask.second;
                    new_list.emplace_back(new_pair);
                }

                ++list_iter;
            }
        }
        lista = new_list;
    }

    cout << (lista.size())%(999999993) << endl;

    return 0;
}
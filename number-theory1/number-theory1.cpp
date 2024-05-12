#include<iostream>
#include<cstdlib>
#include<vector>
#include<bitset>
#include<map>

using namespace std;

#define MAX 1000001

int calculate(int num, vector<int> primes);
vector<int> prime_numbers(int num);

int main() {
    int n;
    cin >> n;

    // calculates all primes
    vector<int> prime_nums = prime_numbers(MAX);
    map<int, int> results;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(results.find(num) == results.end())
            results.emplace(num, calculate(num, prime_nums));
        
        cout << results.at(num) << endl;
    }

    return 0;
}

vector<int> prime_numbers(int num){
    vector<int> prime_nums;

    bitset<1000010> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long i = 2; i <= num; i++) {
        if(bs[i]) {
            for(long j = i * i; j <= num; j += i) {
                bs[j] = 0;
            }
            prime_nums.push_back((int)i);
        }
    }

    return prime_nums;
}

int calculate(int num, vector<int> primes) {
    int current = 1;
    int num_divider = 1;
    int size = primes.size();
    for(int i = 0; (current = primes[i]) <= num && i < size; i++) {
        int count = 0;
        while((num % current) == 0) {
            ++count;
            num = num / current;
        }

        num_divider *= (count + 1);
    }

    if(num_divider == 1)
        num_divider = 2;
    return num_divider;

}
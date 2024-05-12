#include<iostream>
#include<cstdlib>
#include<vector>
#include<bitset>
#include<math.h>

using namespace std;

int calculate(int num);
int primes(int num);

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << primes(num) << endl;
    }

    return 0;
}

int primes(int num) {
    long size = num + 1;
    bitset<1000010> bs;
    vector<int> prime_nums;

    int num_divider = 1;

    bs.set();
    bs[0] = bs[1] = 0;
    for(long i = 2; i <= size; i++) {
        if(bs[i]) {
            for(long j = i * i; j <= size; j += i) {
                bs[j] = 0;
            }
            prime_nums.push_back((int)i);
        }
    }

    int size_prime = sqrt(size);
    int current_num;
    for(int i = 0; (current_num = prime_nums[i]) <= size_prime; i++) {
        int count = 0;
        long mult = current_num;
        while(num % mult == 0) {
            ++count;
            mult *= current_num;
        }
        
        num_divider *= (count + 1);
    }

    if(*(prime_nums.end()-1) == num)
        num_divider++;

    return num_divider;

}
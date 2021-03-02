#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve2(sqrt(2147483647) + 1);
vector <long> prime;

void compute(long m,long n){
    vector<int> sieve(n - m + 1);
    for(long i = 0; i < prime.size(); i++){
        if(prime[i] > sqrt(n)) break;
        long j = 0;
        if(m % prime[i] != 0) j = ( m/prime[i] + 1) * prime[i] - m;
        if(j+m == prime[i]) j += prime[i];
        for(; j < sieve.size(); j += prime[i]) sieve[j] = 1;
    }

    for(long i = 0; i < sieve.size();i++){
        if(!sieve[i] && (i+m) != 1) printf("%ld\n", i + m);
    }
}

int main() {
    long t;
    scanf("%ld", &t);
    //precalculate sieve 2
    sieve2[0] = 1;
    sieve2[1] = 1;
    for(long i = 2; i <= sqrt(sieve2.size()); ++i) {
        if(sieve2[i]) continue;
        for(long j = i * i; j < sieve2.size(); j += i) sieve2[j] = 1;
    }
    for(long i = 0; i < sieve2.size(); i++){
        if(!sieve2[i]) prime.push_back(i);
    }

    while(t--){
        long m,n;
        scanf("%ld %ld", &m, &n);
        compute(m,n);
    }
}

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    long t;
    cin >> t;
    while(t--) {
        long m,n;
        cin >> m >> n;
        vector<int> sieve(n - m + 1), sieve2(sqrt(n) + 1);
        sieve2[0] = 1;
        if(sieve2.size() > 1) sieve2[1] = 1;
        for(long i = 2; i <= sqrt(sieve2.size()); ++i) {
            if(sieve2[i]) continue;
            for(long j = i * i; j < sieve2.size(); j += i) sieve2[j] = 1;
        }
        for(long i = 2; i < sieve2.size(); i++){ //10^3.5 in size
            if(!sieve2[i]) {
                long j = 0;
                if(m == 1) j = 1;
                for(; j < sieve.size(); j++)   //10^5 in size
                    if( ((j+m) % i) == 0 && (j+m) != i) { sieve[j] = 1; break; }
                for(; j < sieve.size(); j += i) sieve[j] = 1;
            }
        }
        for(long i = 0; i < sieve.size();i++){
            if(!sieve[i] && (i+m) != 1) printf("%ld\n", i + m);
        }
        printf("\n");
    }
}

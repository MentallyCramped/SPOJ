#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1000000007;
vll dp(10000001);

void init(){
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= 10000000; i++){
        dp[i] = (i % MOD * dp[i-1] % MOD) % MOD;
    }
}

int main(){
    ll t;
    cin >> t;
    init();
    while (t--){
        ll n;
        cin >> n;
        ll sum = 0;
        bool even = true;
        while(n >= 0){
            if (even) sum = (sum + dp[n] % MOD) % MOD;
            else sum = (sum - dp[n] % MOD) % MOD;
            n--;
            even = !even;
        }
        cout << sum / 2 << endl;
    }
}
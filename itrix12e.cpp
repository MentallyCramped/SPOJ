#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"
#include <thread>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll primes{2,3,5,7,11,13,17,19},sum = {0,4};
vvll pairs(9, vll(9));
vll dp(9,0);
vvll inv = {{1,1,0,-1,0,-1,-2,0,0},
            {1,1,0,0,-1,-1,-1,-1,0},
            {0,0,0,-1,1,1,0,0,-1},
            {-1,0,-1,-2,3,2,0,1,-1},
            {0,-1,1,3,-3,-2,1,-1,1},
            {-1,-1,1,2,-2,-1,1,0,1},
            {-2,-1,0,0,1,1,2,1,0},
            {0,-1,0,1,-1,0,1,0,0},
            {0,0,-1,-1,1,1,0,0,0}
};
vvll eye = {
        {1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1}
};

void calc_pairs(ll x, vvll& pairs){
    for(ll i = 0; i < 9; i++){
        if(find(primes.begin(), primes.end(), i+x+2) != primes.end()) {
            pairs[i][x] = 1;
        }
    }
}

ll modulo(ll n){
    if(n >= 0) return n % 1000000007;
    else{
        return 1000000007 + n % 1000000007;
    }
}

void init(){
    dp[1] = dp[2] = dp[4] = dp[6] = 1;
    for(ll i = 2; i <= 2; i++){
        vll dp_old(dp);
        sum.push_back(sum[i-1]);
        for(ll j = 0; j < 9; j++){
            dp[j] = 0;
            for(ll k = 0; k < 9; k++){
                if(pairs[j][k] == 1) {
                    dp[j] += max(dp_old[k], ll(1));
                    dp[j] %= 1000000007;
                }
            }
            sum[i] += dp[j];
            sum[i] %= 1000000007;
        }
    }
}

vvll matrix_mul(const vvll &A, const vvll &B)
{
    vvll c(A);
    for(ll i = 0; i < A.size(); i++){
        for(ll j = 0; j < A.size(); j++){
            c[i][j] = 0;
            for(ll k = 0; k < A.size(); k++) {
                c[i][j] = modulo(c[i][j] + modulo(modulo(A[i][k]) * modulo(B[k][j])));
            }
        }
    }
    return c;
}

vvll matrix_diff(const vvll &A, const vvll &B){
    vvll C(A);
    for(ll i = 0; i < A.size(); i++){
        for(ll j = 0; j < A.size(); j++) {
            C[i][j] = modulo(A[i][j] - B[i][j]);
        }
    }
    return C;
}

vvll log_mul(const vvll& A, ll n){
    if(n == 0) return eye;
    else if(n == 1) return A;
    else if(n == 2) return matrix_mul(A,A);
    vvll B = log_mul(A, n / 2);
    if(n % 2 == 0) {
        return matrix_mul(B,B);
    }
    else{
        vvll C = matrix_mul(B,B);
        return matrix_mul(C,A);
    }
}

int main(){
    for(ll i = 0; i < 9; i++){
        calc_pairs(i, pairs);
    }
    init();
    ll t = 0;
    vvll DP;
    for(ll i = 0; i < 9; i++) DP.push_back(dp); //Store dp[2]
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n <= 2) cout << sum[n] << endl;
        else{
            vvll p_n = log_mul(pairs, n - 1);   //Calculate pairs^n-1
            p_n = matrix_mul(inv, matrix_diff(eye,p_n));    //Calculate geometric sum till pairs^n
            p_n = matrix_mul(DP,p_n);   //Calculate dp[n]
            ll suml = sum[1];
            for(ll i = 0; i < 9; i++) {
                suml = modulo(suml + p_n[0][i]);
            }
            cout << suml << endl;
        }
    }
}
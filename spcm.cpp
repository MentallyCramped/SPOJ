#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll func(ll n){
//    cout << n << endl;
    ll sum = 0, uniq = 0, curr = n;
    for(ll i = 2; i <= sqrt(curr) + 1; i++){
        if(n % i == 0) {
            if(i != curr) uniq++;
            sum += i;
            while(n % i == 0 && n > 1) n /= i;
        }
        if(n == 1) break;
    }
    if(uniq == 0) return 1;
    if(n > 1){
        sum += n;
        uniq++;
    }
//    cout << sum << "  " << uniq << endl;
    return func(sum) + uniq;
}

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << func(n) << endl;
    }
}
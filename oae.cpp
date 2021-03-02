#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"
#include "unordered_map"
#include "set"

using namespace std;

typedef long long ll;

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n; cin >> n;
        ll a = 5, b = 4;
        n--;
        while(n--){
            a *= 10;
            a %= 314159;
            b *= 8;
            b %= 314159;
        }
        cout << (a + b) % 314159 << endl;
    }
}
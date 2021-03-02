#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long reverse(long a){
    long b = 0;
    while(a > 0){
        b = b*10 + a%10;
        a /= 10;
    }
    return b;
}

int main(){
    long t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        a = reverse(a);
        b = reverse(b);
        a = a + b;
        cout << reverse(a) << "\n";
    }
}
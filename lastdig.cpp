#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int lastdig(long a, long b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int even = lastdig(a,b/2) % 10;
    int odd = (even * a) % 10;
    if(b % 2 == 0){
        return (even * even) % 10;
    }
    else {
        return (even * odd) % 10;
    }
}

int main() {
    long t;
    scanf("%ld", &t);
    while (t--) {
        long a, b;
        scanf("%ld %ld", &a, &b);
        printf("%d\n", lastdig(a,b));
    }
}

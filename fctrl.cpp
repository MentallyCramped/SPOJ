#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long a;
        scanf("%ld", &a);
        long div = 5, count = 0;
        while(div <= a){
            count += a/div;
            div *= 5;
        }
        printf("%ld\n", count);
    }
}
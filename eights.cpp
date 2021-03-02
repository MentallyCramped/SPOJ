#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

int main(){
    vector<int> pos = {192, 442, 692};
    long long t;
    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        if(k % 4 == 0) cout << 1000 * (k/4 - 1) + 942 << endl;
        else{
            cout << 1000 * (k/4) + pos[k % 4 - 1] << endl;
        }
    }
}
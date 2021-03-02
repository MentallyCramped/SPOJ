#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

//I suppose a lazy approach would be to traverse the tree - logn time per query
//Orrr you could try mathematically deriving a formula for the nth term

string binary(long long n){
    string s = "";
    while(n > 0){
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    //Let's traverse the tree - convert n into binary numbers; that gives you the actual path to traverse
    while(true){
        long long n;
        cin >> n;
        if(n == 0) break;
        string s = binary(n);
        long num = 1, dem = 1;  //root
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0'){
                dem += num;
            }
            else{
                num += dem;
            }
        }
        cout << num << "/" << dem << endl;
    }
}
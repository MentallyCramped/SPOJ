#include <iostream>
#include <vector>

using namespace std;

int main() {
    while(true){
        string s;
        cin >> s;
        if(s == "0") break;
        s.push_back('1');   //inserting random non zero number for i+2 zero check
        vector<int> dp(s.size());
        dp[s.size() - 2] = dp[s.size() - 1] = 1;
        for(int i = s.size() - 2; i >= 0; i--){
            if(s[i] == '0'){
                if(stoi(s.substr(i-1,2)) < 27) dp[i-1] = dp[i+1];
                else break; //no possible encoding
                i--;
            }
            else {
                dp[i] = dp[i + 1];
                if (i < s.size() - 2 && stoi(s.substr(i, 2)) < 27 && s[i+2] != '0') dp[i] += dp[i + 2];
            }
        }
        cout << dp[0] << endl;
    }
}
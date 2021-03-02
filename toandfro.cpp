#include <iostream>
#include <vector>

using namespace std;

int main(){
    while(true){
        int c;
        cin >> c;
        if(c == 0) break;
        string s;
        cin >> s;
        int i = 0, j = 0, n = s.size(), x = 0, e = 0;
        vector< vector<char> > a (n/c, vector<char>(c) );
        while(i < n) {
            if (!e) {
                a[j][x] = s[i];
                i++;
            }
            else{
                a[j][x] = s[i];
                i--;
            }
            x++;
            if(x == c){
                x = 0;
                j++;
                if(!e) i += c - 1;
                else i += c + 1;
                e = 1 - e;
            }
        }
        s = "";
        for(int j = 0; j < c; j++){
            for(int i = 0; i < n/c; i++) s += a[i][j];
        }
        cout << s << endl;
    }
}
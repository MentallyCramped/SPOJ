#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

/*
 * Idea #1: Need to implement division by 2 and subtraction/addition for large numbers
 * Idea #2:
 */

string subtract(string n, string d){
    int i = n.size() - 1, j = d.size() - 1;
    string s = "";
    while(j >= 0){
        if( (n[i] - '0') >= (d[j] - '0')) s += (n[i] - '0') - (d[j] - '0') + '0';
        else{
            int t = i - 1;
            while(n[t] == '0') { n[t] = '9'; t--; }
            n[t] = (n[t] - '0' - 1) + '0';
            s += (n[i] - '0' + 10) - (d[j] - '0') + '0';
        }
        i--;
        j--;
    }
    while(i >= 0){
        s += n[i];
        i--;
    }
    for(i = s.size() - 1; i >= 0; i--){
        if(s[i] != '0') break;
    }
    s = s.substr(0, i + 1);
    if(s.empty()) s = "0";
    reverse(s.begin(), s.end());
    return s;
}

string div_by_two(string a){
    int carry = 0;
    string q = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] - '0' + carry * 10 == 0) {
            q += '0';
        }
        else if(a[i] - '0' + carry * 10 < 2) { carry = 1; q += '0'; }
        else{
            q += (a[i] - '0' + carry * 10) / 2 + '0';
            carry = (a[i] - '0' + carry * 10) % 2;
        }
    }
    int i = 0;
    if(q.size() > 1) {
        for (; i <= q.size(); i++) {
            if (q[i] != '0') break;
        }
    }
    q = q.substr(i);
    return q;
}

string add (string a, string b){
    if(a.size() < b.size()) swap(a,b);
    else if(a.size() == b.size()){
        int i = 0;
        while(a[i] == b[i]) i++;
        if(i < a.size() && a[i] < b[i]) swap(a,b);
    }
    int i  = a.size() - 1, j = b.size() - 1, carry = 0;
    string c = "";
    while(j >= 0){
        c += ( (a[i] - '0') + (b[j] - '0') + carry ) % 10 + '0';
        carry = ( (a[i] - '0') + (b[j] - '0') + carry ) / 10;
        i--; j--;
    }
    while(i >= 0){
        if(carry) {
            c += ((a[i] - '0') + carry) % 10 + '0';
            carry = ((a[i] - '0') + carry) / 10;
        }
        else c += a[i];
        i--;
    }
    if(carry) c += '1';
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    int t = 10;
    while(t--){
        string n,d;
        cin >> n >> d;
        string a = subtract(n,d);
        a = div_by_two(a);
        string b = add(a, d);
        cout << b << "\n" << a << "\n";
    }
}
#include "vector"
#include "algorithm"
#include "iostream"
#include "stack"
using namespace std;

/*
 * Stack will always maintain strict increasing order from top to bottom
 * Allowed elements will always be in the set {1,a} in strict increasing order
 * As more elements get allowed, make sure the stack is emptied out as frequently as possible
 */
int main() {
    while(true){
        int n,a = 0;
        cin >> n;
        bool fail = false;
        stack<int> s;
        if(n == 0) break;
        while(n--){
            int x;
            cin >> x;
            if(fail) continue;
            if(x == a + 1) a++;
            else{
                if(s.empty()) s.push(x);
                else{
                    if(s.top() > x) s.push(x);
                    else fail = true;
                }
            }
            while(!s.empty() && s.top() == a + 1){
                a = s.top();
                s.pop();
            }
        }
        if(!s.empty()) cout << "no\n";
        else cout << "yes\n";
    }
}
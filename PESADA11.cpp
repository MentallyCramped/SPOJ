#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"
#include "unordered_map"
#include "set"

using namespace std;

void bellman_ford(vector< vector< long> > &d, const vector< vector< long> > &G){
    int x = G.size() + 1;
    int n = x - 1;
    while(x--){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < G[i].size(); k++) {
                    d[i][j] = min(d[i][j], d[i][G[i][k]] + d[G[i][k]][j]);
                }
            }
        }
    }
}


int main(){
    long long t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector< vector<long> > d (n, vector<long> (n, 32765)),
        G(n , vector<long>(0));
        for(int i = 0; i <n; i++){
            for(int j = 0; j < n; j++){
                long w;
                cin >> w;
                d[i][j] = w;
                if(d[i][j] < 32765 && j != i) G[i].push_back(j);
            }
        }
        bellman_ford(d,G);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }
}
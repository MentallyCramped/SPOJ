#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"
#include "unordered_map"
#include "set"

using namespace std;
typedef long long ll;
//A map can tell you which students can be bossed by whomever
vector<ll> topsort;
void dfs(long long u, vector<ll> &visited, vector<ll> &parent, const vector< vector<ll> > &G, long long prev) {
    if(visited[u]) return;
    visited[u] = 1;
    parent[u] = prev;

    for(long long i = 0; i < G[u].size(); i++){
        dfs(G[u][i],visited, parent, G, u);
    }
    topsort.push_back(u);
}

int main(){
    ll n,k;
    scanf("%ld %ld", &n, &k);
    vector< vector<ll> > G(n + 1, vector<ll> (0));
    for(ll i = 1; i <= k; i++){
        ll w;
        scanf("%ld", &w);
        while(w--){
            ll u;
            scanf("%ld", &u);
            G[i].push_back(u);
        }
    }
    vector<ll> visited (n+1, 0), parent(n+1, 0);
    topsort.clear();
    for(long long i = 1; i <= n; i++){
        if(!visited[i]) dfs(i, visited, parent, G, 0);
    }
//    for(ll i = 1; i <= n; i++) printf("%lld ",parent[i]);
//    cout << endl;
    ll i = 0, boss = 0;
    for(i = topsort.size() - 1; i >= 0; i--){
        if(parent[topsort[i]] == 0){
            if(boss == 0) boss = topsort[i];
            else{
                parent[topsort[i]] = boss;
                boss = topsort[i];
            }
        }
    }
    for(ll i = 1; i <= n; i++) printf("%lld\n",parent[i]);
}

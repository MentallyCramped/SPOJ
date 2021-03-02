#include "vector"
#include "algorithm"
#include "iostream"
#include "cmath"
#include "unordered_map"
#include "set"

using namespace std;

//Idea #1: Use BF to calc the shortest distance b/w everyone. Then use DP based on the set of orders and the starting location.

void bellman_ford(vector< vector<long long> > &d, const vector< vector<long long> > &G, const vector< vector<long long> > &W){
    int x = G.size(), n = x - 1;
    while(x--){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                for(int k = 0; k < G[i].size(); k++) {
                    d[i][j] = min(d[i][j], d[i][G[i][k]] + d[G[i][k]][j]);
                }
            }
        }
    }
}

void permute(int i, unordered_map<int, vector<string>> &bitmasks, const vector< pair<long long,long long> > &orders, string indices){
    if(i == orders.size()){
        int ones = 0;
        for(int x = 0; x < indices.size(); x++) if(indices[x] == '1') ones++;
        bitmasks[ones].push_back(indices);
        return;
    }
    //include i
    indices += '1';
    permute(i + 1,bitmasks,orders, indices);
    //exclude i
    indices.pop_back();
    indices += '0';
    permute(i + 1,bitmasks,orders, indices);
}

long long dec_convert(string s){
    long long a = 0;
    for(int i = s.size() - 1; i >= 0; i--) a += (s[i]-'0') * pow(2,s.size() - i - 1);
    return a;
}

void build_dp(int home, const vector< pair<long long,long long> > &orders, vector< vector< long long> >&dp ,
              const vector< vector<long long> > &G, const vector< vector<long long> > &d){
    //permute through every subset of orders
    unordered_map<int, vector<string> > bitmasks;
    string indices = "";
    for(int i = 0; i <= orders.size(); i++) bitmasks.insert({i,{}});
    permute(0,bitmasks,orders,indices);

//    for(int i = 0; i <= orders.size(); i++){
//        cout << i << " ---> ";
//        for(int j = 0; j < bitmasks[i].size(); j++){
//            cout << bitmasks[i][j] << " ";
//        }
//        cout << endl;
//    }
    for(int i = 1; i < G.size(); i++){
        dp[i][0] = d[i][home];
    }


    for(int length = 1; length <= orders.size(); length++) {
        for (int order = 0; order < bitmasks[length].size(); order++) {
            string mask = bitmasks[length][order];
//            cout << "MASK : " << mask << endl;
            long long index = dec_convert(mask);
//            cout << "Equivalent number : " << index << endl;
            for (int start = 1; start < G.size(); start++) {    //traverse orders of length i
                for(int i = 0; i < mask.size(); i++){
                    if(mask[i] == '1'){
                        string temp = mask;
                        temp[i] = '0';
                        if(dp[start][index] >  dp[orders[i].second][dec_convert(temp)] +
                                               d[start][orders[i].first] + d[orders[i].first][orders[i].second]){
                            dp[start][index] = dp[orders[i].second][dec_convert(temp)] +
                                               d[start][orders[i].first] + d[orders[i].first][orders[i].second];
//                            backtrack[start][index] = temp;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n,m,h;
        cin >> n >> m >> h;
        vector< vector<long long> > G(n + 1, vector<long long>(0)), W(n + 1, vector<long long>(n + 1)), dist(n + 1, vector<long long>(n + 1, INT16_MAX));
        for(int i = 1; i <= n; i++) dist[i][i] = 0;
        while(m--){
            long long u,v,d;
            cin >> u >> v >> d;
            G[u].push_back(v);
            G[v].push_back(u);
            dist[v][u] = dist[u][v] = W[u][v] = W[v][u] = d;
        }
        long long z;
        cin >> z;
        vector< pair<long long,long long> > orders;
        while(z--){
            long long u,v,b;
            cin >> u >> v >> b;
            while(b--) orders.push_back({u,v});
        }
        vector< vector<long long> > dp (n + 1, vector<long long> (pow(2, orders.size()) + 1, INT32_MAX));
//        cout << "INPUT IS DONE\n";
//        for(int i = 1; i <= n; i++){
//            cout << i << " ---> ";
//            for(int j = 0; j < G[i].size(); j++) {
//                cout << G[i][j] << " ";
//            }
//            cout << endl;
//        }
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <= n; j++) {
//                cout << W[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << "\n\n\n";
        bellman_ford(dist,G,W);
//        for(int i = 1; i <= n; i++){
//            for(int j = 1; j <= n; j++) {
//                cout << dist[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        vector<vector<string> > backtrack(G.size(), vector<string> (pow(2,orders.size())));
        build_dp(h,orders,dp,G,dist);
//        string s = "";
//        n = orders.size();
//        while(n--) s += '1';
//        while(dec_convert(s) > 0){
//            cout << backtrack[h][dec_convert(s)] << "  ";
//            s = backtrack[h][dec_convert(s)];
//        }
        cout << dp[h][pow(2,orders.size()) - 1] << endl;
    }
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    int find(vector<int> &parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
public:
    int detectCycle(int V, vector<int>adj[]) {
        vector<int> parent(V, -1);
        set<pair<int, int>> edges;
        for (int i = 0; i < V; ++i) {
            for (auto j : adj[i]) {
                edges.insert({min(i, j), max(i, j)});
            }
        }
        for (int i = 0; i < V; ++i) parent[i] = i;
        for (auto i : edges) {
            int u = i.first, v = i.second;
            int x = find(parent, u), y = find(parent, v);
            if (x == y) return 1;
            else parent[x] = y;
        }
        return 0;
    }
    void test() {
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
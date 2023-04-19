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
        if (parent[x] == x || parent[x] == -1) return x;
        return parent[x] = find(parent, parent[x]);
    }
public:
    int detectCycle(int V, vector<int>adj[]) {
        vector<int> parent(V, -1);
        for (int i = 0; i < V; ++i) {
            if (parent[i] == -1) {
                parent[i] = i;
            }
            int u = find(parent, i);
            sort(adj[i].begin(), adj[i].end());
            for (auto j : adj[i]) {
                if (j <= i) continue;
                int v = find(parent, j);
                if (v == u) return 1;
                parent[v] = u;
            }
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
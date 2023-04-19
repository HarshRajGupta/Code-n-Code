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

class disJointSet {
    vector<int> parent;
public:
    disJointSet(const int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unionSet(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        parent[x] = y;
        return true;
    }
};

class Solution {
public:
    int detectCycle(int V, vector<int>adj[]) {
        disJointSet ds(V);
        for (int i = 0; i < V; ++i) {
            for (auto j : adj[i]) {
                if (j <= i) continue;
                if (!ds.unionSet(i, j))
                    return 1;
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
#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ signed main() {preCompute(); signed t; cin >> t; while (t--)solve(), cout << '\n'; return 0;}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()


struct Graph {
    vector<vector<int>> adj, edges;
    map<pair<int, int>, int> weight;
    vector<int> indegree, outdegree;
    Graph(int n) : adj(vector<vector<int>>(n)), indegree(vector<int>(n)), outdegree(vector<int>(n)) {}
    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back(v);
        edges.push_back({w, u, v});
        weight[ {u, v} ] = w;
        ++outdegree[u];
        ++indegree[v];
    }
    void addUEdge(int u, int v, int w = 1) {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    void addUEdge(const vector<vector<int>> &edges) {
        if (edges.empty()) return;
        if (edges[0].size() == 2)
            for (auto &e : edges)
                addUEdge(e[0], e[1]);
        else
            for (auto &e : edges)
                addUEdge(e[0], e[1], e[2]);
    }
    void addEdge(const vector<vector<int>> &edges) {
        if (edges.empty()) return;
        if (edges[0].size() == 2)
            for (auto &e : edges)
                addEdge(e[0], e[1]);
        else
            for (auto &e : edges)
                addEdge(e[0], e[1], e[2]);
    }
    void bfs(int src = 0, function<void(int)> f = [](int x) {cout << x << ' ';}) {
        vector<bool> visited(adj.size());
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (visited[u]) continue;
            f(u);
            visited[u] = true;
            for (auto &v : adj[u])
                q.push(v);
        }
    }
    void dfs(int src = 0, function<void(int)> f = [](int x) {cout << x << ' ';}) {
        vector<bool> visited(adj.size());
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            f(u);
            for (auto &v : adj[u])
                if (!visited[v])
                    dfs(v);
        };
        dfs(src);
    }
    vector<vector<int>> floydWarshall() {
        vector<vector<int>> dist(adj.size(), vector<int>(adj.size(), 1e9));
        for (auto &e : edges)
            dist[e[1]][e[2]] = min(dist[e[1]][e[2]], e[0]);
        for (size_t k = 0; k < dist.size(); ++k)
            for (size_t i = 0; i < dist.size(); ++i)
                for (size_t j = 0; j < dist.size(); ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;
    }
    vector<int> dijkstra(int src = 0) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(adj.size(), 1e9);
        dist[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto v : adj[u]) {
                if (dist[u] + weight[ {u, v} ] < dist[v]) {
                    dist[v] = dist[u] + weight[ {u, v} ];
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    vector<int> bellmanFord(int src = 0) {
        vector<int> dist(adj.size(), 1e9);
        dist[src] = 0;
        for (size_t i = 0; i < adj.size() - 1; ++i) {
            for (auto e : edges) {
                int u = e[1], v = e[2], w = e[0];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }
    vector<vector<int>> mst() {
        sort(edges.begin(), edges.end());
        vector<int> parent(adj.size());
        iota(parent.begin(), parent.end(), 0);
        vector<vector<int>> mst(adj.size());
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        function<void(int, int)> unionSet = [&](int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            parent[x] = y;
        };
        for (auto e : edges) {
            int u = e[1], v = e[2];
            if (find(u) != find(v)) {
                mst[u].push_back(v);
                unionSet(u, v);
            }
        }
        return mst;
    }
    vector<int> topoSort() {
        vector<int> order, inDegree = indegree;
        queue<int> q;
        for (size_t i = 0; i < inDegree.size(); ++i)
            if (inDegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (auto v : adj[u]) {
                if (--inDegree[v] == 0)
                    q.push(v);
            }
        }
        return order;
    }
    int connectedComponents() {
        vector<bool> visited(adj.size());
        int count = 0;
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto v : adj[u])
                if (!visited[v])
                    dfs(v);
        };
        for (size_t i = 0; i < adj.size(); ++i)
            if (!visited[i])
                ++count, dfs(i);
        return count;
    }
    vector<int> connect() {
        vector<bool> visited(adj.size());
        vector<int> count;
        function<int(int)> dfs = [&](int u) {
            visited[u] = true;
            int res = 0;
            if (sz(adj[u]) == 1) ++res;
            for (auto v : adj[u])
                if (!visited[v])
                    res += dfs(v);
            return res;
        };
        for (size_t i = 0; i < adj.size(); ++i)
            if (!visited[i])
                count.push_back(dfs(i));
        return count;
    }
};
void solve(void) {
    int n; cin >> n;
    Graph g(n);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        g.addUEdge(u - 1, i);
    }
    auto res = g.connect();
    sort(all(res));
    debug(res)
    cout << g.connectedComponents() << '\n';
}

static bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush(); return 0;
}

__MAIN__
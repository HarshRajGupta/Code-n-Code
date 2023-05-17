#include <bits/stdc++.h>
using namespace std;

vector<int32_t> allPrimes;
vector<bool> sieve(const int n = 1e6 + 7) {
    /**
    * The function generates a boolean sieve of prime numbers up to a given limit and stores all the prime
    * numbers in a vector.
    *
    * @param n The parameter `n` is the upper limit of the range of numbers for which we want to generate
    * a sieve of prime numbers. In this code, the default value of `n` is 1000007.
    *
    * @return The function `sieve` returns a `vector<bool>` containing information about whether each
    * number up to `n` is prime or not. Additionally, the function populates the global vector `allPrimes`
    * with all the prime numbers up to `n`.
    */
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int32_t i = 2; (i * i) <= n; ++i)
        if (isPrime[i])
            for (int j = (i * i); j <= n; j += i)
                isPrime[j] = false;
    for (int32_t i = 2; i <= n; ++i)
        if (isPrime[i])
            allPrimes.push_back(i);
    return isPrime;
}

const int power(int n, int expo, const int MOD = 1e9 + 7) {
    /**
    * This is a function to calculate the power of a number modulo a given value using binary
    * exponentiation.
    *
    * @param n The base number that we want to raise to a power.
    * @param expo The exponent to which the base number 'n' is raised to.
    * @param MOD MOD is a constant integer value that is used as the modulus in the function. It is set to
    * 1e9 + 7 by default, but can be changed to any other value as per the requirement of the problem. The
    * function uses modular arithmetic to prevent integer overflow while computing the power of
    *
    * @return The function `power` returns an integer value which is the result of raising the integer `n`
    * to the power of `expo` modulo `MOD`.
    */
    int ans = 1; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

const int invMod(int n, const int MOD = 1e9 + 7) {
    /**
    * The function calculates the modular inverse of a number using the extended Euclidean algorithm.
    *
    * @param n The number for which we want to find the modular inverse.
    * @param MOD MOD is a constant integer that represents the modulus value used in modular arithmetic
    * operations. In this specific function, it is set to 1e9 + 7, which is a commonly used prime number
    * for modulo operations in competitive programming.
    *
    * @return The function `invMod` returns the modular inverse of the input integer `n` with respect to
    * the given modulus `MOD`.
    */
    int ans = 1, expo = MOD - 2; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

const int bS(const vector<int> &arr, const int t, int l = 0, int r = -1) {
    /**
    * This is a binary search function that returns the index of the target element in a sorted vector or
    * -1 if it is not found.
    *
    * @param arr a constant reference to a vector of integers that we want to search in.
    * @param t The target value that we are searching for in the given sorted vector 'arr'.
    * @param l The starting index of the subarray being searched. By default, it is set to 0, which means
    * the search starts from the beginning of the array.
    * @param r The parameter "r" is the index of the rightmost element of the subarray being searched. If
    * it is not provided as an argument, it is initialized to the index of the last element in the input
    * vector "arr".
    *
    * @return The function `bS` returns the index of the element `t` in the given vector `arr`. If the
    * element is not found, it returns -1.
    */
    if (r == -1)
        r = (arr.size() - 1);
    while (l <= r) {
        const int mid = (l + r) >> 1;
        if (arr[mid] == t)
            return mid;
        else if (arr[mid] > t)
            r = (mid - 1);
        else
            l = (mid + 1);
    }
    return ((arr[l] == t) ? l : ((arr[r] == t) ? r : -1));
}

const int lB(const vector<int> &arr, const int t, int l = 0, int r = -1) {
    /**
    * This is a binary search function that returns the index of the last element in a sorted vector that
    * is less than a given target value.
    *
    * @param arr a constant reference to a vector of integers that we want to search in.
    * @param t The target value that we are searching for in the vector.
    * @param l The starting index of the search range in the vector. It has a default value of 0 if not
    * specified.
    * @param r The parameter "r" is the index of the rightmost element of the subarray being considered.
    * If it is not provided as an argument, it is set to the index of the last element of the input vector
    * "arr".
    *
    * @return the index of the last element in the sorted vector `arr` that is less than `t`, or `-1` if
    * all elements in the vector are greater than or equal to `t`.
    */
    if (r == -1)
        r = (arr.size() - 1);
    if (arr[l] >= t)
        return l - 1;
    if (arr[r] < t)
        return r;
    int ans = l - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= t) r = (mid - 1);
        else ans = mid, l = (mid + 1);
    }
    return ans;
}

const int uB(const vector<int> &arr, const int t, int l = 0, int r = -1) {
    /**
    * The function returns the upper bound index of a target value in a sorted vector.
    *
    * @param arr a constant reference to a vector of integers that we want to search in.
    * @param t The target value that we are trying to find the upper bound for in the given vector.
    * @param l The starting index of the subarray being searched. By default, it is set to 0, which means
    * the entire array is being searched.
    * @param r The parameter "r" is the index of the rightmost element of the subarray being considered.
    * If it is not provided as an argument, it is initialized to the index of the last element of the
    * input vector "arr".
    *
    * @return The function `uB` returns the index of the first element in the sorted vector `arr` that is
    * greater than `t`, or `arr.size()` if all elements in the vector are less than or equal to `t`.
    */
    if (r == -1)
        r = (arr.size() - 1);
    if (t < arr[l])
        return l;
    if (t > arr[r])
        return r + 1;
    int ans = r + 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] <= t) l = (mid + 1);
        else ans = mid, r = (mid - 1);
    }
    return ans;
}

struct ListNode {
    /**
    * This code defines a struct for a singly linked list node in C++.
    */
    int val;
    /**
    * @property {int} val - The value stored in the current node of the linked list.
    */
    ListNode *next;
    /**
    * @property {ListNode} next - `next` is a pointer to the next node in a linked list. It is a member
    * variable of the `ListNode` struct, which represents a single node in a linked list. The `next`
    * pointer points to the next node in the list, or is set to `nullptr` if the
    */
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct disJointSet {
    /**
    * This is a C++ implementation of a disjoint set data structure.
    */
    vector<int> parent;
    /**
    * @property parent - A vector that stores the parent of each element in the disjoint set. Initially,
    * each element is its own parent.
    */
    disJointSet(int n): parent(vector<int>(n)) {
        iota(parent.begin(), parent.end(), 0);
    }
    const int find(const int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    const bool unionSet(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[x] = y;
        return true;
    }
};

struct TreeNode {
    /**
    * This is a C++ struct representing a binary tree node with methods for in-order, pre-order, and
    * post-order traversal.
    */
    int val;
    /**
    * @property {int} val - an integer value representing the node's value.
    */
    TreeNode *left, *right;
    /**
    * @property {TreeNode} left - A pointer to the left child node of the current node in a binary tree.
    * @property {TreeNode} right - A pointer to the right child node of a binary tree node in a TreeNode
    * struct. If there is no right child, it is set to nullptr.
    */
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void inOrder(function<void(int)> f = [&](int x) {cout << x << ' ';}) {
        /**
        * The function performs an in-order traversal of a binary tree and applies a given function to
        * each node's value.
        *
        * @param f f is a function parameter that takes an integer as input and returns nothing (void). It
        * is a default parameter that is initialized with a lambda function that prints the integer value
        * followed by a space character. This lambda function can be overridden by passing a different
        * function as an argument to the inOrder function.
        */
        if (left) left->inOrder(f);
        f(val);
        if (right) right->inOrder(f);
    }

    void preOrder(function<void(int)> f = [&](int x) {cout << x << ' ';}) {
        /**
        * This is a pre-order traversal function for a binary tree that takes a function as an argument to
        * perform an operation on each node.
        *
        * @param f "f" is a function parameter that takes a function as an argument. The default value of
        * this parameter is a lambda function that prints the value of the current node in a binary tree
        * followed by a space. This lambda function can be replaced with any other function that takes an
        * integer as input and returns void
        */
        f(val);
        if (left) left->preOrder(f);
        if (right) right->preOrder(f);
    }

    void postOrder(function<void(int)> f = [&](int x) {cout << x << ' ';}) {
        /**
        * This is a recursive function that performs a post-order traversal of a binary tree and applies a
        * given function to each node's value.
        *
        * @param f f is a function object that takes an integer parameter and returns void. It is a
        * default parameter with a lambda function that prints the integer value followed by a space. This
        * function is used to perform an action on each node during a post-order traversal of a binary
        * tree. If no function is provided,
        */
        if (left) left->postOrder(f);
        if (right) right->postOrder(f);
        f(val);
    }
};

struct Graph {
    /**
    * This is a C++ implementation of a graph data structure with various graph algorithms such as BFS,
    * DFS, Floyd-Warshall, Dijkstra, Bellman-Ford, MST, and topological sort.
    */
    vector<vector<int>> adj, edges;
    /**
    * @property adj - A vector of vectors representing the adjacency list of the graph. Each element of
    * the outer vector represents a vertex, and the inner vector contains the indices of the vertices that
    * are adjacent to it.
    * @property edges - A vector of vectors representing the edges of the graph. Each inner vector
    * contains three integers: the weight of the edge (default 1), the starting vertex, and the ending
    * vertex.
    */
    map<pair<int, int>, int> weight;
    /**
    * @property weight - A map that stores the weight of each edge in the graph. The key of the map is a
    * pair of integers representing the two vertices that the edge connects, and the value is the weight
    * of the edge.
    */
    vector<int> indegree, outdegree;
    /**
    * @property indegree - A vector that stores the indegree of each vertex in the graph. The indegree of
    * a vertex is the number of incoming edges to that vertex.
    * @property outdegree - The outdegree of a vertex in a directed graph is the number of edges that
    * originate from that vertex, i.e., the number of edges that have that vertex as their starting point.
    */
    Graph(int n) : adj(vector<vector<int>>(n)), indegree(vector<int>(n)), outdegree(vector<int>(n)) {}

    void addEdge(int u, int v, int w = 1) {
        /**
        * This function adds an edge between two vertices in a graph with an optional weight parameter.
        *
        * @param u The source vertex of the edge being added.
        * @param v v is an integer representing the destination vertex of the edge being added to the
        * graph.
        * @param w The weight of the edge between vertices u and v. It is an optional parameter with a
        * default value of 1 if not specified.
        */
        adj[u].push_back(v);
        edges.push_back({w, u, v});
        weight[ {u, v} ] = w;
        ++outdegree[u];
        ++indegree[v];
    }

    void addUEdge(int u, int v, int w = 1) {
        /**
        * The function adds an undirected edge between two vertices with an optional weight.
        *
        * @param u The first vertex of the undirected edge to be added.
        * @param v v is an integer representing one of the vertices in the undirected edge being added.
        * @param w The parameter "w" represents the weight of the edge between vertices "u" and "v". It is
        * an optional parameter with a default value of 1, which means that if no weight is specified
        * while calling the function, the weight of the edge will be considered as 1.
        */
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    void addUEdge(const vector<vector<int>> &edges) {
        /**
        * The function adds undirected edges to a graph represented by an adjacency list.
        *
        * @param edges `edges` is a vector of vectors that represents the edges of a graph. Each inner
        * vector contains either two or three integers, depending on whether the graph is weighted or
        * unweighted. If the graph is unweighted, each inner vector contains two integers representing the
        * endpoints of an edge. If the graph
        *
        * @return If the input vector `edges` is empty, the function returns without doing anything.
        */
        if (edges.empty()) return;
        if (edges[0].size() == 2)
            for (auto &e : edges)
                addUEdge(e[0], e[1]);
        else
            for (auto &e : edges)
                addUEdge(e[0], e[1], e[2]);
    }

    void addEdge(const vector<vector<int>> &edges) {
        /**
        * The function adds edges to a graph based on the input vector of edges.
        *
        * @param edges A vector of vectors representing the edges of a graph. Each inner vector contains
        * either two or three integers, depending on whether the graph is weighted or unweighted. If the
        * graph is unweighted, each inner vector contains two integers representing the source and
        * destination vertices of an edge. If the graph is weighted
        *
        * @return If the input vector `edges` is empty, the function returns without doing anything.
        */
        if (edges.empty()) return;
        if (edges[0].size() == 2)
            for (auto &e : edges)
                addEdge(e[0], e[1]);
        else
            for (auto &e : edges)
                addEdge(e[0], e[1], e[2]);
    }

    void bfs(int src = 0, function<void(int)> f = [&](int x) {cout << x << ' ';}) {
        /**
        * The function performs a breadth-first search on a graph starting from a given source node and
        * applies a given function to each visited node.
        *
        * @param src The starting vertex for the breadth-first search algorithm. It is set to 0 by default
        * if no value is provided when calling the function.
        * @param f f is a function parameter that takes an integer as input and returns nothing (void). It
        * is a lambda function with a default value that prints the integer value to the console followed
        * by a space. This function is called for each vertex visited during the breadth-first search
        * traversal. However, the user can provide
        */
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

    void dfs(int src = 0, function<void(int)> f = [&](int x) {cout << x << ' ';}) {
        /**
        * This is a depth-first search function that visits all nodes in a graph starting from a given
        * source node and applies a given function to each visited node.
        *
        * @param src The starting vertex for the depth-first search algorithm. It defaults to 0 if no
        * value is provided.
        * @param f f is a function object that takes an integer as input and returns nothing. It is used
        * to perform some action on each vertex during the depth-first search traversal. By default, it
        * prints the vertex number to the console. However, it can be customized by passing a different
        * function object as an argument to
        */
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
        /**
        * The function implements the Floyd-Warshall algorithm to find the shortest path between all pairs
        * of vertices in a graph.
        *
        * @return The function `floydWarshall` returns a 2D vector `dist` which contains the shortest
        * distances between all pairs of vertices in the given graph.
        */
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
        /**
        * This is an implementation of Dijkstra's algorithm for finding the shortest path from a source
        * node to all other nodes in a weighted graph.
        *
        * @param src The source vertex from which the shortest distances are to be calculated. The default
        * value is 0, which means that the algorithm will start from vertex 0 if no source vertex is
        * specified.
        *
        * @return The function `dijkstra` returns a vector of integers representing the shortest distance
        * from the source node to all other nodes in the graph.
        */
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
        /**
        * This function implements the Bellman-Ford algorithm to find the shortest path from a source node
        * to all other nodes in a graph.
        *
        * @param src The source vertex from which the shortest path is to be calculated. If no source
        * vertex is provided, the default value is 0.
        *
        * @return The function `bellmanFord` returns a vector of integers representing the shortest
        * distance from the source node to all other nodes in the graph.
        */
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
        /**
        * The function implements Kruskal's algorithm to find the minimum spanning tree of a graph
        * represented as an adjacency list.
        *
        * @return The function `mst()` returns a vector of vectors representing the minimum spanning tree
        * of a given graph. Each inner vector represents the edges of the tree connected to a particular
        * vertex.
        */
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
        /**
        * The function performs a topological sort on a directed acyclic graph represented by adjacency
        * list and returns the sorted order.
        *
        * @return The function `topoSort()` returns a vector of integers representing the topological
        * order of the nodes in a directed acyclic graph (DAG). The order represents a linear ordering of
        * the nodes such that for every directed edge (u, v), node u comes before node v in the ordering.
        */
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
};


int main() {return 0;}
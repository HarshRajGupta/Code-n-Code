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
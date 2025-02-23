void bfs(const Graph& graph, int origin) {
    int num_vertices = graph.size();
    vector<bool> enqueued(num_vertices, false);
    queue<int> q;

    // Marcar el vértice de origen como encolado y encolarlo
    enqueued[origin] = true;
    q.push(origin);

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        // Procesar el vértice actual (por ejemplo, imprimirlo)
        cout << "Vértice visitado: " << current_vertex << endl;

        // Explorar los vértices adyacentes al vértice actual
        for (int neighbor : graph[current_vertex]) {
            if (!enqueued[neighbor]) {
                enqueued[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
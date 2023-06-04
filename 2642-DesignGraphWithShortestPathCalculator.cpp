class Graph {
public:
	Graph(int n, std::vector<std::vector<int>>& edges) {
		graph.resize(n);

		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].insert({ edges[i][2], edges[i][1] });
		}

	}
	void addEdge(std::vector<int> edge) {

		graph[edge[0]].insert({ edge[2], edge[1] });

	}

	int shortestPath(int node1, int node2) {

		std::vector<int> distances(graph.size(), INT_MAX);
		std::queue<int> node_queue;
		int current_node = 0;

		distances[node1] = 0;
		node_queue.push(node1);
		
		while (!node_queue.empty()) {

			current_node = node_queue.front();
			node_queue.pop();

			for (auto& node : graph[current_node]) {

				if (distances[node.second] > distances[current_node] + node.first) {
					distances[node.second] = distances[current_node] + node.first;
					node_queue.push(node.second);
				}
			}
		}

		return (distances[node2] == INT_MAX) ? -1 : distances[node2];
	}

private:
	std::vector<std::set<std::pair<int, int>>> graph;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

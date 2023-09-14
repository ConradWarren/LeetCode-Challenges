class Solution {
public:
void Build_Itinerary(std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph, std::vector<std::string>& current,int target, std::vector<bool>& used_edges, std::vector<std::string>& result){
	
	if (!result.empty()) {
		return;
	}

	if (target == 0) {
		result = current;
		return;
	}

	std::string city = current.back();

	for (int i = 0; i < graph[city].size(); i++) {

		if (used_edges[graph[city][i].second]) {
			continue;
		}
		used_edges[graph[city][i].second] = true;
		current.push_back(graph[city][i].first);
		Build_Itinerary(graph, current, target - 1, used_edges, result);
		current.pop_back();
		used_edges[graph[city][i].second] = false;
	}

}


std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
	
	std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph;
	std::vector<std::string> result;
	std::vector<std::string> current = {"JFK"};
	std::vector<bool> used_edges(tickets.size(), false);
	int edge_count = tickets.size();

	for (int i = 0; i < tickets.size(); i++) {
		graph[tickets[i][0]].push_back({tickets[i][1], i });
	}

	for (auto& city_node : graph) {
		std::sort(city_node.second.begin(), city_node.second.end());
	}

	Build_Itinerary(graph, current, edge_count, used_edges, result);

	return result;
}
};

std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
	
	std::vector<std::pair<int, int>> sortable_queries(queries.size());
	std::unordered_map<int, int> servers_request_counts;
	std::vector<int> result(queries.size());
	int current_server_count = 0;
	int idx_front = 0; 
	int idx_back = 0;

	for (int i = 0; i < sortable_queries.size(); i++) {
		sortable_queries[i].first = queries[i];
		sortable_queries[i].second = i;
	}

	std::sort(sortable_queries.begin(), sortable_queries.end());
	std::sort(logs.begin(),	logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[1] < b[1]; });

	for (int i = 0; i < sortable_queries.size(); i++) {

		while (idx_front < logs.size() && logs[idx_front][1] <= sortable_queries[i].first) {
			servers_request_counts[logs[idx_front][0]]++;
			current_server_count += (servers_request_counts[logs[idx_front][0]] == 1) ? 1 : 0;
			idx_front++;
		}

		while (idx_back < logs.size() && logs[idx_back][1] < sortable_queries[i].first - x) {
			servers_request_counts[logs[idx_back][0]]--;
			current_server_count -= (servers_request_counts[logs[idx_back][0]] == 0) ? 1 : 0;
			idx_back++;
		}
		result[sortable_queries[i].second] = n - current_server_count;
	}
	
	return result;
}

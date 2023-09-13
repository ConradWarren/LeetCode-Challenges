class Solution {
public:

int candy(std::vector<int>& ratings) {

	if (ratings.size() == 1) {
		return 1;
	}

	std::vector<int> distributed_candy(ratings.size(), -1);
	std::queue<int> node_queue;
	int current_node = 0;


	if (ratings[0] <= ratings[1]) {
		distributed_candy[0] = 1;
		node_queue.push(0);
	}

	if (ratings.back() <= ratings[ratings.size() - 2]) {
		distributed_candy.back() = 1;
		node_queue.push(ratings.size() - 1);
	}

	for (int i = 1; i < distributed_candy.size() - 1; i++) {
		if (ratings[i] <= ratings[i + 1] && ratings[i] <= ratings[i - 1]) {
			distributed_candy[i] = 1;
			node_queue.push(i);
		}
	}

	while (!node_queue.empty()){

		current_node = node_queue.front();
		node_queue.pop();
		

		if (current_node != 0 && ratings[current_node - 1] > ratings[current_node]) {
			node_queue.push(current_node - 1);
			distributed_candy[current_node - 1] = distributed_candy[current_node] + 1;
		}
		
		if (current_node + 1 < ratings.size() && ratings[current_node + 1] > ratings[current_node]) {
			node_queue.push(current_node + 1);
			distributed_candy[current_node + 1] = distributed_candy[current_node] + 1;
		}
	}

	return std::accumulate(distributed_candy.begin(), distributed_candy.end(), 0);
}
};

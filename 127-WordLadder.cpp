#include <vector>
#include <string>

class Solution {
public:
int Breadth_First_Search(std::vector<std::vector<int>>& graph, int target) {

	std::vector<bool> visted(graph.size(), false);
	std::queue<std::pair<int, int>> node_queue;
	int current_node = 0;
	int distance = 0;

	node_queue.push({graph.size()-1, 1});
	visted[graph.size() - 1] = true;

	while (!node_queue.empty()) {

		current_node = node_queue.front().first;
		distance = node_queue.front().second;
		node_queue.pop();

		for (int i = 0; i < graph[current_node].size(); i++) {

			if (visted[graph[current_node][i]]) continue;
			
			if (graph[current_node][i] == target) return distance + 1;
			
			node_queue.push({ graph[current_node][i], distance + 1 });

			visted[graph[current_node][i]] = true;
		}
	}
	return -1;
}

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {

	wordList.push_back(beginWord);

	std::vector<std::vector<int>> graph(wordList.size());
	int target = -1;

	for (int i = 0; i < wordList.size(); i++) {

		if (wordList[i] == endWord) target = i;
		
		for (int j = i+1; j < wordList.size(); j++) {

			int conflicts = 0;
			for (int z = 0; z < wordList[j].length(); z++) {

				if (wordList[j][z] != wordList[i][z]) {
					conflicts++;
					if (conflicts > 1) break;
				}
			}

			if (conflicts == 1) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	if (target == -1) return 0;
	
	int result = Breadth_First_Search(graph, target);

	return (result != -1) ? result : 0;
}
};

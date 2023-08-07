#include <vector>
#include <priority_queue>

class Solution {
public:
long long findMaximumElegance(std::vector<std::vector<int>>& items, int k) {
	
	std::vector<int> catagories(items.size()+1, 0);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	long long total_profit = 0;
	long long unique_catagories = 0;
	long long max_score = 0;

	std::sort(items.rbegin(), items.rend());
	
	for (int i = 0; i < k; i++) {
		catagories[items[i][1]]++;
		if (catagories[items[i][1]] == 1) {
			unique_catagories++;
		}
		total_profit += items[i][0];
		pq.push({ items[i][0], items[i][1] });
	}
	max_score = total_profit + (unique_catagories * unique_catagories);
	
	for (int i = k; i < items.size(); i++) {

		if (catagories[items[i][1]]) {
			continue;
		}

		while (!pq.empty() && catagories[pq.top().second] == 1) {
			pq.pop();
		}

		if (pq.empty()) {
			break;
		}

		total_profit -= pq.top().first;
		total_profit += items[i][0];
		unique_catagories++;
		catagories[items[i][1]]++;
		catagories[pq.top().second]--;
		pq.pop();
		max_score = (max_score > total_profit + (unique_catagories * unique_catagories)) ? max_score : total_profit + (unique_catagories * unique_catagories);
	}

	return max_score;
}
};

#include <vector>

class Solution {
public:
int miceAndCheese(std::vector<int>& reward1, std::vector<int>& reward2, int k) {

	int sum = std::accumulate(reward2.begin(), reward2.end(), 0);

	for (int i = 0; i < reward1.size(); i++) {
		reward1[i] -= reward2[i];
	}

	std::sort(reward1.rbegin(), reward1.rend());

	for (int i = 0; i < k; i++) {
		sum += reward1[i];
	}


	return sum;
}
};

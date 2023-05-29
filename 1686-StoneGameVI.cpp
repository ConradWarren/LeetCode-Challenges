#include <vector>

class Solution {
public:
int stoneGameVI(std::vector<int>& aliceValues, std::vector<int>& bobValues) {

	std::vector<std::pair<int, int>> stones(aliceValues.size());
	int allice_score = 0;
	int bob_score = 0;

	for (int i = 0; i < stones.size(); i++) {
		stones[i].first = aliceValues[i] + bobValues[i];
		stones[i].second = i;
	}
	std::sort(stones.rbegin(), stones.rend());

	for (int i = 0; i < stones.size(); i++) {

		if (i % 2 == 0) {
			allice_score += aliceValues[stones[i].second];
		}
		else {
			bob_score += bobValues[stones[i].second];
		}
	}

	if (allice_score == bob_score) return 0;

	return (allice_score > bob_score) ? 1 : -1;
}
};

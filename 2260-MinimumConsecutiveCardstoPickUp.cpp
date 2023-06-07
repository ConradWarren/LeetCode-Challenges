#include <vector>
#include <unordered_map>

class Solution {
public:
int minimumCardPickup(std::vector<int>& cards) {

	std::unordered_map<int, int> card_idx;
	int result = INT_MAX;
	for (int i = 0; i < cards.size(); i++) {

		if (card_idx.find(cards[i]) == card_idx.end()) {
			card_idx[cards[i]] = i;
		}
		else {
			result = (result < (i - card_idx[cards[i]] + 1)) ? result : (i - card_idx[cards[i]] + 1);
			card_idx[cards[i]] = i;
		}

	}

	return (result == INT_MAX) ? -1 : result;
}
};

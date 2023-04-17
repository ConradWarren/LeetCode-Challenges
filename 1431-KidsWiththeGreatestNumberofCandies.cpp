#include <vector>

class Solution {
public:
std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {

	std::vector<bool> result(candies.size(), false);
	int highest = candies[0];

	for (int i = 1; i < candies.size(); i++) {
		highest = max(highest, candies[i]);
	}

	for (int i = 0; i < candies.size(); i++) {
		if (candies[i] + extraCandies >= highest) result[i] = true;
	}

	return result;
}
};

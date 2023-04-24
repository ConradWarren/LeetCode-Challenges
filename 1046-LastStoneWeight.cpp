#include <vector>

int lastStoneWeight(std::vector<int>& stones) {

	std::sort(stones.rbegin(), stones.rend());

	while (stones.size() > 1) {

		int current = stones[0] - stones[1];
		
		stones.erase(stones.begin());
		stones.erase(stones.begin());

		if (current != 0) {
			bool inserted_flag = false;
			for (int i = 0; i < stones.size(); i++) {

				if (stones[i] <= current) {
					inserted_flag = true;
					stones.insert(stones.begin() + i, current);
					break;
				}

			}
			if (!inserted_flag) {
				stones.push_back(current);
			}
		}
	}

	return (stones.empty()) ? 0 : stones[0];
}

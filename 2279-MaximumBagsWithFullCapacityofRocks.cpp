#include <vector>

int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks) {

	std::vector<int> offsets(capacity.size());
	int count = 0;

	for (int i = 0; i < offsets.size(); i++) {
		offsets[i] = capacity[i] - rocks[i];
	}
	std::sort(offsets.begin(), offsets.end());

	for (int i = 0; i < offsets.size(); i++) {

		if (offsets[i] > 0 && offsets[i] <= additionalRocks) {
			additionalRocks -= offsets[i];
			offsets[i] = 0;
		}

		if (offsets[i] == 0) count++;
		
		else break;
	}

	return count;
}

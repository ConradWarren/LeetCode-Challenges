class SmallestInfiniteSet {
public:

	int smallest;
	std::vector<int> added_nums;

	SmallestInfiniteSet() {
		smallest = 1;
		added_nums = {};
	}

	int popSmallest() {

		if (added_nums.empty()) {
			smallest++;
			return smallest - 1;
		}

		int result = added_nums.front();
		added_nums.erase(added_nums.begin());
		return result;
	}

	void addBack(int num) {

		if (num >= smallest) return;
		
		bool added_num_flag = false;

		for (int i = 0; i < added_nums.size(); i++) {

			if (added_nums[i] == num) {
				added_num_flag = true;
				break;
			}

			if (added_nums[i] > num) {
				added_num_flag = true;
				added_nums.insert(added_nums.begin() + i, num);
				break;
			}
		}

		if (!added_num_flag) added_nums.push_back(num);
		
		while (!added_nums.empty() && added_nums.back() + 1 == smallest) {
			smallest--;
			added_nums.pop_back();
		}
	}
};

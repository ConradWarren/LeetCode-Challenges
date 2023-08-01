#include <vector>

class SummaryRanges {
public:
	SummaryRanges() {
		nums.resize(10002, false);
		num_count = 0;
		largest_num = 0;
	}

	void addNum(int value) {
		
		if (nums[value]) {
			return;
		}

		nums[value] = true;
		num_count++;
		largest_num = (largest_num > value) ? largest_num : value;
	}

	std::vector<std::vector<int>> getIntervals() {

		std::vector<std::vector<int>> result;
		bool valid_range_flag = false;
		int range_start = 0;
		

		for (int i = 0; i <= largest_num+1; i++) {

			if (nums[i] && !valid_range_flag) {
				range_start = i;
				valid_range_flag = true;
			}
			else if (!nums[i] && valid_range_flag) {
				result.push_back({ range_start, i - 1 });
				valid_range_flag = false;
			}
		}

		return result;
	}

private:
	int num_count;
	std::vector<bool> nums;
	int largest_num;
};

#include <priority_queue>

class MedianFinder {
public:

	void addNum(int num) {

		if (left_nums.size() == 0 && right_nums.size() == 0) {
			left_nums.push(num);
			return;
		}

		if (num < left_nums.top()) left_nums.push(num);
		
		else right_nums.push(num);
	
		while (left_nums.size() > right_nums.size() + 1) {
			right_nums.push(left_nums.top());
			left_nums.pop();
		}

		while (right_nums.size() > left_nums.size()) {
			left_nums.push(right_nums.top());
			right_nums.pop();
		}
	}

	double findMedian() {

		if (left_nums.size() > right_nums.size()) {
			return left_nums.top();
		}

		double result = left_nums.top() + right_nums.top();

		result /= 2;

		return result;
	}
private:
	std::priority_queue<int> left_nums;
	std::priority_queue<int, std::vector<int>, std::greater<int>> right_nums;
};

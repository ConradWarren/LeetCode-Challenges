#include <vector>

class Solution {
public:
double average(std::vector<int>& salary) {

	int largest = INT_MIN;
	int smallest = INT_MAX;

	for (int i = 0; i < salary.size(); i++) {
		largest = (largest > salary[i]) ? largest : salary[i];
		smallest = (smallest < salary[i]) ? smallest : salary[i];
	}

	int sum = std::accumulate(salary.begin(), salary.end(), 0) - largest - smallest;

	double average = sum / double(salary.size() - 2);

	return average;
}
};

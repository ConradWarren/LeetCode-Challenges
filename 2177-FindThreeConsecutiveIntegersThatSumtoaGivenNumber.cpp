class Solution {
public:
std::vector<long long> sumOfThree(long long num) {


	std::vector<long long> result(3, 0);

	num -= 3;
	if (num % 3 != 0) {
		return {};
	}
	num /= 3;
	result[0] = num;
	result[1] = num+1;
	result[2] = num+2;

	return result;
}
};

class Solution {
public:
int divide(int dividend_input, int divisor_input) {

	long dividend = dividend_input;
	long divisor = divisor_input;
	long result = 0;
	int idx = 0;
	bool negaitive_flag = false;

	if (dividend < 0 && divisor < 0) negaitive_flag = false;
	
	else if (dividend < 0 || divisor < 0) negaitive_flag = true;
	
	dividend = std::abs(dividend);
	divisor = std::abs(divisor);

	while (dividend >= divisor) {

		idx = 0;
		while ((divisor << (idx + 1)) <= dividend) {
			idx++;
		}
		result += std::pow(2, idx);
		dividend -= (divisor << idx);
	}
	
	if (!negaitive_flag && result > 2147483647) result = 2147483647;
	
	return (negaitive_flag) ? -result : result;
}
};

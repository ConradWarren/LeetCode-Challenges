class Solution {
public:
int minSteps(int n) {

	int result = 0;

	int idx = 2;
	while (n > 1) {
		if (n % idx == 0) {
			result += idx;
			n /= idx;
		}
		else {
			idx++;
		}
	}


	return result;
}
};

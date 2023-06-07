class Solution {
public:
int minFlips(int a, int b, int c) {

	int bitmask = (a | b);
	int idx = 0;
	int result = 0;
	
	while ((1 << idx) <= c || (1 << idx) <= bitmask) {

		if ((c & (1 << idx)) != (bitmask & (1 << idx)) && (c & (1 << idx))) {
			result++;
		}
		else if ((c & (1 << idx)) != (bitmask & (1 << idx))){
			result += (a & (1 << idx)) ? 1 : 0;
			result += (b & (1 << idx)) ? 1 : 0;
		}
		idx++;
	}

	return result;
}
};

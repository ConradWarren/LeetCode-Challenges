#include <string>

class Solution {
public:

int maxConsecutiveAnswers(std::string answerKey, int k) {
	
	int back_idx = 0;
	int result = 0;
	int t_count = 0;
	int f_count = 0;

	for (int i = 0; i < answerKey.length(); i++) {

		if (answerKey[i] == 'T') {
			t_count++;
		}
		else {
			f_count++;
		}

		while (min(t_count, f_count) > k) {
			
			if (answerKey[back_idx] == 'T') {
				t_count--;
			}
			else {
				f_count--;
			}
			back_idx++;
		}

		result = (result > i - back_idx + 1) ? result : i - back_idx + 1;

	}

	return result;
}
};

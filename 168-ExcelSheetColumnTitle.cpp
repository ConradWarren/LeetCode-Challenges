#include <string>

class Solution {
public:
std::string convertToTitle(int columnNumber) {

	std::string result;
	while (columnNumber > 0){
		result += (columnNumber % 26) ? (columnNumber % 26)-1 + 'A' : 'Z';
		columnNumber -= result.back() - 'A' + 1;
		columnNumber /= 26;
	}
	std::reverse(result.begin(), result.end());
	return result;
}
};

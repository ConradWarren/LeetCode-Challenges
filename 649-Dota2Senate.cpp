#include <string>
#include <queue>

class Solution {
public:
std::string predictPartyVictory(std::string senate) {
	
	std::queue<int> r_que;
	std::queue<int> d_que;
	int off_set = senate.length();

	for (int i = 0; i < senate.size(); i++) {
		if (senate[i] == 'R') r_que.push(i);
		
		else d_que.push(i);
	}

	while (!r_que.empty() && !d_que.empty()) {

		if (r_que.front() < d_que.front()) {
			d_que.pop();
			r_que.push(r_que.front() + off_set);
			r_que.pop();
		}
		else {
			r_que.pop();
			d_que.push(d_que.front() + off_set);
			d_que.pop();
		}

	}

	return (r_que.empty()) ? "Dire" : "Radiant";
}
};

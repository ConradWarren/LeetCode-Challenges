#include <vector>
#include <string>
#include <string>

class Solution {
public:
std::vector<int> topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback, std::vector<std::string>& report, std::vector<int>& student_id, int k) {

	std::vector<std::pair<int, int>> ranked_students(student_id.size());
	std::vector<int> result(k);
	std::vector<std::vector<std::string>> words(report.size());
	std::string current_word;
	std::unordered_map<std::string, int> feedback_map;
	int score = 0;

	for (int i = 0; i < positive_feedback.size(); i++) {
		feedback_map[positive_feedback[i]] = 3;
	}
	for (int i = 0; i < negative_feedback.size(); i++) {
		feedback_map[negative_feedback[i]] = -1;
	}

	for (int i = 0; i < report.size(); i++) {

		for (int j = 0; j < report[i].length(); j++) {

			if (report[i][j] == ' ' && !current_word.empty()) {
				words[i].push_back(current_word);
				current_word.clear();
			}
			else if (report[i][j] != ' ') current_word += report[i][j];
		}

		if (!current_word.empty()) {
			words[i].push_back(current_word);
			current_word.clear();
		}

	}

	for (int i = 0; i < words.size(); i++) {
		score = 0;
		for (int j = 0; j < words[i].size(); j++) {

			if (feedback_map.find(words[i][j]) != feedback_map.end()) score += feedback_map[words[i][j]];

		}
		ranked_students[i] = { score, -student_id[i] };
	}

	std::sort(ranked_students.rbegin(), ranked_students.rend());

	for (int i = 0; i < k; i++) {
		result[i] = -ranked_students[i].second;
	}

	return result;
}
};

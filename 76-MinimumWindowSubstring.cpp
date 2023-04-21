bool Valid_Window(std::unordered_map<char, int>& s_occurances, std::unordered_map<char, int>& t_occurances) {


	for (auto& letter : t_occurances) {
		
		if (s_occurances[letter.first] < letter.second) {
			return false;
		}

	}

	return true;
}

std::string minWindow(std::string s, std::string t) {

	bool valid_flag = false;
	int smallest_window_start = 0;
	int smallest_window_length = s.length();
	int back_idx = 0;

	std::unordered_map<char, int> t_occurances;
	std::unordered_map<char, int> s_occurances;

	for (int i = 0; i < t.length(); i++) {
		t_occurances[t[i]]++;
	}

	for (int i = 0; i < s.length(); i++) {

		s_occurances[s[i]]++;

		if (t_occurances.find(s[i]) != t_occurances.end() && Valid_Window(s_occurances, t_occurances)) {

			valid_flag = true;

			while (back_idx <= i) {

				if (smallest_window_length > (i - back_idx + 1)) {
					smallest_window_length = (i - back_idx + 1);
					smallest_window_start = back_idx;
				}

				s_occurances[s[back_idx]]--;

				if (t_occurances.find(s[back_idx]) != t_occurances.end() && s_occurances[s[back_idx]] < t_occurances[s[back_idx]]) {
					back_idx++;
					break;
				}
				back_idx++;
			}


		}

	}

	if (!valid_flag) {
		return "";
	}
	return s.substr(smallest_window_start, smallest_window_length);
}
};

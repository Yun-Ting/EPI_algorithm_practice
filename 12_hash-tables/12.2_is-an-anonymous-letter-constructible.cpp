// 12.2_is-an-anonymous-letter-constructible.cpp

bool IsLetterConstructibleFromMagazine(const string& letter_text, const string& magazine_text) {
	unordered_map<char, int> char_to_freq;
	for (char c : letter_text) {
		++magazine_text[c];
	}
	for (char c : magazine_text) {
		auto it = char_to_freq.find(c);
		if (it != char_to_freq.end()) {
			--it->second;
			if (it->second == 0) {
				char_to_freq.erase(it);
			}
			if (char_to_freq.empty()) {
				break;
			}
		}
	}
	return char_to_freq.empty();
}
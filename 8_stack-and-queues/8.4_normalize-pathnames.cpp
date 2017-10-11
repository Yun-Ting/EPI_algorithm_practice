// 8.4_normalize-pathnames.cpp
#include <vector>
#include <sstream>

string ShortestEquivalentPath(const string& path) {
	if (path.empty()) {
		throw invalid_argument("Empty string is not a valid path.");
	}
	vector<string> path_names; // uses vector as a stack

	// special case: starts with / -> an absolute path
	if (path.front() == '/') {
		path_names.emplace_back("/");
	}

	stringstream ss(path);
	string token;
	while(ss, token, '/') {
		if (token == "..") { 
			// for relative path
			if (path_names.empty() || path_names.back() == "..") {
				//已經回到相對路徑的頭了 || 代表已經回到這個相對路徑的頭的至少上面一層了
				path_names.emplace_back(token); // 所以要再繼續往上一層的話, 就要用..紀錄
			} else {
				if (path_names.back() == "/") {
					throw invalid_argument("path error");
				}
				path_names.pop_back();
			}
		} else if (token != "." && token != "") { // must be a name
			path_names.emplace_back(token);
		}
	}

	string result;
	if (!path_names.empty()) {
		result = path_names.front(); // vector of string .front() is a string
		for (int i = 1; i < path_names.size(); ++i) {
			if (i == 1 && result == "/") {
				result += path_names[i];
			} else {
				result += "/" + path_names[i];
			}
		}
	}
	return result;
}


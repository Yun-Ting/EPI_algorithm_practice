// // 128_longest-consecutive-sequence.cpp

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int, int> h;
//         for (int num : nums) {
//         	// 可能有重複的數字 直接略過 因為不重要
//         	if (h.count(num)) continue;

//         	auto it_l = h.find(num - 1);
//         	// 我左看右看, 看看有沒有鄰G
//         	auto it_r = h.find(num + 1);

//         	int l_len = it_l != h.end() ? it_l->second : 0; // 左邊連續的長度
//         	int r_len = it_r != h.end() ? it_r->second : 0;

//         	// 我是一條橋
//         	if (l_len > 0 && r_len > 0) {
//         		h[num] = h[num - l_len] = h[num + r_len] = l_len + r_len + 1;
//         	} else if (l_len > 0) {
//         		h[num] = h[num - l_len] = l_len + 1;
//         	} else if (r_len > 0) {
//         		h[num] = h[num + r_len] = r_len + 1;
//         	} else {
//         		h[num] = 1;
//         	}
//         }

//         int ans = 0;
//         for (const auto& kv : h) {
//         	ans = max(ans, kv.second);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
   		unordered_set<int> h(nums.begin(), nums.end());
   		int ans = 0;
   		for (int num : nums) {
   			if (!h.count(num - 1)) { // 我是最左邊界!
   				int l = 0;
   				while (h.count(num++)) ++l;
   				ans = max(ans, l);
   			}
   		}
   		return ans;
    }
};











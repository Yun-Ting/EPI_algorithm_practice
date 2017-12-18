class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	if (nums.size() <= 2) {
    		return {};
    	}
        
        vector<vector<int>> result;
    	sort(nums.begin(), nums.end());
    	size_t i = 0;
    	while (i < nums.size() - 2) {

    		int target = -nums[i];
    		size_t l = i + 1;
    		size_t r = nums.size() - 1;
    		
    		while (l < r) {
    			int sum = nums[l] + nums[r];
    			if (sum == target) {
    				vector<int> triplet = {nums[i], nums[l], nums[r]};
    				result.emplace_back(triplet);

    				while (l < r && nums[l] == triplet[1]) ++l;
    				while (l < r && nums[r] == triplet[2]) --r;
    			}
    			else if (sum < target) {
    				int old_front = nums[l];
    				while (nums[l] == old_front && l < r) ++l;
    			} else if (sum > target){
    				int old_back = nums[r];
    				while (nums[r] == old_back && l < r) --r;
    			}
            }

            int old_i = nums[i];
		    // 第一次會是自己跟自己比!
		    while (i < nums.size() - 2 && old_i == nums[i]) ++i;
    	}
    	return result;
    }    
};
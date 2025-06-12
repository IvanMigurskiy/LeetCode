/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>  

using namespace std;

vector<int> twoSum(vector<int>& nums, int taget);

int main()
{
	vector<int> nums {2, 7, 11, 15};
	vector<int> result = twoSum(nums, 9);
	cout << result[0] << "  " << result[1] << endl;
	
	return 0;
}


vector<int> twoSum(vector<int>& nums, int target){
	vector<int> nums_cp(nums.size());
	copy(nums.begin(), nums.end(), nums_cp.begin()); 
	sort(begin(nums_cp), end(nums_cp));

	int start = 0;
	int end = nums.size() - 1;
	int end_t = end;

	while(start<end){
		
		int sum = nums_cp[start]+nums_cp[end];
		if(sum > target)
			end--;
		else if(sum < target){
			end = end_t;
			start++;
		}
		else
			break;
	}
	int start_ind = distance(nums.begin(), find(nums.begin(), nums.end(), nums_cp[start]));

	int end_ind = 0;
	
	if (nums_cp[start] == nums_cp[end]){
		auto first_el = find(nums.begin(), nums.end(), nums_cp[end]);
		end_ind = distance(nums.begin(), find(first_el + 1, nums.end(), nums_cp[end]));
	}
	else
		end_ind = distance(nums.begin(), find(nums.begin(), nums.end(), nums_cp[end]));


	return vector<int>{start_ind, end_ind};
}



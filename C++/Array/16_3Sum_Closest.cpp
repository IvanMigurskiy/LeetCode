/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main()
{
	vector<int> nums {2,3,8,9,10};
	int target = 16;

	int result = threeSumClosest(nums, target);
	cout << result << endl;

	return 0;
}


int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int left = 0;
	int right = size - 1;
	int middle = 1;

	int closestSum = nums[0] + nums[1] + nums[2];

	while( left < size-2 ) {
		int t_lr = target - (nums[left] + nums[right]);
			
		while( right > left + 1 ) {		
			if( t_lr < nums[middle] ) {
				while( middle > left+1 && t_lr < nums[middle] )
					middle--;
				
				if ( t_lr < nums[middle] ) {
                    			if ( abs(t_lr - nums[middle]) < abs(target - closestSum) ) {
						closestSum =  nums[left] + nums[right] + nums[middle];
					}
                    			right--;
					t_lr = target - (nums[left] + nums[right]);
					continue;
                		}

				if( abs(t_lr - nums[middle]) < abs(t_lr - nums[middle+1])) {
					if (abs(t_lr - nums[middle]) < abs(target - closestSum)) {
						closestSum =  nums[left] + nums[right] + nums[middle];
					}
				}
				else{
                    			if (abs(t_lr - nums[middle+1]) < abs(target - closestSum)) {
						closestSum =  nums[left] + nums[right] + nums[middle+1];
					}
				}
			}
			else if( t_lr > nums[middle] ) {
				while( middle < right-1 && t_lr > nums[middle] )
					middle++;
                
                		if ( t_lr > nums[middle] ) {
                    			if ( abs(t_lr - nums[middle]) < abs(target - closestSum) ) {
						closestSum =  nums[left] + nums[right] + nums[middle];
					}
					middle--;
                    			right--;
					t_lr = target - (nums[left] + nums[right]);
					continue;
                		}
				
				if( abs(t_lr - nums[middle]) < abs(t_lr - nums[middle-1])){
                    			if ( abs(t_lr - nums[middle]) < abs(target - closestSum) ){
						closestSum =  nums[left] + nums[right] + nums[middle];
					}
				}
				else{
                			if ( abs(t_lr - nums[middle-1]) < abs(target - closestSum)  ) {
						closestSum =  nums[left] + nums[right] + nums[middle-1];
					}
				}
			}
			else{
				return target;
			}

			right--;
			t_lr = target - (nums[left] + nums[right]);
		}
		
		left++;	
		middle = left + 1;
		right = size - 1;
	}
	return closestSum;
}



















/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 

Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>  

using namespace std;

int maxArea(vector<int>& height);

int main()
{
	vector<int> height {8, 7, 2, 1};

	int result = maxArea(height);
	cout << result << endl;
	
	return 0;
}

// area = (x2 - x1) * min(height1, height2)

int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right)
        {
            maxArea = max(maxArea, (right-left) * min(height[left], height[right]));

            if(height[left] > height[right])
                right--;
            else
                left++;

        }

        return maxArea;	
}















	

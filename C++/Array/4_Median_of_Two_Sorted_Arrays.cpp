/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>  

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
	vector<int> nums1 {1, 2};
	vector<int> nums2 {3, 4};

	double result = findMedianSortedArrays(nums1, nums2);
	cout << result << endl;
	
	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int start1 = 0, start2 = 0;
    int end1, size1;
    end1 = size1 = nums1.size()-1;
    int end2, size2;
    end2 = size2 = nums2.size()-1;
    
    if ( size1+1 == 0 ){
        if ((size2+1) % 2 == 0)
        {
            return double((nums2[(size2+1) / 2 - 1] + nums2[(size2+1) / 2])) / 2;
        }
        else 
        {
            return nums2[(size2+1) / 2];
        }
    }
    else if (size2+1 == 0){
        if ((size1+1) % 2 == 0)
        {
            return double(nums1[(size1+1) / 2 - 1] + nums1[(size1+1) / 2]) / 2;
        }
        else 
        {
            return nums1[(size1+1) / 2];
        }
    }


    while( start1 < end1 || start2 < end2 ) {

        if (start1 > size1)
            start2++;
        else if (start2 > size2) 
            start1++;
        else if(nums1[start1] <= nums2[start2])
            start1++;
        else
            start2++;

        if (end1 < 0)
            end2--;
        else if (end2 < 0)
            end1--;
        else if (nums1[end1] >= nums2[end2])
            end1--;
        else
            end2--;
        
    }
    
    

    
    if ((size2+size1+2) % 2 == 0)
    {
        int start = 0, end = 0;
        if (start1 > size1 && start2 <= size2)
            start = nums2[start2];
        else if (start1 <= size1 && start2 > size2)
            start = nums1[start1];
        else if (start1 <= size1 && start2 <= size2)
            start = min(nums1[start1], nums2[start2]);
        else
            start = min(nums1[start1--], nums2[start2--]);

        if (end1 < 0 && end2 >= 0)
            end = nums2[end2];
        else if (end1 >= 0 && end2 < 0)
            end = nums1[end1];
        else if (end1 >= 0 && end2 >= 0)
            end = max(nums1[end1], nums2[end2]);
        else
            end = max(nums1[end1++], nums2[end2++]);

        return double(start + end ) / 2;
    }
    else 
    {
        int start = 0;
        if (start1 > size1 && start2 <= size2)
            start = nums2[start2];
        else if (start1 <= size1 && start2 > size2)
            start = nums1[start1];
        else if (start1 <= size1 && start2 <= size2)
            start = min(nums1[start1], nums2[start2]);
        else
            start = min(nums1[start1--], nums2[start2--]);

        return start;
    }	

}

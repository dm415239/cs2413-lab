#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement
	if (nums1Size == n + m) {
		if (nums2Size == n) {
			int x = 0;
			int w = 0;
			while (x < nums1Size) {
				int y = w;
				while (y < nums2Size) {
					if (x>=m)
					{
						nums1[x] = nums2[y];
						m++;
						w++;
					}
					else {
						if (nums2[y] <= nums1[x]) {
							int z = x + 1;
							int temp = nums1[x];
							int ttemp = nums1[x + 1];
							nums1[x] = nums2[y];
							w++;
							m++;
							int t = 1;
							while (t == 1) {
								if (z>=m) {
									t = 0;
								}

								else {
									nums1[z] = temp;
									temp = ttemp;
									ttemp = nums1[z + 1];
								}
								z++;
							}
							
							
						}
					}
					y++;
				}
				x++;
				
			}
		}

	}

}

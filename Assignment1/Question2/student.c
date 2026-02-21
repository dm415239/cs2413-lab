#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement
    int majority = 0;
    int x = 0;
   

    while (x < numsSize) {
        int y = x + 1;
        int count = 1;
        
        while (y < numsSize) {
            if (nums[x] == nums[y])
                count++;
            y++;
        }
        if (count > (numsSize / 2))
            majority = nums[x];
        x++;
       
    }
    return(majority);


}

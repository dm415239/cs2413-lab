#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement
    int* output;
    int a = 0;
    int x = digitsSize - 1;
    int y = 0;
    if (digits[x] < 9) {
        output = malloc(digitsSize * sizeof(int));
        *returnSize = digitsSize;

        while (y < digitsSize) {
            output[y] = digits[y];
            y++;

        }
        output[x] = digits[x] + 1;
        a = 1;

    }
    else {
        int temp[digitsSize];
        while (y < digitsSize) {
            temp[y] = digits[y];
            y++;
        }
        while (x >= 0) {
            if (a == 0) {
                if (digits[x] < 9) {
                    a = 1;
                    temp[x] = digits[x] + 1;

                }
                if (digits[x] == 9)
                    temp[x] = 0;
            }
            x--;
        }
        if (a == 1) {
            output = malloc(digitsSize * sizeof(int));
            *returnSize = digitsSize;
            y = 0;
            while (y < digitsSize) {
                output[y] = temp[y];
                y++;
            }
        }
        else {
            output = malloc((digitsSize + 1) * sizeof(int));
            output[0] = 1;
            x = 1;
                while (x <= digitsSize) {
                    output[x] = 0;
                    x++;
            }
            *returnSize = digitsSize + 1;
        }
    }


    return(output);
}


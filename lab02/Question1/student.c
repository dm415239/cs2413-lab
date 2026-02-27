// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    bool output = true;
    int x = strlen(s);
    int y = 0;
    char arr[x];
    int w = 0;
    while (y < x) {
        if (s[y] == '(' || s[y] == '[' || s[y] == '{') {
            arr[w] = s[y];
            w++;
            bool t = true;
            int z = (y+1);
            while (t) {
                if (z < x) {
                    if (s[z] == '(' || s[z] == '[' || s[z] == '{') {
                        t = false;
                    }
                    else {
                        if ((arr[w - 1] == '(' && s[z] == ')') ||
                            (arr[w - 1] == '[' && s[z] == ']') ||
                            (arr[w - 1] == '{' && s[z] == '}'))
                        {
                            t = false;
                            w--;
                        }

                        else {
                            if (s[z] == ')' || s[z] == ']' || s[z] == '}') {
                                t = false;
                                output = false;
                            }
                        }
                    }

                }
                

                if (z >= x) {
                    t = false;
                    output = false;
                }

                z++;
            }
            
        }
        else {
            if (y == 0) {
                output = false;
            }
        }
        y++;
    }
    if (x % 2 != 0) {
        output = false;
    }
   
    return (output);
}

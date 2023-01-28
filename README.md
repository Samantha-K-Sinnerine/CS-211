# CS-211 Object Oriented Programming in C++

8 QUEENS- WITH GOTO

The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. (No two queens can be in the same row, column, or diagonal.) This version of code solves the problem using GOTO labels.

8 QUEENS

Solve the eight queens puzzle without using GOTO labels. (Mechanically place a queen in the slot, and then send it to some sort of "judge." This "judge, which contains the intellegence of the program, will return if the queen is allowed in that spot or not. If the queen is rejected from all spots in that row, use backtracking.)

8 NUMBERS IN A CROSS

Use backtracking to write a program which allocates the integers 1-8 to the squares in the cross-like figure, subject to the restrictions that no two adjacent squares contain consecutive integers. (No two consecutive numbers can be in boxes that are vertical, horizontal, or diagonal from each other.)

STABLE MARRIAGE

The Problem: You have n men and n woman, and their preference rankings of each other, and you need to match them up so that the total matching is “stable.”

The preference rankings: You are given 2 n X n arrays, mp (men’s preference) which gives the men’s ranking of the women, and wp (women’s preference) which gives the women’s ranking of the men. So mp[i][j] gives man i's ranking of woman j and likewise for the women’s ranking of the men in wp.

What is a stable matching? A matching is stable if there are no “instabilities.” An instability is the situation where there is a mutual greater preference for the other person’s partner than for one’s own. For example m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.

Input Data: For this program use the arrays mp and wp given. The data will thus be “given” and not obtained by reading it in. Output: Print out all stable matchings, one per line. (Same output as the one dimensional eight queens program.)


TOWERS OF HANOI - (non-recurisve solution)

Solve the Towers of Hanoi puzzle, for an even and odd number of rings.

INTEGRATION (USING FUNCTION POINTERS)

The problem is to write a function “integrate” with prototype FUNC, which represents functions of one variable that take a double as input and return a double. When it is passed a function f and bounds a and b, the call "integrate(f, a,b)" will return the value of the definite integral of f evaluated between a and b. Test this with line, square, and cube- using a main function.

How does integrate work? Inside a loop we sum up the area of rectangles with a small base (say .0001) and height f(x) for each x between a and b in increments of .0001. When the loop terminates, we return the value of the sum. The purpose if this assignment is to see (and implement) a very simple application of function pointers.

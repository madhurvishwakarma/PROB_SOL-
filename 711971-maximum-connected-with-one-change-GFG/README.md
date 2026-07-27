# [Maximum Connected with One Change](https://www.geeksforgeeks.org/problems/maximum-connected-group/1)
## Hard
You are given a square&nbsp;binary grid. A grid is considered binary if every value in the grid is either&nbsp;1 or 0.&nbsp;You can change&nbsp;at most one&nbsp;cell in the grid from&nbsp;0 to 1.&nbsp;You need to find the largest group of connected&nbsp;&nbsp;1's.&nbsp;Two cells are said to be connected if both are&nbsp;adjacent(top, bottom, left, right)&nbsp;to each other and both have the same value.
Examples :
Input: grid[][] = [[1, 1], [0, 1]]
Output: 4
Explanation: By changing the only 0 to 1, all the 1s become connected, resulting in a connected group of size 4.
 
Input: grid[][] = [[1, 0, 1], [1, 0, 1], [1, 0, 1]]
Output: 7
Explanation: By changing any 0 in the middle column to 1, the two connected groups merge into a single connected group of size 7.
Constraints:1 ≤ grid.size() ≤ 5000 ≤ grid[i][j] ≤ 1
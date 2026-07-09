# [Predecessor and Successor](https://www.geeksforgeeks.org/problems/predecessor-and-successor/1)
## Medium
You are given the root of a BST&nbsp;and an integer key. You need to find the inorder predecessor and successor of the given key. If either predecessor or successor is not found, then set it to NULL.
Note: In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.&nbsp;
Examples :
Input: root = [50, 30, 70, 20, 40, 60, 80], key = 65
Output: [60, 70]
Explanation: In the given BST the inorder predecessor of 65 is 60 and inorder successor of 65 is 70.
Input: root = [8, 1, 9, N, 4, N, 10, 3], key = 8
Output: [4, 9]
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Constraints:&nbsp;1&nbsp;≤&nbsp;no. of nodes&nbsp;≤&nbsp;1050 ≤ node-&gt;data&nbsp;≤&nbsp;1061&nbsp;≤&nbsp;key&nbsp;≤ 106
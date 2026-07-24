# [Bipartite Graph](https://www.geeksforgeeks.org/problems/bipartite-graph/1)
## Medium
Given a Graph with V&nbsp;vertices (Numbered from&nbsp;0&nbsp;to&nbsp;V-1) and&nbsp;E edges.&nbsp;Check whether the graph is bipartite or not.
A&nbsp;bipartite graph&nbsp;can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.

Examples:
Input: V = 3, edges[][] = [[0, 1], [1,2]]

Output: true
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.

Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]Output: false Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 
Constraints:1&nbsp;≤ V&nbsp;≤ 2 * 1051 ≤ edges.size() ≤ 1051 ≤ edges[i][j] ≤ 105
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* mark( Node* root , unordered_map<Node* , Node*>& parent , int target ){
        queue<Node*> q ;
        q.push( root ) ;
        Node* targetNode = NULL ;
        while(!q.empty()){
            Node* node = q.front() ;
            q.pop() ;
            if( node->data == target ){
                targetNode = node ;
            } 
            if(node->left){
                parent[node->left] = node;
                q.push(node->left) ;
            }
            if( node->right){
                parent[node->right] = node ;
                q.push(node->right) ;
            }
        }
        return targetNode ;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node* , Node* > parent ;
        Node* targetNode = mark(root , parent ,target ) ;
        unordered_map<Node* , bool > visited ;
        queue<Node*> q ;
        q.push(targetNode) ;
        int dist = -1 ;
        visited[targetNode] = true ;
        while( !q.empty() ){
            int size = q.size() ;
            for( int i=0 ; i<size ; i++ ){
                Node* node = q.front() ;
                q.pop() ;
                if(node->left && !visited[node->left]){
                    q.push(node->left) ;
                    visited[node->left] = true ;
                }
                if( node->right && !visited[node->right]){
                    q.push( node->right ) ;
                    visited[node->right] = true ;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]) ;
                    visited[parent[node]] = true ;
                }
            }
            dist++ ;
        }
        return dist ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
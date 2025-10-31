class Solution {
  public:
    Node* prev = NULL;
    Node* head = NULL;
    Node* bToDLL(Node* root) {
        if (!root) return NULL;
        
        // Convert left subtree first
        bToDLL(root->left);
        
        // Process current node
        if (prev == NULL)
            head = root;
        else {
            root->left = prev;
            prev->right = root;
        }
        
        // Mark current as previous before moving to right
        prev = root;
        
        // Convert right subtree
        bToDLL(root->right);
        
        return head;
    }
};

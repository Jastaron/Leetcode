void traverse(struct TreeNode* root, int* arr, int* returnSize){
        if( root ){
                traverse(root->left, arr, returnSize);
                arr[(*returnSize)++] = root->val;
                traverse(root->right, arr, returnSize);
        }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
        /* 中序遍历的顺序是：左->中->右 */
        *returnSize = 0;
        int* ans = malloc( sizeof(int) * 100 );
        traverse(root, ans, returnSize);
        return ans;
}
~

void traverse(struct TreeNode* root, int* arr, int* returnSize){
        if( root ){
                traverse(root->left, arr, returnSize);
                traverse(root->right, arr, returnSize);
                arr[(*returnSize)++] = root->val;
        }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
        /* 后序遍历的顺序是：左->右->中 */
        *returnSize = 0;
        int* ans = malloc( sizeof(int) * 100 );
        traverse(root, ans, returnSize);
        return ans;
}
~

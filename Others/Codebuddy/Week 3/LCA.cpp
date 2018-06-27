int ANS;
int dfs(TreeNode *x, int a, int b)
{
    if(x == NULL)
        return 0;
    int ans = (x->val == a)+(x->val == b)+dfs(x->left, a, b)+dfs(x->right, a, b);
    if(ans == 2 && ANS == -1)
        ANS = x->val;
    return ans;
}

int Solution::lca(TreeNode* A, int B, int C) {
    ANS=-1;
    dfs(A, B, C);
    return ANS;
}

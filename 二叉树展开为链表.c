/**
 * struct TreeNode 
 *{
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param root TreeNode类 
 */
typedef struct TreeNode *NodePtr;
//思想:每次找到当前节点的左子树的最右节点,然后将左子树的最右节点的右子树指向当前节点的右节点。然后将左子树挂到当前节点的右节点上。
//接着遍历当前节点的右节点。重复以上步骤。
void expandTree(struct TreeNode* root )
{
    NodePtr curNode = root;
    while(curNode)
    {
            if(curNode->left)
            {
                    NodePtr left = curNode->left;
                    NodePtr temp = left;
                    while(temp->right)
                        temp = temp->right;
                    temp->right = curNode->right;
                    curNode->right = left;
                    curNode->left = NULL;
            }
            curNode = curNode->right;
    }
}
//思想：先遍历右子树然后遍历左子树。最后将当前节点的右子树指向前一个记下的节点。同时将当前节点的左子树置为空。最后将前一个记下的节点设为当前节点。
//即先将右子树疏离成链表，然后再将左子树梳理成链表，最后整体整理成链表。
TreeNode* last = NULL;  // 从后往前 插入
void expandTree(TreeNode* root) 
{
      // write code here
      if(!root) return ;
      expandTree(root->right);
      expandTree(root->left);
      root->right = last;
      root->left = NULL;
      last = root;
 ｝

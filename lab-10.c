#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val);
    if(root->key < val)
        root->right = insert(root->right,val);
    else if(root->key > val)
        root->left = insert(root->left,val);

    return root;
}

int getRightMin(struct node *root)
{
    struct node *temp = root;

    //min value should be present in the left most node.
    while(temp->left != NULL){ temp = temp->left;}

    return temp->key;
}

struct node *removeNode(struct node *root, int val)
{
    if(root == NULL) return NULL;
    if(root->key < val) root->right = removeNode(root->right,val);
    else if(root->key > val) root->left = removeNode(root->left,val);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            int rightMin = getRightMin(root->right);
            root->key = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    return root;
}

/*
 * it will print the tree in ascending order
 */
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

int main()
{
    /*
         100
         / \
        50  200
            /  \
           150  300
     */
    struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,200);
    root = insert(root,150);
    root = insert(root,300);

    printf("Initial tree after insertion:\t");
    inorder(root);
    printf("\n");

    /* remove leaf node 300
         100
         / \
        50  200
            /
           150
     */
    root = removeNode(root,300);
    printf("After deletion of 300, the new tree :\t");
    inorder(root);
    printf("\n");

    /* remove root node 100
         150
         / \
        50  200
     */
    root = removeNode(root,100);
    printf("After deletion of 100, the new tree :\t");
    inorder(root);
    printf("\n");

    return 0;
}

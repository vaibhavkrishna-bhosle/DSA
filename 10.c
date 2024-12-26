//binary search tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data)
{
    struct node *newNode = createNode(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    struct node *temp = root;
    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}


void inorder(struct node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void preorder(struct node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

int main()
{
    printf("Enter the number of elements you want to insert in the tree: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert(data);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}

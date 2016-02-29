#include <stdio.h>
#include <stdlib.h>
typedef int Type;
typedef struct node
{
    Type data;
    struct node *lchild;
    struct node *rchild;
} Node,Btree;

void Init(Btree *tdemo);   /* Initialize */
void InsertLeftNode(Node *n,Type data);
void InsertRightNode(Node *n,Type data);
void PreOrderTraverse(Btree *tdemo);
void InOrderTraverse(Btree *tdemo);
void PostOrderTraverse(Btree *tdemo);
void visit(Node *n);

/************ driver: the main method   ****************/
int main()
{
    Btree *bitree = (Btree *)malloc(sizeof(Btree));
    if(bitree == (Btree *)NULL)
    {
        printf("Error: Failed to allocate memory to the tree.\n");
        exit(1);
    }
    Init(bitree);

    InsertLeftNode(bitree,1);
    InsertRightNode(bitree,2);
    InsertLeftNode(bitree->lchild,3);
    InsertRightNode(bitree->lchild,4);
    InsertLeftNode(bitree->rchild,5);
    InsertRightNode(bitree->rchild,6);
    printf("\nPre order Traverse: ");
    PreOrderTraverse(bitree);
    printf("\nIn order Traverse: ");
    InOrderTraverse(bitree);
    printf("\nPost order Traverse: ");
    PostOrderTraverse(bitree);

    free(bitree);
    printf("\n");
    return 0;
}


/****** Realization of methods about Binary Tree ********/
void Init(Btree *root)
{
    root->data = 0;
    root->lchild = NULL;
    root->rchild = NULL;
}
void InsertLeftNode(Node *n,Type data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == (Node *)NULL)
    {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    n->lchild = newnode;
}
void InsertRightNode(Node *n,Type data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == (Node *)NULL)
    {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    n->rchild = newnode;
}
void PreOrderTraverse(Btree *node)
{
    if(node != NULL)
    {
        visit(node);
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
    }
}
void InOrderTraverse(Node *node)
{
    if(node != NULL)
    {
        InOrderTraverse(node->lchild);
        visit(node);
        InOrderTraverse(node->rchild);
    }
}
void PostOrderTraverse(Node *node)
{
    if(node != NULL)
    {
        PostOrderTraverse(node->lchild);
        PostOrderTraverse(node->rchild);
        visit(node);
    }
}
void visit(Node *n)
{
    Type data;
    data = n->data;
    printf("%d ",data);
}

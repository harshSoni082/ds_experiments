// Program to -
// a. create a BST
// b. perform inorder, preorder and postorder traversal on above

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char key;
  struct node *left;
  struct node *right;
}node;

node *create_node(char key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *insert(node *root, char key)
{
  if(!root)
  {
    root = create_node(key);
  }
  else
  {
    if(key < root->key)
    {
      if(!root->left)
      {
        root->left = create_node(key);
        return NULL;
      }
      insert(root->left, key);
    }
    else
    {
      if(!root->right)
      {
        root->right = create_node(key);
        return NULL;
      }
      insert(root->right, key);
    }
  }
  return root;
}

void inorder_traversal(node *root)
{
  if(root)
  {
    inorder_traversal(root->left);
    printf("%c, ", root->key);
    inorder_traversal(root->right);
  }
}

void preorder_traversal(node *root)
{
  if(root)
  {
    printf("%c, ", root->key);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }

}

void postorder_traversal(node *root)
{
  if(root)
  {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%c, ", root->key);
  }
}

int main()
{
  node *root = NULL;

  int size;
  char key;
  printf("Enter number of elements to insert: ");
  scanf("%d", &size);
  fflush(stdin);
  printf("Enter elements: \n");
  for(int i=0; i<size; i++)
  {
    scanf("%c", &key);
    if(i == 0)
    {
      root = insert(root, key);
    }
    else
    {
      insert(root, key);
    }
    fflush(stdin);
  }
  printf("\nInorder : ");
  inorder_traversal(root);

  printf("\nPreoder : ");
  preorder_traversal(root);

  printf("\nPostorder : ");
  postorder_traversal(root);

  printf("\n");
}

// Program to -
// a. create bst of integers
// b. iteratively perform inorder traversal
// c. calculate height

#include <stdio.h>
#include <stdlib.h>
#define MAX(A, B) A > B ? A : B

typedef struct node
{
  int key;
  struct node *left;
  struct node *right;
}node;


node *create_node(int key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *insert(node *root, int key)
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

void inorder_traversal(node *root, int size)
{
  node *stack[size];
  int top = -1;
  node *curr_node = root;
  while((top != -1)||(curr_node))
  {
    while(curr_node)
    {
      stack[++top] = curr_node;
      curr_node = curr_node->left;
    }
    if(top != -1)
    {
      curr_node = stack[top--];
      printf("%d, ", curr_node->key);
      curr_node = curr_node->right;
    }
  }

}

int height(node *root)
{
  if(!root)
  {
    return -1;
  }
  return MAX(height(root->left), height(root->right)) + 1;
}


int main()
{
  node *root = NULL;

  int size, key;
  printf("Enter number of elements to insert: ");
  scanf("%d", &size);
  fflush(stdin);
  printf("Enter elements: \n");
  for(int i=0; i<size; i++)
  {
    scanf("%d", &key);
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
  printf("Inorder : ");
  inorder_traversal(root, size);
  printf("\nHeight of BST: ");
  printf("%d\n", height(root));
}

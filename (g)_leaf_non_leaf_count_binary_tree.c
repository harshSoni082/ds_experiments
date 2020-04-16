// Program to count number of leaf and non leaf nodes in a binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left;
  struct node *right;
}node;

node *create_node()
{
  int key;
  printf("\nEnter key: ");
  scanf("%d", &key);

  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *create_binary_tree(node *root)
{
  int choice;

  printf("\nEnter:\n1. To add node\n2. To End.\n");
  scanf("%d", &choice);
  if(choice == 1)
  {
    root = create_node();
    printf("\nLeft Child");
    root->left = create_binary_tree(root->left);
    printf("\nRight Child");
    root->right = create_binary_tree(root->right);

    return root;
  }
  else
  {
    return NULL;
  }
}

int count_leaf(node *root)
{
  if((!root->left)&&(!root->right))
  {
    return 1;
  }
  return count_leaf(root->left) + count_leaf(root->right);
}

int count_non_leaf(node *root)
{
  if((!root->left)&&(!root->right))
  {
    return 0;
  }
  return 1 + count_non_leaf(root->left) + count_non_leaf(root->right);
}


int main()
{
  node *root;
  root = create_binary_tree(root);

  printf("Number of leaf nodes: %d\n", count_leaf(root));
  printf("Number of non-leaf nodes: %d\n", count_non_leaf(root));
}

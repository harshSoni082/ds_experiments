// Program to -
//   a. Create a doubly linked list
//   b. Delete a given integer from that list
//   c. Display contents after deletion

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *next;
  struct node *prev;
}node;

node *head = NULL;

// Function to create a node
node *create_node(int key)
{
   node *new_node = (node *)malloc(sizeof(node));
   new_node->key = key;
   new_node->next = NULL;
   new_node->prev = NULL;
   return new_node;
}

// Function to traverse
void traverse()
{
  node *curr_node = head;
  while(curr_node)
  {
    printf("%d<->", curr_node->key);
    curr_node = curr_node->next;
  }
  printf("\n");
}

// functio to delete a node
void delete(int key)
{
  node *curr_node = head;
  node *to_del = NULL;
  while(curr_node)
  {
    if(curr_node->next->key == key)
    {
      to_del = curr_node->next;
      break;
    }
    curr_node = curr_node->next;
  }
  if(to_del)
  {
    curr_node->next = to_del->next;
    to_del->next->prev = curr_node;
    printf("Node with value %d deleted\n", to_del->key);
    free(to_del);
    printf("Updated Linked List: ");
    traverse();
  }
  else
  {
    printf("Node with value %d not found\n", key);
  }
}


int main()
{
  int key;
  node *curr_node = NULL;
  for(int i=0; i<10; i++)
  {
    node *new_node = create_node(i+1);
    if(!head)
    {
      head = new_node;
      curr_node = head;
    }
    else
    {
      curr_node->next = new_node;
      new_node->prev = curr_node;
      curr_node = curr_node->next;
    }
  }
  printf("Doubly Linked List: ");
  traverse();
  printf("Enter key to delete: ");
  scanf("%d", &key);
  delete(key);
}

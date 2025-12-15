// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    float data;
    struct Node* next;
};

struct Node* createNode(float data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

#pragma region InsertionFunctions

void insertAtStart(struct Node* *head,float data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
};

void insertAtEnd(struct Node* *head, float data)
{
    struct Node* newNode = createNode(data);
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct Node * tempNode = *head;
    while(tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    
    tempNode->next = newNode;
};

void insertAtPosition(struct Node* *head , float data , int position)
{
    if(position < 0)
    {
        printf("Invalid Position\n");
        return;
    }
     
     if(position == 0)
     {
         insertAtStart(head , data);
     }
     
     struct Node* newNode = createNode(data);
     
     struct Node * temp = *head;
     
     for(int i = 0 ; i < position - 1  && temp != NULL ; i++)
     {
         temp = temp->next;
     }
     
     if(temp == NULL)
     {
         printf("Array Out Of Bounds\n");
         free(newNode);
         return;
     }
     
     newNode->next = temp->next;
     temp->next = newNode;
     
};

#pragma endregion

#pragma region DeletionFunctions

void deleteAtStart(struct Node** head)
{
  if(*head == NULL)
  {
      printf("Nothing to delete bruv");
      return;
  }
  
  struct Node * temp = *head;
  *head = temp->next;
  free(temp);
};

void deleteAtEnd(struct Node** head)
{
    if(*head == NULL)
    {
        printf("Nothing to delete bruv");
        return;
    }
    
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    
    struct Node * temp = *head;
    
    
    while((temp->next->next) != NULL)
    {
        temp = temp->next;
    }
    
    free(temp->next->next);
    temp->next = NULL;
    
}

void deleteAtPosition(struct Node** head, int position)
{
    if (position < 0)
    {
        printf("Invalid Position\n");
        return;        
    }

    if(*head == NULL)
    {
        printf("Empty List bruv\n");
        return;
    }

    struct Node* temp = *head;

    // Case 1: delete head (position 0)
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node BEFORE the one to delete
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    // If position is out of bounds
    if (temp->next == NULL)
        return;

    // Delete the node
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

#pragma endregion

void printList(struct Node * head)
{
    struct Node * temp = head;
    while(temp != NULL)
    {
        printf("%f -> ",temp->data);
        temp  = temp->next;
    }
}

int main()
{
    struct Node * head = NULL;
    
    insertAtStart(&head , 5);
    
    insertAtEnd(&head , 10);
    
    insertAtPosition(&head , 7.5 , 1);
    
    //deleteAtEnd(&head);
    
    //deleteAtStart(&head);
    
    deleteAtPosition(&head , 1);
    
    printList(head);
    
    return 0;
}
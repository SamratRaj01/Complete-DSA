#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtStart(struct Node** head , int data)
{
    if (*head == NULL){
        *head = createNode(data);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void instertAtEnd(struct Node** head , int data)
{
    if(*head == NULL)
    {
        *head = createNode(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void instertAtPosition(struct Node** head , int data , int position)
{

    if(position < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if(position == 0)
    {
        insertAtStart(head , data);
        return;
    }
    
    struct Node* temp = *head;

    // Move temp to (position - 1)
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

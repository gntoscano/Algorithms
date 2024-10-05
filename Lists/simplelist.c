#include <stdio.h>
#include <stdlib.h>

typedef struct //Node structure
{
    int data;
    Node *next;
}Node;

Node* creationNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL; //The last item of a list have to point NULL
}

//Insert a new node at the beginning of the list
void insertNode(Node **head, int data)
{
    Node newNode = creationNode(data);
    newNode -> next = *head;
    *head = newNode;
}


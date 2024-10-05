#include <stdio.h>
#include <stdlib.h>

typedef struct Node //Node structure
{
    int data;
    struct Node *next;
} Node;

Node* creationNode(int data);
void insertNode(Node **head, int data);
void printlist(Node *head);

int main (void)
{
    int n1, n2, n3;
    Node *head = NULL;
    printf("Digite 3 valores para serem adicionados a lista: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    insertNode(&head, n1);
    insertNode(&head, n2);
    insertNode(&head, n3);

    printlist(head);
}

Node *creationNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL; //The last item of a list have to point NULL
    return newNode;
}

//Insert a new node at the beginning of the list
void insertNode(Node **head, int data) //Head = First node pointer
{
    Node *newNode = creationNode(data);
    newNode -> next = *head;
    *head = newNode;
}

void printlist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}



#include <stdio.h>
#include <stdlib.h>

typedef struct st_node
{
    int item;
    struct st_node *pointed;
}node;

node *search (node *head, int x);
void insertValue (node **head, int x);
void removeValue (node **head, node *r);
node *previous (node *head, node *r);
void printNode (node *head);

int main (void)
{
    node *list1 = NULL, *b = NULL, *a = NULL;

    insertValue( &list1, 1);
    printNode(list1);
    insertValue( &list1, 2);
    printNode(list1);
    insertValue( &list1, 3);
    printNode(list1);
    b = search(list1, 2);

    if (b != NULL)
        printf("b->c: %d\n", b->item);

    a = previous(list1, b);

    if (a != NULL)
        printf("a->c: %d\n", a->item);

    b = search(list1, 1);
    removeValue(&list1, b);
}

node *search (node *head, int x) /*Essa função serve para buscar os valores dentro da lista */
{
    node *p1 = head;
    while (p1 != NULL)
    {
        if (p1->item == x)
        {
            return p1;
        }
        p1 = p1->pointed;
    }
    return NULL;
}

void insertValue (node **head, int x) /* Função para inserir novos valores na lista */
{
    node *p1 = *head;
    node *plant = NULL;

    while (p1 != NULL)
    {
        plant = p1;
        p1 = p1->pointed;
    }

    p1 = malloc(sizeof(node));
    p1->item = x;
    p1->pointed = NULL;

    if (plant != NULL)
    {
        plant->pointed = p1;
    }
    else
    {
        *head = p1;
    }
}

void removeValue (node **head, node *r) /*Função para remover valores da lista*/
{
    node *p1 = *head;
    node *plant = NULL;
    if (r == NULL)
        return;

    while (p1 != NULL && p1 != r)
    {
        plant = p1;
        p1 = p1->pointed;
    }

    if (p1 == NULL) //Nao achou ou  Lista vazia
        return;

    if (plant != NULL)
        plant->pointed = p1->pointed; //Tem anterior
    else
        *head = p1->pointed;
    free(p1);
    return;
}

node *previous (node *head, node *r)
{
    node *p1 = head;
    node  *plant = NULL;

    if (r == NULL)
        return NULL;
    while(p1 != NULL && p1 != r)
    {
        plant = p1;
        p1 = p1 -> pointed;
    }

    return plant;
}

void printNode (node *head)
{
    node *p1 = head;
    while (p1 != NULL)
    {
        printf("%d->", p1->item);
        p1 = p1->pointed;
    }
    printf("NULL\n");
}
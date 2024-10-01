#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100 //Tamanho máximo

typedef struct //Estrutura da pilha
{
    int items[MAX];
    int top; //Topo da pilha
}Pilha;

int escolha(Pilha *p, int x);
void inicializarPilha(Pilha *p);
bool pilhaVazia (Pilha *p);
bool pilhaCheia (Pilha *p);
bool empilhar(Pilha *p, int valor);
bool desempilhar (Pilha *p);
int top(Pilha *p);

int main(void) {
    Pilha p;
    inicializarPilha(&p);

    char entrada[10]; // Buffer para ler a entrada do usuário
    int num;

    do {
        // Loop para garantir uma entrada válida
        do {
            printf("\nDigite '1' para adicionar um novo valor à pilha.\n");
            printf("Digite '2' para remover um valor da pilha.\n");
            printf("Digite '3' para encerrar o programa.\n");
            printf("Digite sua escolha: ");
            scanf("%s", entrada);

            num = atoi(entrada); // Converte a string para um número inteiro

            if (num != 1 && num != 2 && num != 3) {
                printf("Opção inválida! Por favor, escolha 1, 2 ou 3.\n");
            }

        } while (num != 1 && num != 2 && num != 3); // Verifica se a entrada é válida

        escolha(&p, num);

    } while (num == 1 || num == 2); // Continua enquanto a escolha for 1 ou 2

    return 0;
}

int escolha(Pilha *p, int x)
{
    int valor;
    if (x == 1)
        {
        printf("Digite um valor para ser adicionado a pilha: \n");
        scanf("%d", &valor);
        empilhar(p, valor);
        printf("Topo atual da pilha: %d\n", top(p));
    }
    else if (x == 2)
    {
        printf("O valor %d foi removido da pilha: \n", top(p));
        desempilhar(p);
        printf("Novo valor do topo da pilha: %d\n", top(p));
    }
    else if (x == 3)
    {
        return -1;
    }
    else
    {
        int novoValor = 0;
        printf("Digite um novo valor: ");
        scanf("%d\n", &novoValor);
        escolha(p, novoValor);
        return -1;
    }
    return 0;
}

void inicializarPilha(Pilha *p)
{
    p -> top = -1;
}

/* Verifica se a pilha está vazia */
bool pilhaVazia (Pilha *p)
{
    return p -> top == -1;
}

/* Verifica se a pilha está cheia */
bool pilhaCheia (Pilha *p)
{
    return p -> top == MAX - 1;
}

bool empilhar(Pilha *p, int valor)
{
    if (pilhaCheia(p)) {
        printf("A pilha excedeu o tamanho máximo! Não é possível empilhar %d\n", valor);
        return false;
    }
    p -> items[++p -> top] = valor;
    return true;
}

bool desempilhar (Pilha *p)
{
    if (pilhaVazia(p))
    {
        printf("A pilha está vazia!\n");
        return -1;
    }
    return p -> items[p -> top--];
}

int top(Pilha *p)
{
    if (pilhaVazia(p))
    {
        printf("Erro! A pilha está vazia!\n");
        return -1;
    }
    return p -> items[p -> top];
}

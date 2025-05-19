#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Corredor {
    char nome[30];
    float tempo;
} Corredor;

typedef struct Node {
    Corredor corredor;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(Corredor corredor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->corredor = corredor;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Corredor corredor, float tempoCorte) {
    if (root == NULL)
        return createNode(corredor);

    if (corredor.tempo < tempoCorte)
        root->right = insertNode(root->right, corredor, tempoCorte);  // Classificado
    else
        root->left = insertNode(root->left, corredor, tempoCorte);   // Desclassificado

    return root;
}

void mostrarClassificados(Node* root) {
    if (root == NULL) return;


    mostrarClassificados(root->right);
    printf("Nome: %s | Tempo: %.2f\n", root->corredor.nome, root->corredor.tempo);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int qtd;
    float tempoCorte;

    printf("Digite o tempo de corte: ");
    scanf("%f", &tempoCorte);

    printf("Quantos corredores deseja inserir? ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        Corredor corredor;
        printf("\nDigite o nome do corredor %d: ", i + 1);
        scanf(" %[^\n]", corredor.nome);

        printf("Digite o tempo do corredor %d: ", i + 1);
        scanf("%f", &corredor.tempo);

        root = insertNode(root, corredor, tempoCorte);
    }

    printf("\n--- Corredores Classificados (tempo melhor que %.2f) ---\n", tempoCorte);
    mostrarClassificados(root);

    freeTree(root);
    return 0;
}


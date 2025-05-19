#include <stdio.h>

//(Tree.h)
struct Node {
int data;
struct Node *left;
struct Node *right;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)
malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
struct Node* insertNode(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
static int side = 0;
if (side == 0) {
root->left = insertNode(root->left, value);
} else {
root->right = insertNode(root->right, value);
}
side = 1 - side;
return root;
}

void inorderTraversal(struct Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}
void printTreeUtil(struct Node* root, int space) {
if (root == NULL) {
return;
}
space += 10;
printTreeUtil(root->right, space);
printf("\n");
for (int i = 10; i < space; i++) {
printf(" ");
}
printf("%d\n", root->data);
printTreeUtil(root->left, space);
}
void printTree(struct Node* root) {
printf("Estrutura da Arvore Binaria:\n");
printTreeUtil(root, 0);
}

void freeTree(struct Node* root) {
if (root == NULL) {
return;
}
freeTree(root->left);
freeTree(root->right);
free(root);
}


int buscarCaminho(struct Node* root, int value) {
    if (root == NULL) {
        printf("Arvore vazia.\n");
        return 0;
    }

    struct Node* current = root;
    printf("Raiz");
    while (current != NULL) {
        if (value == current->data) {
            printf(" -> %d (Encontrado!)\n", current->data);
            return 1;
        }
        else if (current->left && value == current->left->data) {
            printf(" -> E -> %d (Encontrado!)\n", value);
            return 1;
        }
        else if (current->right && value == current->right->data) {
            printf(" -> D -> %d (Encontrado!)\n", value);
            return 1;
        }
        else if (current->left) {
            printf(" -> E");
            current = current->left;
        }
        else if (current->right) {
            printf(" -> D");
            current = current->right;
        }
        else {
            break;
        }
    }

    printf("\nNumero nao encontrado na arvore.\n");
    return 0;
}




    int main(){
    
    struct Node* root = NULL;
    int opcoes;
    int value;

    while(1){
    printf("----------Menu de opcoes:----------\n");
    printf("1- Inserir numeros na arvore\n");
    printf("2- Buscar numero na arvore\n");
    printf("0- Sair da operacao\n");

    printf("Escolha: ");
    scanf("%d", &opcoes);

    switch (opcoes)
    {
    case 1:
        printf("Digite 5 numeros para colocar na arvore:\n");
        for(int i = 0; i < 5;i++){
        scanf("%d", &value);
        root = insertNode(root, value);
        
    }
        printf("Numeros inseridos com sucesso!\n");
    
        break;
    
    case 2:
        printf("Digite o numero que deseja buscar na arvore: \n");
        scanf("%d", &value);

        if (!buscarCaminho(root, value)) {
        printf("Percorrendo a arvore completa (in-order): ");
        inorderTraversal(root);
        printf("\n");
        }   
        break;

    case 0:
        printf("Saindo do programa...\n");
        freeTree(root);
        return 0;
    }

    }
        return 0;
    
    }


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

// Функція обчислення висоти дерева
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int isBalanced(struct Node* root) {
    if (root == NULL) {
        return 1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return 0;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

void generateRandomData(Node** root, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int value = rand() % 100;
        *root = insert(*root, value);
    }
}

// Функція для вставки відсортованих даних (імітація поганого випадку)
void generateSortedData(Node** root, int n) {
    for (int i = 0; i < n; i++) {
        *root = insert(*root, i);
    }
}

int main() {
    Node* rootRandom = NULL;
    Node* rootSorted = NULL;
    int n = 10; // Кількість елементів

    // Випадковий порядок
    generateRandomData(&rootRandom, n);
    printf("Random Tree: Height = %d, Balanced = %s\n", height(rootRandom), isBalanced(rootRandom) ? "Yes" : "No");

    // Відсортований порядок
    generateSortedData(&rootSorted, n);
    printf("Sorted Tree: Height = %d, Balanced = %s\n", height(rootSorted), isBalanced(rootSorted) ? "Yes" : "No");

    return 0;
}

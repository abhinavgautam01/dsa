// WAP to create a Binary Search Tree and include following operations in tree: (a) Insertion (Recursive and Iterative Implementation) (b) Deletion by copying (c) Deletion by Merging (d) Search a no. in BST (e) Display its preorder, postorder and inorder traversals Recursively (f) Display its preorder, postorder and inorder traversals Iteratively (g) Display its level-by-level traversals (h) Count the non-leaf nodes and leaf nodes (i) Display height of tree (j) Create a mirror image of tree (k) Check whether two BSTs are equal or not?
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertRecursive(struct Node* root, int data);
struct Node* insertIterative(struct Node* root, int data);
struct Node* deleteByCopy(struct Node* root, int data);
struct Node* deleteByMerge(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
void preorderRecursive(struct Node* root);
void inorderRecursive(struct Node* root);
void postorderRecursive(struct Node* root);
void preorderIterative(struct Node* root);
void inorderIterative(struct Node* root);
void postorderIterative(struct Node* root);
void levelOrderTraversal(struct Node* root);
int countNonLeafNodes(struct Node* root);
int countLeafNodes(struct Node* root);
int heightOfTree(struct Node* root);
struct Node* mirrorTree(struct Node* root);
int areTreesEqual(struct Node* root1, struct Node* root2);

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert (Recursive)\n");
        printf("2. Insert (Iterative)\n");
        printf("3. Delete (By Copying)\n");
        printf("4. Delete (By Merging)\n");
        printf("5. Search\n");
        printf("6. Display (Preorder Recursive)\n");
        printf("7. Display (Inorder Recursive)\n");
        printf("8. Display (Postorder Recursive)\n");
        printf("9. Display (Preorder Iterative)\n");
        printf("10. Display (Inorder Iterative)\n");
        printf("11. Display (Postorder Iterative)\n");
        printf("12. Level Order Traversal\n");
        printf("13. Count Non-Leaf Nodes\n");
        printf("14. Count Leaf Nodes\n");
        printf("15. Height of Tree\n");
        printf("16. Create Mirror Image of Tree\n");
        printf("17. Check if Two Trees are Equal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertRecursive(root, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertIterative(root, value);
                break;
            case 3:
                printf("Enter value to delete (by copying): ");
                scanf("%d", &value);
                root = deleteByCopy(root, value);
                break;
            case 4:
                printf("Enter value to delete (by merging): ");
                scanf("%d", &value);
                root = deleteByMerge(root, value);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode) {
                    printf("Node %d found.\n", value);
                } else {
                    printf("Node %d not found.\n", value);
                }
                break;
            case 6:
                printf("Preorder (Recursive): ");
                preorderRecursive(root);
                printf("\n");
                break;
            case 7:
                printf("Inorder (Recursive): ");
                inorderRecursive(root);
                printf("\n");
                break;
            case 8:
                printf("Postorder (Recursive): ");
                postorderRecursive(root);
                printf("\n");
                break;
            case 9:
                printf("Preorder (Iterative): ");
                preorderIterative(root);
                printf("\n");
                break;
            case 10:
                printf("Inorder (Iterative): ");
                inorderIterative(root);
                printf("\n");
                break;
            case 11:
                printf("Postorder (Iterative): ");
                postorderIterative(root);
                printf("\n");
                break;
            case 12:
                printf("Level Order Traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 13:
                printf("Non-Leaf Nodes Count: %d\n", countNonLeafNodes(root));
                break;
            case 14:
                printf("Leaf Nodes Count: %d\n", countLeafNodes(root));
                break;
            case 15:
                printf("Height of Tree: %d\n", heightOfTree(root));
                break;
            case 16:
                root = mirrorTree(root);
                printf("Mirror image created.\n");
                break;
            case 17: {
                struct Node* tree2 = NULL;
                printf("Enter values for the second tree (enter -1 to stop): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    tree2 = insertRecursive(tree2, value);
                }
                if (areTreesEqual(root, tree2)) {
                    printf("Both trees are equal.\n");
                } else {
                    printf("Trees are not equal.\n");
                }
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive insertion
struct Node* insertRecursive(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertRecursive(root->left, data);
    } else if (data > root->data) {
        root->right = insertRecursive(root->right, data);
    }
    return root;
}

// Iterative insertion
struct Node* insertIterative(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }
    
    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            return root; // Duplicate value; do not insert
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return root;
}

// Delete by copying
struct Node* deleteByCopy(struct Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteByCopy(root->left, data);
    } else if (data > root->data) {
        root->right = deleteByCopy(root->right, data);
    } else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Node with two children: find inorder successor
            struct Node* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->data = successor->data; // Copy the value
            root->right = deleteByCopy(root->right, successor->data);
        }
    }
    return root;
}

// Delete by merging
struct Node* deleteByMerge(struct Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteByMerge(root->left, data);
    } else if (data > root->data) {
        root->right = deleteByMerge(root->right, data);
    } else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Merge left and right subtrees
            struct Node* temp = root->left;
            struct Node* rightSubtree = root->right;
            free(root);
            if (temp == NULL) {
                return rightSubtree;
            }
            struct Node* maxNode = temp;
            while (maxNode->right != NULL) {
                maxNode = maxNode->right;
            }
            maxNode->right = rightSubtree;
            return temp;
        }
    }
    return root;
}

// Search for a number in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Preorder traversal (Recursive)
void preorderRecursive(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// Inorder traversal (Recursive)
void inorderRecursive(struct Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

// Postorder traversal (Recursive)
void postorderRecursive(struct Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

// Preorder traversal (Iterative)
void preorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100]; // Simple stack implementation using array
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

// Inorder traversal (Iterative)
void inorderIterative(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Postorder traversal (Iterative)
void postorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Level order traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = -1;
    queue[++rear] = root;

    while (front <= rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
}

// Count non-leaf nodes
int countNonLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Height of the tree
int heightOfTree(struct Node* root) {
    if (root == NULL) return -1; // Height of an empty tree is -1
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Create a mirror image of the tree
struct Node* mirrorTree(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* left = mirrorTree(root->left);
    struct Node* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// Check if two trees are equal
int areTreesEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->data == root2->data) && 
           areTreesEqual(root1->left, root2->left) && 
           areTreesEqual(root1->right, root2->right);
}

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global variables
struct Node* head = NULL;
struct Node* newNode = NULL;
struct Node* last = NULL;
struct Node* temp = NULL;
struct Node* prev = NULL;
int data, position;

// Function to create a new node
void createNewNode() {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
}

// Function to insert a node at the front
void insertFront() {
    createNewNode();
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertEnd() {
    createNewNode();
    if (head == NULL) {
        head = newNode;
        return;
    }
    last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a node at a specific position
void insertMid() {
    createNewNode();
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        for (int i = 0; current != NULL && i < position - 1; i++) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            printf("Position out of range\n");
        }
    }
}

// Function to delete a node from the front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

// Function to delete a node from a specific position
void deleteMid() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    if (position == 0) {
        head = temp->next;
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Position out of range\n");
        }
    }
}

// Function to print the list
void printList() {
    struct Node *node = head;
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at front\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from front\n5. Delete from end\n6. Delete from position\n");
        printf("7. Print list\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter data: ");
            scanf("%d", &data);
            if (choice == 3 || choice == 6) {
                printf("Enter position: ");
                scanf("%d", &position);
            }
        }

        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertMid();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteMid();
                break;
            case 7:
                printList();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

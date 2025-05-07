#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;  // Point to itself (for circularity)
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = *head;  
        *head = newNode;         
    }
    
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = *head;
    }
    
    printf("%d inserted at the end.\n", data);
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Position must be greater than or equal to 1.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    
    if (position == 1) {
        insertAtBeginning(head, data);  
        return;
    }

    struct Node* temp = *head;
    int count = 1;
    
    while (temp->next != *head && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    if (count != position - 1) {
        printf("Position is greater than the number of nodes in the list.\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    printf("%d inserted at position %d.\n", data, position);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 25, 3); 
    
    displayList(head);
    
    return 0;
}

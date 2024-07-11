#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int data;
    struct node *link;
};

int top = -1;
int stack_arr[MAX];

// Function declarations
void simple_myarray();
void search_myarray();
void insert_myarray();
void delete_myarray();
void insert_end_mylinkedlist();
void insert_first_mylinkedlist();
void insert_givenpos_mylinkedlist();
void delete_last_mylinkedlist();
void delete_first_mylinkedlist();
void delete_givenpos_mylinkedlist();
void push(int data);
void print();
void pop();

int main() {
    int choice, arr[20];
    printf("\nVarious types of data structure:");
    printf("\n1. Array:");
    printf("\n2. Linked List:");
    printf("\n3. Stack:");
    printf("\n4. Queue:");
    printf("\n5. Tree:");
    printf("\n6. Graph:");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nArray:");
            printf("\n1. Simple array:");
            printf("\n2. Search an element in an array:");
            printf("\n3. Insert an element in an array:");
            printf("\n4. Delete an element in an array:");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    simple_myarray();
                    break;
                case 2:
                    search_myarray();
                    break;
                case 3:
                    insert_myarray();
                    break;
                case 4:
                    delete_myarray();
                    break;
                default:
                    printf("Invalid choice.");
                    break;
            }
            break;
        case 2:
            printf("\nLinked List:");
            printf("\n5. Insertion at end in Linked list:");
            printf("\n6. Insertion at first in Linked list:");
            printf("\n7. Insertion at given position in Linked list:");
            printf("\n8. Delete the last node of the linked list:");
            printf("\n9. Delete the first node of the linked list:");
            printf("\n10. Delete the given node of the linked list:");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 5:
                    insert_end_mylinkedlist();
                    break;
                case 6:
                    insert_first_mylinkedlist();
                    break;
                case 7:
                    insert_givenpos_mylinkedlist();
                    break;
                case 8:
                    delete_last_mylinkedlist();
                    break;
                case 9:
                    delete_first_mylinkedlist();
                    break;
                case 10:
                    delete_givenpos_mylinkedlist();
                    break;
                default:
                    printf("Invalid choice.");
                    break;
            }
            break;
        case 3:
            printf("\nStack:");
            printf("\n11. Insertion in stack:");
            printf("\n12. Deletion in stack:");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 11:
                    push(1);
                    print();
                    break;
                case 12:
                    push(1);
                    push(2);
                    push(3);
                    pop();
                    print();
                    break;
                default:
                    printf("Invalid choice.");
                    break;
            }
            break;
        case 4:
            printf("\nQueue:");
            // Add your queue implementation here
            break;
        case 5:
            printf("\nTree:");
            // Add your tree implementation here
            break;
        case 6:
            printf("\nGraph:");
            // Add your graph implementation here
            break;
        default:
            printf("Invalid choice.");
            break;
    }
    return 0;
}

void simple_myarray() {
    int i, n, arr[20];
    printf("\nEnter the size of an array:");
    scanf("%d", &n);
    printf("\nEnter the elements of an array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nArray=  ");
    for(i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
}

void search_myarray() {
    int i, n, flag = 0, val, arr[20];
    printf("\nEnter the size of an array:");
    scanf("%d", &n);
    printf("\nEnter the elements of an array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nArray=  ");
    for(i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\nEnter the value you want to search:");
    scanf("%d", &val);
    for(i = 0; i < n; i++) {
        if(arr[i] == val) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        printf("\nFound the element at position = %d", i + 1);
    } else {
        printf("\nElement not found.");
    }
}

void insert_myarray() {
    int i, val, pos, n, arr[20];
    printf("\nEnter the size of an array:");
    scanf("%d", &n);
    printf("\nEnter the elements of an array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nArray=  ");
    for(i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\nEnter the value you want to insert:");
    scanf("%d", &val);
    printf("\nEnter the position you want to insert:");
    scanf("%d", &pos);
    n++;
    for (i = n - 1; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    printf("\nArray after insertion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_myarray() {
    int i, n, pos, arr[20];
    printf("\nEnter the size of an array:");
    scanf("%d", &n);
    printf("\nEnter the elements of an array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nArray=  ");
    for(i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\nEnter the position you want to delete:");
    scanf("%d", &pos);
    if (pos >= n + 1) {
        printf("Deletion not possible.\n");
    } else {
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Resultant array:\n");
        for (i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
    }
}

struct node* at_end(struct node *head, int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    struct node *temp = head;
    while(temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = ptr;
    return head;
}

void insert_end_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After insertion:\n");
    head = at_end(head, 20);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

struct node* addbeg(struct node *head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    head = temp;
    return head;
}

void insert_first_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After insertion:\n");
    head = addbeg(head, 20);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

struct node* insertpos(struct node *head, int pos, int data) {
    struct node *ptr = head;
    struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;
    pos--;
    while(pos != 1) {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
    return head;
}

void insert_givenpos_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After insertion:\n");
    head = insertpos(head, 2, 20);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

struct node* delete_last(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    } else if (head->link == NULL) {
        free(head);
        head = NULL;
        return head;
    } else {
        struct node *temp = head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
        return head;
    }
}

void delete_last_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After deletion:\n");
    head = delete_last(head);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

struct node* del_first(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
    } else {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}

void delete_first_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After deletion:\n");
    head = del_first(head);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

struct node* delpos(struct node *head, int pos) {
    struct node *current = head;
    struct node *previous = head;
    if (head == NULL) {
        printf("List is already empty.\n");
    } else if (pos == 1) {
        head = current->link;
        free(current);
        current = NULL;
    } else {
        while (pos != 1) {
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
    return head;
}

void delete_givenpos_mylinkedlist() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    current = head;
    printf("Original linked list:\n");
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    printf("After deletion:\n");
    head = delpos(head, 2);
    current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
}

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top = top + 1;
        stack_arr[top] = data;
    }
}

void print() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack_arr[i]);
        }
        printf("\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped element is %d\n", stack_arr[top]);
        top = top - 1;
    }
}

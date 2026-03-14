#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
        return;
    }
    
    appendNode(&((*head)->next), data);
}

void prependNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAfter(Node **head, int data, int key)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == key)
    {
        Node *newNode = createNode(data);
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        return;
    }
    insertNodeAfter(&((*head)->next), data, key);
}

void deleteNode(Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }
    if ((*head)->data == key)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    deleteNode(&((*head)->next), key);
}

void clearList(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    clearList(&((*head)->next));
    free(*head);
    *head = NULL;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    printList(head->next);
}

int main()
{
    Node *myList = NULL;

    appendNode(&myList, 10);
    appendNode(&myList, 20);
    prependNode(&myList, 5);
    insertNodeAfter(&myList, 15, 10);
    
    printf("List after additions: ");
    printList(myList);

    deleteNode(&myList, 10);
    printf("List after deleting 10: ");
    printList(myList);

    clearList(&myList);
    return 0;
}
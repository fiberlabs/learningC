#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    struct Node *next;
};

static struct Node *first_node = NULL;

struct Node *add_node(int id)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("error: malloc new_node");
        return NULL;
    }

    new_node->id = id;
    new_node->next = NULL;

    if (first_node == NULL) {
        first_node = new_node;
        return new_node;
    }

    struct Node *current_node = NULL;
    current_node = first_node;
    while (current_node->next != NULL) //as long as ->next != NULL
    {
        current_node = current_node->next; //keep moving the finger onwards
    }
    current_node->next = new_node; //once you reach NULL, append the new node
    //creating the chain
    

    return new_node;
}

void print_list() {
    if (first_node == NULL) {
        printf("there are no nodes to print\n");
        return;
    }

    struct Node *current_node = NULL; 
    current_node = first_node;
    while (current_node != NULL) {
        printf("ID: %d\nMemory Address: %p\n\n", current_node->id, (void *)current_node);
        current_node = current_node->next;
    }

}

int main()
{
    add_node(10);
    add_node(20);
    add_node(30);

    print_list();

    return 0;
}
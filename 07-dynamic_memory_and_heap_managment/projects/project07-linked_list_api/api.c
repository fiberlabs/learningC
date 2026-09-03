#include <stdio.h>
#include <stdlib.h>

struct Node {
    int node_id;
    struct Node *prev;
    struct Node *next;
};

static struct Node *first_node = NULL;
static struct Node *last_node = NULL;

struct Node *spawn_node(int id_parameter) {
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("error: malloc for new_node returned NULL\n");
        return NULL;
    }

    new_node->node_id = id_parameter;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (first_node == NULL) {
        first_node = new_node;
        return new_node;
    }

    struct Node *current_node = NULL;
    current_node = first_node;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;

    //by the time this line is reached, new_node is the last Node
    last_node = new_node;

    return new_node;
}

void print_forward() {
    if (first_node == NULL) {
        printf("nothing to print\n");
        return;
    }

    struct Node *current_node = NULL;
    current_node = first_node;
    while(current_node != NULL) {
        printf("ID: %d\n", current_node->node_id);
        current_node = current_node->next;
    }
}

void print_reverse() {
    if (first_node == NULL) {
        printf("nothing to print\n");
        return;
    }

    struct Node *current_node = NULL;
    current_node = last_node;
    while(current_node != NULL) {
        printf("ID: %d\n", current_node->node_id);
        current_node = current_node->prev;
    }
}

void destroy_nodes() {
    if (first_node == NULL) {
        printf("nothing to destroy :(\n");
        return;
    }

    struct Node *current_node = NULL;
    current_node = first_node;
    while (current_node != NULL)
    {
        struct Node *temporary = NULL;
        temporary = current_node->next;
        free(current_node);
        current_node = temporary;
    }

    first_node = NULL;
    last_node = NULL;
}

int main() {
    print_forward();
    print_reverse();
    spawn_node(95);
    spawn_node(96);
    spawn_node(97);
    spawn_node(98);
    spawn_node(99);
    print_forward();
    print_reverse();
    destroy_nodes();

    return 0;
}
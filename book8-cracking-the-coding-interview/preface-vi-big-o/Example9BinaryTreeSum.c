#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct _Node
{
    struct _Node *left;
    struct _Node *right;
    int value;
} Node;

Node *node_new(int value)
{
    Node *node = malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    node->value = value;
    return node;
}

void node_free(Node *node)
{
    free(node);
}

/*
 * Returns the sum of all the nodes in a binary tree.
 * Time: O(n)
 * Memory: O(log(n)) 
 */
int node_sum(Node *node)
{
    if (node == NULL)
        return 0;
    return node_sum(node->left) + node->value + node_sum(node->right);
}

int main(int argc, char *argv[])
{
    Node **nodes = malloc(sizeof(Node *) * 5);
    for (int i = 0; i < 5; i++)
        nodes[i] = node_new(i + 1);
    nodes[1]->left = nodes[0];
    nodes[2]->left = nodes[1];
    nodes[2]->right = nodes[3];
    nodes[3]->right = nodes[4];
    printf("NodeSum(1..5) = %d\n", node_sum(nodes[2]));
    Node **p = nodes + 5;
    while (p >= nodes)
    {
        node_free(*p--);
    }
    free(nodes);
    return EXIT_SUCCESS;
}
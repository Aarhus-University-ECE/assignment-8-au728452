extern "C"
{
// Add the header files required to run your main
#include "insertion_sort.h"
#include "list_queue.h"
#include <time.h>
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    printf("The test for insertion sort starts here:\n");
    linked_list *ll = createLinkedList();

    assert(ll->head == NULL);

    ll->head = createNode(7);
    node_t *temp = ll->head;

    temp->next = createNode(19);
    temp = temp->next;
    temp->next = createNode(-5);
    temp = temp->next;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(21);
    temp = temp->next;
    temp->next = createNode(21);
    temp = temp->next;
    temp->next = createNode(11);
    temp = temp->next;
    temp->next = createNode(21);
    temp = temp->next;
    temp->next = createNode(21);
    temp = temp->next;
    /*This linked list contains negative numbers, as well as duplicate numbers, to ensure that the
    sorting algorithm works in all cases*/

    /*
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
    {
        int x = rand() % 50 + 1;
        temp->next = createNode(x);
    }
    */
    /*
        linked_list ll;
        ll.head == NULL;

        int ns[] = {
            7, 3, 10, 12, 2, 17, 8};

        int n = sizeof(ns) / sizeof(ns[0]);

        // n = 7;

        for (int i = 0; i < n; i++)
        {
            node_t *node = (node_t *)malloc(sizeof(node_t));
            int idx = n - 1 - i;
            node->data = ns[idx];
            node->next = ll.head;
            ll.head = node;
            // insertFront(node, &ll);
        }
    */
    printLL(ll);

    sort(ll);

    printLL(ll);

    // Testing out queue

    printf("The test for queue starts here:\n");

    queue q1;
    init_queue(&q1);
    enqueue(&q1, 5);
    assert(empty(&q1) == 0);
    dequeue(&q1);
    assert(empty(&q1) == 1);

    // Test enqueue then dequeue
    enqueue(&q1, -5);
    enqueue(&q1, 10);
    enqueue(&q1, 0);
    enqueue(&q1, 5);

    assert(-5 == dequeue(&q1));
    assert(10 == dequeue(&q1));
    assert(0 == dequeue(&q1));
    assert(5 == dequeue(&q1));

    /*The queue will contain positive and negative numbers as well as 0
    as to ensure that the queue can contain any number, and will still return them in the correct order*/

    return 0;
}
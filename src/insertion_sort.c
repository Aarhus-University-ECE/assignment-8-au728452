#include "insertion_sort.h"
#include "linked_list.h"

void sort(linked_list *llPtr)
{
    // Add your sort function here

    /*Pre condition*/
    if (llPtr->head == NULL) // Asserts whether or not the list to be sorted is empty.
    {
        printf("No data to sort:\n");
        abort();
    }

    /*Post condition*/
    node_t *current = llPtr->head; // Makes a node that marks the current list item being sorted, that starts at the first element in the list

    while (current->next != NULL) // Makes it so that all list items are checked at some point
    {
        current = current->next;                    // Updates the item to be sorted through each run through of the while loop, and ensures that the loop terminates at some point
        node_t *temp = llPtr->head;                 // Makes a temporary node, that is to be used as a way to loop through the sorted elements, without changing the overall list
        node_t *prev_temp = malloc(sizeof(node_t)); // Used to keep track of the element that was just sorted
        node_t *sorted = llPtr->head;               // Used to keep track of how much of the list has been sorted already

        while (sorted->next != NULL && sorted->data <= sorted->next->data) // Ensures that "sorted" is always at the largest element at the front of the sorted list
        {
            sorted = sorted->next;
        }

        while (temp != current) // While loop that goes through already sorted elements
        {
            if (current->data < temp->data && temp == llPtr->head) // If statement that checks if the item currently being sorted is smaller than the very first element of the list
            {
                sorted->next = current->next; // Updates the position of "sorted", making it so that its next is pointing to the next element to be sorted
                llPtr->head = current;        // Places the element that is being sorted at the very beginning of the list, since it is the smalles value, as established by the if statement
                current->next = temp;         // Updates currents next value to point to the former first value
                break;                        // goes out of the while loop
            }
            else if (current->data < temp->data) // If the element to be sorted is smaller than the temp data, at a certain point in the sorted list.
            {
                sorted->next = current->next; // Updates sorted to point to next element to be sorted
                prev_temp->next = current;    // The node before the temporary node just used to identify the place to insert the item being sorted will of course point to that element
                current->next = temp;         // Current will then point to the temp value larger than itself in the list, thus it is sorted
                break;                        // Goes out of the while loop
            }
            prev_temp = temp;  // Updates prev_temp thus that it now stores the temp value that was just checked as being larger than current
            temp = temp->next; // Updates the temp value, so that it is the next value that we will check if it is larger than the current item being sorted
        }
    }

    /*
    node_t *temp;
    node_t *current = llPtr->head->next;
    node_t *previous = llPtr->head;

    while (previous->next != NULL)
    {

        if (current->data < previous->data)
        {
            temp = current;
            temp->next = current->next;
            previous->next = current->next;
        }

        node_t *inserter = llPtr->head;
        while (inserter->next->data < temp->data)
        {
            inserter = inserter->next;
        }

        if (llPtr->head == inserter)
        {
            temp->next = llPtr->head;
            llPtr->head = temp;
        }
        else
        {
            temp->next = inserter->next;
            inserter->next = temp;
        }
        previous = current;
        current = current->next;

        */

    /*
    temp = llPtr->head;
            while (current->data > temp->data)
            {
                temp = temp->next;
            }
            previous->next = current->next;
            current->next = temp->next;
            temp->next = current;
*/
    /*
    while (current != NULL){
    while (current->data > previous->data)
    {
        previous = previous->next;
        current = current->next;
    }


    while (current->data < previous->data)
    {
        previous->next = current->next;
        current->next = dummy->next;
        dummy->next = current;
        current = previous->next;
    }
    }
    */
}

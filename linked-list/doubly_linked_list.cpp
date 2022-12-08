#include <string>
#include <bits/stdc++.h>

using namespace std;

/* Representation of a node using class.
 */
class Node
{
public:
    string data;
    Node *previous;
    Node *next;
};

/* Search for a node containing data.
 */
Node *search(Node *n, string data)
{
    while (n != NULL)
    {
        if (n->data == data)
        {
            return n;
        }

        n = n->next;
    }

    return NULL;
};

int main()
{
    Node *head = new Node();
    Node *middle = new Node();
    Node *tail = new Node();

    /*
    Three nodes where allocated dynamically.
    Nodes data are empty.

        head               middle                  tail
            |                    |                    |
            |                    |                    |
    +_____+___+_____+    +_____+___+_____+    +_____+___+_____+
    | %%% | # | %%% |    | %%% | # | %%% |    | %%% | # | %%% |
    +_____+___+_____+    +_____+___+_____+    +_____+___+_____+
    */

    head->previous = NULL;      // the head previous pointer is NULL
    head->data = "im the head"; // assign data for head
    head->next = middle;        // link head with middle node

    /*
    Now the head node has data and next points to middle node.
    Head previous pointer is NULL, indicating that the list begins here.

        head               middle                  tail
            |                    |                    |
            |                    |                    |
    +______+______+_____+    +_____+___+_____+    +_____+___+_____+
    | NULL | data | o ------> %%%  | # | %%% |    | %%% | # | %%% |
    +______+______+_____+    +_____+___+_____+    +_____+___+_____+
    */

    middle->previous = head;        // link middle with head node
    middle->data = "im the middle"; // assign data for middle
    middle->next = tail;            // link middle with tail node

    /*
    Head node has data and next points to middle node.
    Middle node has data, previous points to head node and next points to tail node.

        head               middle                  tail
            |                    |                    |
            |                    |                    |
    +______+______+_____+    +_____+______+_____+    +_____+___+_____+
    | NULL | data | o <-------> o  | data | o----> | %%% | # | %%% |
    +______+______+_____+    +_____+______+_____+    +_____+___+_____+
    */

    tail->previous = middle; // linked tail with middle node
    tail->data = "im the tail";   // assign data for tail
    tail->next = NULL;       // tail points to null

    /*
    Head node has data and next points to middle node.
    Middle node has data, previous points to head node and next points to tail node.
    Tail node has data, previous points to middle node and next points to null,
    indicating that the list ends here.

        head               middle                  tail
            |                    |                    |
            |                    |                    |
    +______+______+_____+    +_____+______+_____+    +___+______+______+
    | NULL | data | o <-------> o  | data | o <------> o | data | NULL |
    +______+______+_____+    +_____+______+_____+    +___+______+______+
    */

    // ------------------------------------------------------------------

    // REMOVE MIDDLE NODE FROM LINKEDLIST!!!

    middle->previous = NULL; // points middle previous node to NULL
    middle->next = NULL;     // points middle next to node to NULL
    tail->previous = head;   // points tail previous node to head
    head->next = tail;       // points the head to tail node

    /*
       Middle node has been removed from list.
       Head now points to the tail node.

        head                 tail
            |                   |
            |                   |
    +______+______+_____+   +_____+______+______+
    | NULL | data | o <-------> o | data | NULL |
    +______+______+_____+   +_____+______+______+
    */

    // ------------------------------------------------------------------

    // REINSERTING THE MIDDLE NODE

    middle->previous = head; // points middle previous node to head
    middle->next = tail;     // points middle next to node to tail
    tail->previous = middle; // points tail previous node to middle
    head->next = middle;     // points the head to middle node

    /*
    Now we have the linked list as the same as before.
    Head node has data and next points to middle node.
    Middle node has data, previous points to head node and next points to tail node.
    Tail node has data, previous points to middle node and next points to NULLm,
    indicating that the list ends here.

        head               middle                  tail
            |                    |                    |
            |                    |                    |
    +______+______+_____+    +_____+______+_____+    +_____+______+______+
    | NULL | data | o <-------> o  | data | o <--------> o | data | NULL |
    +______+______+_____+    +_____+______+_____+    +_____+______+______+
    */

    return 0;
}

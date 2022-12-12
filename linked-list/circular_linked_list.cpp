#include <string>
#include <bits/stdc++.h>

using namespace std;

/* Representation of a node using class.
 */
class Node
{
public:
    string data;
    Node *next;
};

/* Search for a node containing data.
 */
Node *search(Node *n, string data)
{
    while (n)
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
    Circular linked lists can be compared to singly
    linked lists. The difference between them is that
    in a circular linked list, the tail points to head,
    creating a circular reference loop.


    Three nodes where allocated dynamically.
    Nodes data are empty.

    head          middle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +___+_____+
    | # | %%% |    | # | %%% |    | # | %%% |
    +___+_____+    +___+_____+    +___+_____+
    */

    head->data = "im the head"; // assign data for head
    head->next = middle;        // link head with middle node

    /*
    Now the head node has data and next points to middle node.

        head          midlle           tail
            |               |             |
            |               |             |
    +______+_____+    +___+_____+    +___+_____+
    | data |  o ----->| # | %%% |    | # | %%% |
    +______+_____+    +___+_____+    +___+_____+
    */

    middle->data = "im the middle"; // assign data for middle
    middle->next = tail;            // link middle with tail node

    /*
    Head node has data and next points to middle node.
    Middle node has data and next points to tail node.

    head          midlle           tail
        |               |             |
        |               |             |
    +______+_____+    +______+_____+    +___+_____+
    | data | o------->| data |  o------>| # | %%% |
    +______+_____+    +______+_____+    +___+_____+
    */

    tail->data = "im the tail"; // assign data for tail
    tail->next = head;          // tail points to head

    /*
    Head node has data and it's next pointer points to middle node.
    Middle node has data and it's next pointer points to tail node.
    Tail node has data and it's next pointer points to head, creating
    a pointer reference loop.

    head          midlle           tail
        |               |             |
        |               |             |
    +______+_____+    +______+_____+    +_______+_____+
    | data | o------->| data |  o------>|  data | o---> head
    +______+_____+    +______+_____+    +_______+_____+
    */

    // ------------------------------------------------------------------

    // REMOVE MIDDLE NODE FROM LINKEDLIST!!!

    middle->next = NULL; // points middle next pointer to null
    head->next = tail;   // points the head next pointer to tail, removing middle node from the list

    /*
       Middle node has been removed from list and now points to NULL.
       Head now points to the tail node.

       head            tail
           |              |
           |              |
       +___+_____+    +_________+_____+
       | foo | o----->|  foobar | o-----> head
       +___+_____+    +_________+_____+
    */

    // ------------------------------------------------------------------

    // REINSERTING THE MIDDLE NODE
    head->next = middle; // link head with middle node
    middle->next = tail; // link middle with tail

    /*
    Now we have the linked list as the same as before.
    Head node has data and next points to middle node.
    Middle node has data and next points to tail node.
    Tail node has data and next points to head, creating
    a circular reference in the list.

    head          midlle           tail
        |               |             |
        |               |             |
    +______+_____+    +______+_____+    +_______+_____+
    | data | o------->| data |  o------>|  data | o-----> head
    +______+_____+    +______+_____+    +_______+_____+
    */

    return 0;
}

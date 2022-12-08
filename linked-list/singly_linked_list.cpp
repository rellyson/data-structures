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

/* Print each linked list node data.
 */
void displayLinkedList(Node *n)
{
    cout << "\n";

    while (n != NULL)
    {
        cout << "Address:" << n << " | Data:" << n->data << " | Next address ->:" << n->next << endl;
        n = n->next;
    }

    cout << endl;
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
    | data | o------->| # | %%% |    | # | %%% |
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
    tail->next = NULL;          // tail points to null

    /*
    Head node has data and next points to middle node.
    Middle node has data and next points to tail node.
    Tail node has data and next points to null, indicating
    that the linked list ends here.

    head          midlle           tail
        |               |             |
        |               |             |
    +______+_____+    +______+_____+    +________+_____+
    | data | o------->| data |  o------>|  data | NULL
    +______+_____+    +______+_____+    +________+_____+
    */

    // ------------------------------------------------------------------

    // REMOVE MIDDLE NODE FROM LINKEDLIST!!!

    middle->next = NULL; // points middle to null
    head->next = tail;   // points the head to tail

    /*
       Middle node has been removed from list and now points to NULL.
       Head now points to the tail node.

       head            tail
           |              |
           |              |
       +______+_____+    +______+_____+
       | data | o------->| data | NULL
       +______+_____+    +_ ____+_____+
    */

    // ------------------------------------------------------------------

    // REINSERTING THE MIDDLE NODE
    head->next = middle; // link head with middle node
    middle->next = tail; // link middle with tail

    /*
    Now we have the linked list as the same as before.
    Head node has data and next points to middle node.
    Middle node has data and next points to tail node.
    Tail node has data and next points to NULL, indicating
    that the linked list ends here.

    head          midlle           tail
        |               |             |
        |               |             |
    +______+_____+    +______+_____+    +______+_____+
    | data | o------->| data |  o------>| data | NULL
    +______+_____+    +______+_____+    +______+_____+
    */

    return 0;
}

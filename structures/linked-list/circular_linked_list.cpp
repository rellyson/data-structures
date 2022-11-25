#include <string>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
};

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
    Circular linked list can be compared to a
    singly linked list. The only difference between
    them is that in a circular linked list, the tail
    points to head, creating a pointer reference loop.
    Three blocks where allocated dynamically.
    We have the pointers of each node and.
    Each node data is empty.

    head          middle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +___+_____+
    | # | %%% |    | # | %%% |    | # | %%% |
    +___+_____+    +___+_____+    +___+_____+
    */

    head->data = "foo";  // assign data for head
    head->next = middle; // link head with middle node

    /*
    Now the head node has data and it's next pointer points to middle node.

    head          midlle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +___+_____+
    | foo | o----->| bar | % |    | # | %%% |
    +___+_____+    +___+_____+    +___+_____+
    */

    middle->data = "bar"; // assign data for middle
    middle->next = tail;  // link middle with tail node

    /*
    Head node has data and it's next pointer points to middle node.
    Middle node has data and it's next pointer points to tail node.

    head          midlle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +________+_____+
    | foo | o----->| bar |  o---->| foobar | %%% |
    +___+_____+    +___+_____+    +________+_____+
    */

    tail->data = "foobar"; // assign data for tail
    tail->next = head;     // tail points to head

    /*
    Head node has data and it's next pointer points to middle node.
    Middle node has data and it's next pointer points to tail node.
    Tail node has data and it's next pointer points to head, creating
    a pointer reference loop (if we traverse this linked list, we will
    get stuck in a infinite loop due to its circular reference).

    head          midlle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +________+_____+
    | foo | o----->| bar |  o---->|  foobar | o-----> head
    +___+_____+    +___+_____+    +________+_____+
    */



    // REMOVE MIDDLE NODE FROM LINKEDLIST!!!

    middle->next = NULL; // points middle to null
    head->next = tail;   // points the head to tail

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



    // REINSERTING THE MIDDLE NODE
    head->next = middle; // link head with middle node again
    middle->next = tail; // link middle with tail again

    /*
    Now we have the linked list the same as before.
    Head node has data and it's next pointer points to middle node.
    Middle node has data and it's next pointer points to tail node.
    Tail node has data and it's next pointer is NULL to indicate that
    the linked list ends here.

    head          midlle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +________+_____+
    | foo | o----->| bar |  o---->|  foobar | o-----> head
    +___+_____+    +___+_____+    +________+_____+
    */

    return 0;
}

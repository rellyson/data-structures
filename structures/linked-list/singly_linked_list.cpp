#include <string>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
};

/* Print each linked list node data.
 */
void displayList(Node *n)
{
    cout << "\n";

    while (n != NULL)
    {
        cout << "Address:" << n << " | Data:" << n->data << " | Next address ->:" << n->next << endl;
        n = n->next;
    }

    cout << endl;
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
    tail->next = NULL;     // tail points to null

    /*
    Head node has data and it's next pointer points to middle node.
    Middle node has data and it's next pointer points to tail node.
    Tail node has data and it's next pointer is NULL to indicate that
    the linked list ends here.

    head          midlle           tail
        |               |             |
        |               |             |
    +___+_____+    +___+_____+    +________+_____+
    | foo | o----->| bar |  o---->|  foobar | NULL
    +___+_____+    +___+_____+    +________+_____+
    */

    // REMOVE MIDDLE NODE FROM LINKEDLIST!!!

    cout << "Linked List before removing middle node!!!" << endl;
    displayList(head);

    middle->next = NULL; // points middle to null
    head->next = tail;   // points the head to tail

    /*
       Middle node has been removed from list and now points to NULL.
       Head now points to the tail node.

       head            tail
           |              |
           |              |
       +___+_____+    +_________+_____+
       | foo | o----->|  foobar | NULL
       +___+_____+    +_________+_____+
    */

    cout << "Linked List after removing middle node!!!" << endl;
    displayList(head);

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
    | foo | o----->| bar |  o---->|  foobar | NULL
    +___+_____+    +___+_____+    +________+_____+
    */

    cout << "Linked List after reinserting middle node!!!" << endl;
    displayList(head);

    return 0;
}

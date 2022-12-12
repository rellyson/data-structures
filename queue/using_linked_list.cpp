#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class Queue
{
    Node<T> *_head;

public:
    Queue()
    {
        this->_head = NULL;
    }

    /* Adds a Node to the end of the queue
    and points the node to the queue.
    */
    void enqueue(T data)
    {
        // creating new node
        Node<T> *node = new Node<T>();
        node->data = data; // assign data
        node->next = NULL; // points next to NULL, indicating the end of the queue

        if (!this->_head)
            this->_head = node; // if head is not defined yet, assign created node
        else
        {
            Node<T> *n = this->_head;

            /* Traverse the queue and looks for
            the last queue node. Assigns the
            created node as its next pointer (new
            node is now the last element of the
            queue).
            */
            while (n)
            {
                if (n->next)
                    n = n->next;
                else
                {
                    n->next = node;
                    return;
                }
            }
        }
    }

    /* Replaces the first Node on the queue,
    returning its data.
    */
    T dequeue()
    {
        Node<T> *front = this->_head;
        this->_head = this->_head->next;
        front->next = NULL;

        return front->data;
    }

    /* Returns the first Node in the queue
    without removing it.
    */
    T front()
    {
        return this->_head->data;
    }
};

int main()
{
    Queue<string> *firstFiveGreekLetters = new Queue<string>();

    firstFiveGreekLetters->enqueue("alpha");
    firstFiveGreekLetters->enqueue("beta");
    firstFiveGreekLetters->enqueue("gamma");
    firstFiveGreekLetters->enqueue("delta");
    firstFiveGreekLetters->enqueue("epsilon");

    cout << firstFiveGreekLetters->dequeue() << endl; // replaces first Node and returns its data (alpha)
    cout << firstFiveGreekLetters->front() << endl;   // returns beta

    return 0;
}
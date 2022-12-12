#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *previous;
};

template <class T>
class Stack
{
    Node<T> *_top;

public:
    Stack()
    {
        this->_top = NULL; // initial top value
    }

    /* Pushes a Node to the top of the stack
       and points the node to a Linked List.
     */
    void push(T data)
    {
        // creating new node
        Node<T> *node = new Node<T>();
        node->data = data;           // assign data
        node->previous = this->_top; // points new node to current top node
        node->next = NULL;           // points next to NULL, indicating the end of the stack

        if (this->_top != NULL)
            this->_top->next = node; // points current node next to new node

        this->_top = node; // assign new node to top
    }

    /* Removes the Node from the top of the stack
      and from the Linked List then returns it.
    */
    T pop()
    {
        Node<T> *top = this->_top;

        this->_top = top->previous;
        this->_top->next = NULL;

        return top->data;
    }

    /* Returns the Node in the top of the stack
    without removing it.
    */
    T peek()
    {
        return this->_top->data;
    }
};

int main()
{
    /* Initializing a new string Stack. The advantage
    of use linked list with stacks is that we have a
    dynamically sized Stack so we can push as many data
    as we want.

    Pushing 7 elements to Stack.
    */
    Stack<string> *topFootballPlayers = new Stack<string>();
    topFootballPlayers->push("Cristiano Ronaldo");
    topFootballPlayers->push("Messi");
    topFootballPlayers->push("Neymar JR");
    topFootballPlayers->push("Ronaldinho Gaucho");
    topFootballPlayers->push("Thierry Henry");
    topFootballPlayers->push("Ronaldo Fenomeno");
    topFootballPlayers->push("Vinicius JR");

    cout << topFootballPlayers->pop() << endl;  // removes the last element ("Vinicius JR") and returns it
    cout << topFootballPlayers->peek() << endl; // only returns the last element ("Ronaldo Fenomeno")

    return 0;
}

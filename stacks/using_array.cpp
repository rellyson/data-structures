#include <iostream>

using namespace std;

template <class T, ssize_t N>
class Stack
{
    int _top;
    int _size;
    T _items[N];

public:
    Stack()
    {
        this->_top = -1; // initial top value
        this->_size = N; // stack size
    }

    /* Pushes an element to the top of the stack.
    If the stack is complete, does not push the
    element and returns.
     */
    void push(T item)
    {
        // skip push if stack is complete
        if (this->isComplete())
            return;

        this->_top++;
        this->_items[this->_top] = item;
    }

    /* Removes the element in the top of the stack,
    returing it.
    */
    T pop()
    {
        T top = this->_items[this->_top];
        this->_items[this->_top] = NULL;
        this->_top--;

        return top;
    }

    /* Returns the element in the top of the stack
    without removing it.
    */
    T peek()
    {
        return this->_items[this->_top];
    }

    // Returns whether a stack is empty or not.
    bool isEmpty()
    {
        return this->_top == -1; // if top == -1 no value is present in the stack (empty)
    }

    // Returns whether a stack is complete or not.
    bool isComplete()
    {
        return this->_top == this->_size - 1; // if top equals to size-1, the stack is full.
    }
};

int main()
{
    /* Initialing an integer stack with size 5
    and pushing 4 elements.
    */
    Stack<int, 5> *firstFiveFibonacciSeq = new Stack<int, 5>();
    firstFiveFibonacciSeq->push(1);
    firstFiveFibonacciSeq->push(2);
    firstFiveFibonacciSeq->push(3);
    firstFiveFibonacciSeq->push(5);
    firstFiveFibonacciSeq->push(8);

    cout << firstFiveFibonacciSeq->pop() << endl;  // removes the last element (8) and returns it
    cout << firstFiveFibonacciSeq->peek() << endl; // only returns the last element (5)

    return 0;
}

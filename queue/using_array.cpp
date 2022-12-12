#include <iostream>

using namespace std;

template <class T, int N>
class Queue
{
    T _items[N];
    int _size;

public:
    Queue()
    {
        this->_size = 0;
    }

    /* Adds an element to the end of the queue.
    If the queue is complete, does not push the
    element and returns.
     */
    void enqueue(T item)
    {
        // skip enqueue if queue is complete
        if (this->isComplete())
            return;

        this->_items[this->_size] = item;
        this->_size++;
    }

    /* Removes the first element of the queue,
      returning the element.
    */
    T dequeue()
    {
        T front = this->_items[0];

        for (int i = 0; i < this->_size; i++)
        {
            if (i < this->_size - 1)
                this->_items[i] = this->_items[i + 1];
            else
                this->_items[i] = NULL;
        }

        this->_size--;

        return front;
    }

    /* Returns the first element of the queue
    without removing it.
    */
    T front()
    {
        return this->_items[0];
    }

    // Returns whether the queue is complete or not.
    bool isComplete()
    {
        return this->_size == N;
    }
};

int main()
{
    /* Initialing an integer queue with size 5
      and enqueue elements.
      */
    Queue<int, 5> *brazilianWCTitles = new Queue<int, 5>();
    brazilianWCTitles->enqueue(1958);
    brazilianWCTitles->enqueue(1962);
    brazilianWCTitles->enqueue(1970);
    brazilianWCTitles->enqueue(1994);
    brazilianWCTitles->enqueue(2002);

    cout << brazilianWCTitles->dequeue() << endl; // removes the first element (1958) and returns it
    cout << brazilianWCTitles->front() << endl;   // only returns the first element (1962)

    return 0;
}

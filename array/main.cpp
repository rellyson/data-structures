#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* Removes an element from array (if the element exists).
 */
void removeElement(string arr[], int size, string element)
{
    const int lastIndex = size - 1; // last array index

    for (int i = 0; i <= lastIndex; i++)
    {
        if (arr[i] == element)
        {
            for (int j = i; j <= lastIndex; j++)
            {
                if (j == lastIndex)
                    arr[j] = ""; // when j is the last element, replace with default ("")
                else
                    arr[j] = arr[j + 1]; // shift current element with the next element
            }
        }
    }
}

int main()
{
    /* Arrays are strucutures used to store multiple elements
    of the same type in a single variable. It stores the elements
    in contiguous memory locations that can be accessed using an
    index.

    Arrays can be left unitialized or explicitly initialized to
    specific values, as below.

    In C/C++, when no array size is specified (square brackets empty[]),
    the compiler will assume automatically a size for the array that
    matches the number of elements inside the array.
    */
    string programmingLanguages[5] = {"C++", "Rust", "Golang", "Python"};

    // ------------------------------------------------------------------------

    /* APPENDING ELEMENTS

    In Plain arrays, we can append elements in the range of the array size.
    For example, the programmingLanguages array has a length of 5, so we can
    append elements between the indexes 0 and 4.
    */
    programmingLanguages[4] = "Elixir";
    // programmingLanguages[5] = "Clojure"; // if we try to run this code, we get a buffer overflow exception

    /*
    Plain arrays in C/C++ cannot change size at runtime. If you
    intend to change the size, use the std::vector library instead.
    */
    vector<string> topProgrammingLanguages = {"Javascript", "Python"};

    topProgrammingLanguages.push_back("Java"); // we can add elements to a vector during runtime

    // ------------------------------------------------------------------------

    /* ACCESSING ELEMENTS

    We can access an array element by referring to the its index.
    Array indexes starts with 0. To access the element in position 2,
    we need to specify the position-1 (1) index.
    */
    cout << programmingLanguages[1] << endl;    // Outputs Rust from plain array
    cout << topProgrammingLanguages[0] << endl; // Outputs Javascript from std::vector

    // ------------------------------------------------------------------------

    // REMOVING ELEMENTS

    removeElement(programmingLanguages, 5, "C++"); // calls removeElement to remove C++ from plain Array

    topProgrammingLanguages.pop_back(); // removes the last element from vector
    topProgrammingLanguages.clear();    // removes all elements from vector
                                        // vector has other many removing methods such as erase, remove and remove_if.

    // ------------------------------------------------------------------------

    /* MULTIDIMENSIONAL ARRAYS

    We can also have multidimensional arrays (arrays of arrays).

    For example, we can have a bi-dimensional array representating
    a matrix or a table.
    */
    int table[2][2] = {{1, 2}, {3, 4}};

    /*  We can illustrate this table as shown below.

    +___+___+
    | 1 | 2 |
    | --+-- |
    | 3 | 4 |
    +---+---+
    */

    return 0;
}
#include <iostream>
using namespace std;

class Item
{
    int m_value; // Value of the item
    Item* m_next; // Pointer to the next item in the list
public:
    Item(int value = 0, Item* item = NULL); // Constructor of the class 'Item'
    int value() const { return m_value; } // Return the value of the item
    Item* next() const { return m_next; } // Return the pointer to the next item
    void next(Item* ptr) { m_next = ptr; } // Set the pointer to the next item
};

class IntList
{
    Item* m_front, * m_end; // Pointers to the first and last item in the list
    int m_size; // Size of the list
public:
    IntList() { m_front = m_end = NULL; m_size = 0; } // Constructor of the class 'IntList'
    ~IntList() { remove_all(); } // Destructor of the class 'IntList'

    void insert_front(int value); // Insert an item with value 'value' at the front
    void insert_end(int value); // Insert an item with value 'value' at the end
    void insert_order(int value); // Insert an item with value 'value' in order
    IntList& join(IntList& za, IntList& zb); // Join two unordered lists
    IntList& join_ordered(IntList& za, IntList& zb); // Join two ordered lists
    void remove_front(); // Remove the first item in the list
    void remove_all(); // Remove all items from the list
    int numb_of_occurr(int value); // Count occurrences of 'value' in the list
    void display(); // Display the values in the list
    void reverse(IntList& list); // Reverse the list
    Item* front() const { return m_front; } // Return the first item in the list
    Item* end() const { return m_end; } // Return the last item in the list
    int size() const { return m_size; } // Return the size of the list
    void bump_up() { m_size++; } // Increase the size of the list
    void bump_down() { m_size--; } // Decrease the size of the list
};
IntList& operator+(IntList& za, IntList& zb); // Overloaded '+' operator for joining two unordered lists
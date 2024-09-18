#include "class.h"
// Definition of the parameterized constructor of the 'Item' class
Item::Item(int value, Item* item) : m_value(value)
{
    if (!item) // If the pointer to the next item in the list is NULL,
        m_next = NULL; // Then we initialize the instance variable 'm_next' to NULL
    else
    {
        m_next = item->m_next;
        item->m_next = this;
    }
}
// Definition of a member function that inserts an item with value 'value' at the end of the list
void IntList::insert_end(int value)
{
    if (!m_end) // If the list is empty,
        m_end = m_front = new Item(value); // Insert the new item as the first and last one
    else
        m_end = new Item(value, m_end); // Otherwise, insert it at the end

    bump_up();
}
// Definition of a member function that inserts an item with value 'value' at the beginning of the list
void IntList::insert_front(int value)
{
    Item* ptr = new Item(value); // Create a pointer to the new item being inserted

    if (!m_front) // If the list is empty,
        m_front = m_end = ptr; // Insert it as the first (and last) item in the list
    else
    {
        ptr->next(m_front); // Insert the new item before the first item in the list
        m_front = ptr;
    }

    bump_up();
}
// Definition of a member function that inserts an item with value 'value' in order
void IntList::insert_order(int value)
{
    Item* ptr = new Item(value); // Create a pointer to the new item being inserted
    if (!m_front) // If the list is empty,
        m_front = m_end = ptr; // Insert it as the first item
    else
    {
        Item* pred = NULL, * next_item = m_front;
        enum { SEARCHING, FINISH } state = SEARCHING;
        while ((state == SEARCHING) && (next_item != 0))
            if (next_item->value() >= value)
                state = FINISH; // Suitable position found!
            else
            {
                pred = next_item;
                next_item = next_item->next();
            }
        if (pred == NULL) // Insert new item at the start
        {
            m_front = ptr;
            ptr->next(next_item);
        }
        else if (next_item == NULL) // Insert new item at the end
        {
            m_end->next(ptr);
            ptr->next(NULL);
            m_end = ptr;
        }
        else // Insert the new item between existing ones
        {
            pred->next(ptr);
            ptr->next(next_item);
        }
    }
    bump_up();
}
// Definition of a member function that merges two unordered lists 'za' and 'zb'
IntList& IntList::join(IntList& za, IntList& zb)
{
    IntList* new_list = new IntList;
    Item* p1 = za.front();
    Item* p2 = zb.front();
    while (p1 != NULL)
    {
        new_list->insert_end(p1->value());
        p1 = p1->next();
        bump_up();
    }
    while (p2 != NULL)
    {
        new_list->insert_end(p2->value());
        p2 = p2->next();
        bump_up();
    }
    return (*new_list);
}
// Definition of a member function that merges two ordered lists 'za' and 'zb'
IntList& IntList::join_ordered(IntList& za, IntList& zb)
{
    IntList* new_list = new IntList;
    Item* p1 = za.front();
    Item* p2 = zb.front();
    while (p1 != NULL)
    {
        new_list->insert_order(p1->value());
        p1 = p1->next();
        bump_up();
    }
    while (p2 != NULL)
    {
        new_list->insert_order(p2->value());
        p2 = p2->next();
        bump_up();
    }
    return (*new_list);
}
// Overloaded '+' operator for joining two unordered lists
IntList& operator+(IntList& za, IntList& zb)
{
    IntList* new_list = new IntList;
    Item* p1 = za.front();
    Item* p2 = zb.front();
    while (p1 != NULL)
    {
        new_list->insert_end(p1->value());
        p1 = p1->next();
    }
    while (p2 != NULL)
    {
        new_list->insert_end(p2->value());
        p2 = p2->next();
    }
    return (*new_list);
}
// Definition of a member function that removes the first item from the list
void IntList::remove_front()
{
    if (m_front) // If the list is not empty
    {
        Item* ptr = m_front;
        m_front = m_front->next(); // Update the pointer to the next item
        bump_down();
        delete ptr; // Delete the first item
    }
}
// Definition of a member function that removes all items from the list
void IntList::remove_all()
{
    while (m_front)
        remove_front();

    m_size = 0;
    m_front = m_end = NULL;
}
// Definition of a member function that counts the number of occurrences of 'value' in the list
int IntList::numb_of_occurr(int value)
{
    int occurrences = 0;
    Item* ptr = m_front;
    while (ptr)
    {
        if (ptr->value() == value)
            occurrences++;
        ptr = ptr->next();
    }

    return occurrences;
}
// Definition of a member function that displays the values in the list
void IntList::display()
{
    cout << " (size " << m_size << ") ( ";
    Item* ptr = m_front;
    while (ptr)
    {
        cout << ptr->value() << " ";
        ptr = ptr->next();
    }
    cout << ")\n";
}
// Definition of a member function that reverses the list
void IntList::reverse(IntList& list) {
    IntList* reversed_list = new IntList;
    Item* ptr = m_front;
    while (ptr)
    {
        reversed_list->insert_front(ptr->value());
        ptr = ptr->next();
    }
    reversed_list->display();
}

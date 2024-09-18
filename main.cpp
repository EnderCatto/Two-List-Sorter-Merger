#include "class.h"
int main()
{
    int n, data, a, insert_c1_into_l2, insert_c2_into_l2, insert_c3_into_l2, search_c_in_l2;
    IntList l, l_ordered, l1, l2;
    cout << "Enter the base size of the lists you want to create: ";
    cin >> n;
    cout << "\nEnter " << n << " elements that will be inserted unordered into list L1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        l1.insert_end(data);
    }
    cout << "\nList L1 = ";
    l1.display();
    cout << "\n_____________________________________________________________\n\nEnter " <<
        n << " elements that will be inserted ORDERED into list L2: \n";
    for (int j = 0; j < n; j++)
    {
        cin >> a;
        l2.insert_order(a);
    }
    cout << "\nList L2 = ";
    l2.display();
    cout << "\nEnter 3 numbers that will be inserted ORDERED into list L2:\n";
    cin >> insert_c1_into_l2 >> insert_c2_into_l2 >> insert_c3_into_l2;
    l2.insert_order(insert_c1_into_l2);
    l2.insert_order(insert_c2_into_l2);
    l2.insert_order(insert_c3_into_l2);
    cout << "\nList L2 with ORDERED inserted numbers " << insert_c1_into_l2 << ", " <<
        insert_c2_into_l2 << " and " << insert_c3_into_l2 << "\nList L2 = ";
    l2.display();
    cout << "\nEnter the number to be searched in list L2: ";
    cin >> search_c_in_l2;
    cout << "Number of occurrences of " << search_c_in_l2 << " in list L2: " <<
        l2.numb_of_occurr(search_c_in_l2);
    cout << "\n______________________________________________________________";
    cout << "\n\n\nElements ONLY from the merged list Z = L1 + L2 using the '+' operator:\n ";
    l = l1 + l2;
    l.display();
    l = l.join(l, l1);
    cout << "\n\nElements ONLY from the merged list Z (= Z + L1) using the 'join' instance function:\n ";
    l.display();

    l_ordered = l_ordered.join_ordered(l, l1);
    cout << "\n\nOrdered elements of the merged list Z_ord (= Z + L1) using the 'join_ordered' instance function:\n ";
    l_ordered.display();

    cout << "\n\nReversed list Z:\n ";
    l.reverse(l);
    l.display();

    cout << "\n\nReversed list Z_ord:\n ";
    l_ordered.reverse(l_ordered);
    l_ordered.display();
    return 0;
}

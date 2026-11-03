#include <iostream>
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;
    Node(int i, Node *p)
    {
        data = i;
        next = p;
    }
};

// print all integers in the list, in order
void print(Node *head)
{
    // IMPLEMENT ME
    /*
 answer,

     Node *tmp = head;
     while(tmp != nullptr) {
         cout << tmp->data << " ";
         tmp = tmp->next;
     }
 cout << endl;
 */

    Node *tmp = head; // new node / copy of node where tmp is the head rn

    while (tmp != nullptr)
    { // if tmp ( head of tmp which is head of node* itself ) is not nullpointer (no value) cout okk

        cout << tmp->data << " "; // print item of pointed to item

        tmp = tmp->next; // ok so this goes to the next item
    }
    cout << endl; // ans says to end this line
}

// find integer t from the list, returning a pointer to that node.
// If there are more than one match, return the first one.
// if not found, return nullptr
Node *find(Node *head, int t)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->data == t)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

// insert integer t to the list as the new head
// (yep, you can pass pointers by reference!)
void insert_head(Node *&head, int t)
{
    Node *tmp = new Node(t, head);
    head = tmp;
}

// insert t as a new node after "location"
// location is assumed to point to a valid position in the list
void insert_after(Node *location, int t)
{
    // IMPLEMENT ME

    Node *tmp = new Node(t, location->next); // new node tmp and has value of t, and location is location next since its after
    location->next = tmp;                    // location next needs to be defined then
}

// remove head from the list
void remove_head(Node *&head)
{
    // IMPLEMENT ME
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

// remove the NEXT integer i.e. AFTER the one pointed to by "location",
// NOT the one pointed to by it.
// location is assumed to point to a valid position in the list.
// If there is no next integer after location (i.e. location points to
// the last one) do nothing
void remove_after(Node *location)
{
    // IMPLEMENT ME

    Node *tmp = location->next;
    location->next = tmp->next;
    delete tmp;
}

int main()
{
    // some example usage of these functions
    Node *mylist = nullptr;
    print(mylist);
    insert_head(mylist, 1);
    insert_head(mylist, 2);
    insert_head(mylist, 3);
    print(mylist);
    Node *result = find(mylist, 3);
    if (result != nullptr)
        insert_after(result, 5);
    print(mylist);
    remove_head(mylist);
    print(mylist);
    remove_after(find(mylist, 5));
    print(mylist);
}

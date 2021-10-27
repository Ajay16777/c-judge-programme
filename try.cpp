#include<stdio.h>
// template related keywords removed (T is the generic object type)
class List {
    private:
    // nested Node class
    struct Node {
        T data;
        Node *prev;
        Node* next;
        Node(const T& d = T(), Node* p = NULL, Node* n = NULL)
            : data(d), prev(p), next(n) { }
    };

    public
    class const_iterator {
        //nested const_iterator class
    }
    class iterator : public const_iterator {
        //nested iterator class
    }

    public:
    // member functions that are commented out may have parameters and return values, but we did not specify them in detail

    // constructor, destructor, copy constructor, and assignment operator
    List();
    List(const List& rhs);
    List& operator=(const List& rhs);
    ~List();

    // member functions , empty(), clear()
    bool empty() const;
    void clear();


    int size(); // return the number of elements in the list

    void remove(cont T& val); // delete all elements with value val in the list

    // member functions front() and back()
    T& front();
    T& back();

    // member functions begin() and end()
    iterator begin();
    iterator end();

    // member functions push_front(), push_back(), pop_front(), pop_back()
    void push_front(const T& val);
    void push_back(const T& val);
    void pop_front();
    void pop_back();

    // member functions insert() and erase()
    iterator insert(iterator pos, const T& val);
    iterator erase(iterator pos);


private:
    Node* head; // head node
    Node* tail; // tail node
    
};


// constructor
List::List() {
    head = NULL;
    tail = NULL;
}

List::List(const List& rhs) {
    head = NULL;
    tail = NULL;
    Node* curr = rhs.head;
    while (curr != NULL) {
        push_back(curr->data);
        curr = curr->next;
    }
}

List& List::operator=(const List& rhs) {
    if (this != &rhs) {
        clear();
        Node* curr = rhs.head;
        while (curr != NULL) {
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

List::~List() {
    clear();
}


// member functions
bool List::empty() const {
    return head == NULL;
}

// clear the list
void List::clear() {
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}


// size
// return the number of elements in the list
// develop a recursive algorithm to compute the size
int List::size() {
    if (head == NULL) {
        return 0;
    }
    int count = 1;
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}


// remove
void List::remove(cont T& val) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == val) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }
}

// worst case explain of remove
// if the list is empty, then there is nothing to remove
// if the list is not empty, then we need to find the node with the value val
// if the node is the head, then we need to update the head
// if the node is the tail, then we need to update the tail
// if the node is in the middle, then we need to update the previous node's next pointer to point to the next node
// if the node is not in the middle, then we need to update the previous node's next pointer to point to the next node
// if the node is not in the middle, then we need to update the next node's prev pointer to point to the previous node
//so worst case is O(n)

// front
T& List::front() {
    return head->data;
}

// back
T& List::back() {
    return tail->data;
}

// begin
List::iterator List::begin() {
    return iterator(head);
}

// end
List::iterator List::end() {
    return iterator(NULL);
}

// push_front
void List::push_front(const T& val) {
    Node* temp = new Node(val, NULL, head);
    if (head != NULL) {
        head->prev = temp;
    }
    else {
        tail = temp;
    }
    head = temp;
}

// push_back
void List::push_back(const T& val) {
    Node* temp = new Node(val, tail, NULL);
    if (tail != NULL) {
        tail->next = temp;
    }
    else {
        head = temp;
    }
    tail = temp;
}

// pop_front
void List::pop_front() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }
}

// pop_back
void List::pop_back() {
    if (tail != NULL) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }
        delete temp;
    }
}

// insert
List::iterator List::insert(iterator pos, const T& val) {
    Node* temp = new Node(val, pos.current->prev, pos.current);
    if (pos.current->prev != NULL) {
        pos.current->prev->next = temp;
    }
    else {
        head = temp;
    }
    pos.current->prev = temp;
    return iterator(temp);
}
// erase
List::iterator List::erase(iterator pos) {
    if (pos.current->next != NULL) {
        pos.current->next->prev = pos.current->prev;
    }
    else {
        tail = pos.current->prev;
    }
    if (pos.current->prev != NULL) {
        pos.current->prev->next = pos.current->next;
    }
    else {
        head = pos.current->next;
    }
    Node* temp = pos.current;
    pos.current = pos.current->next;
    delete temp;
    return pos;
}

// size_t size() returns the number of elements in the list
// use a recursive algorithm to compute the size
// implement a helper function to compute the size
// call the helper function within the size() function
// the helper function should return the number of elements in the list
// if the list is empty, then the size is 0
// if the list is not empty, then the size is 1 + the size of the list after the first element


size_t List::size() {
    return size_helper(head);
} 

size_helper(Node* head) {
    if (head == NULL) {
        return 0;
    }
    else {
        return 1 + size_helper(head->next);
    }
}

//remove(const T& val)
//delete all elements with value val in the list
list::remove(const T& val) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == val) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else { 
            curr = curr->next;
        }
    }
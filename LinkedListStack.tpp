template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (top != nullptr) {
        Node<T>* doomed = top;
        top = top->next;
        delete doomed;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
     top = nullptr;
    this->length = 0;

    Node<T>* tail = nullptr;
    for (Node<T>* cur = copyObj.top; cur != nullptr; cur = cur->next) {
        Node<T>* node = new Node<T>(cur->data);
        if (top == nullptr) {
            top = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        ++this->length;
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
     if (isEmpty()) {
        throw string("peek: error, stack is empty, cannot access the top");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw string("pop: error, stack is empty, avoiding underflow");
    }
    Node<T>* doomed = top;
    top = top->next;
    delete doomed;
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
        Node<T>* node = new Node<T>(elem);
    node->next = top;
    top = node;
    ++this->length;

}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) {
        throw string("rotate: error, stack is empty, unable to rotate");
    }
    if (this->length == 1) return;

    if (dir == Stack<T>::RIGHT) {
        // Move top to bottom
        Node<T>* first = top;
        top = top->next;
        first->next = nullptr;

        Node<T>* tail = top;
        while (tail->next != nullptr) tail = tail->next;
        tail->next = first;
    } else if (dir == Stack<T>::LEFT) {
        // Move bottom to top
        Node<T>* prev = nullptr;
        Node<T>* cur = top;
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        // cur is tail, prev is before tail
        prev->next = nullptr;
        cur->next = top;
        top = cur;
    } else {
        throw string("rotate: error, unknown direction");
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}

#include <iostream>

using namespace std;

template<typename T>
class MyList{
private:
    struct Node{
        T data = 0;
        Node* pNext = nullptr;
    };
    
    Node* pHead = nullptr;
    unsigned int size = 0;

public:

    MyList();
    MyList(const MyList& other);
    ~MyList();
    void Add(T value);
    void Printlist();
    void Delete();
    int get_size() const;
    T get_Value(int index) const;
    int get_index(T value) const;
    void insert(int index, T value);
    void erase(int index);
    void Reverse();

    MyList<T>& operator=(const MyList& other)
    {
        if (this == &other) return *this;

        while(pHead)
        {   Node* tmp = pHead;
            pHead = pHead->pNext;
            delete tmp;
        }
        pHead = nullptr;

        this->pHead = other->pHead;

        return *this;
    }
    friend ostream& operator<<(ostream& out, const MyList& list) {
        Node* tmp = list.pHead;
        while(tmp)
        {
            out << tmp->data << "->";
            tmp = tmp->pNext;
        }
        cout << "end";
        return out;
    }
};

int main(void)
{
    MyList<int> l;

    for(int i = 1; i < 10; i++)
    {
        l.Add(i);
    }
    cout << l << endl;

    cout << "--------------------------------------------" << endl;

    l.Delete();
    cout << l << endl;

    cout << "--------------------------------------------" << endl;

    cout << l.get_Value(7) << endl;
    cout << l.get_index(6) << endl;

    cout << "--------------------------------------------" << endl;

    l.insert(3, 9999999);
    cout << l << endl;

    cout << "--------------------------------------------" << endl;

    l.erase(3);
    cout << l << endl;

    cout << "--------------------------------------------" << endl;
    l.Reverse();
    cout << l << endl;
    
    return 0;
}
template<typename T>
MyList<T>::~MyList(){
    while(pHead)    
    {
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    size = 0;
}

template<typename T>
MyList<T>::MyList(){
    pHead = nullptr;
    size = 0;
}

template<typename T>
MyList<T>::MyList(const MyList& other): size(0), pHead(nullptr){
    if (other.pHead) {
        pHead = new Node();
        pHead->data = other.pHead->data;

        Node* current = pHead;
        Node* otherCurrent = other.pHead->pNext;
        while (otherCurrent) {
            current->pNext = new Node();
            current = current->pNext;
            current->data = otherCurrent->data;
            otherCurrent = otherCurrent->pNext;
        }
    }
}
template<typename T>
void MyList<T>::Add(T value){
    if(pHead == nullptr)
    {
        pHead = new Node();
        pHead->data = value;
    }
    else
    {
        Node* tmp = pHead;
        while (tmp->pNext)
        {
            tmp = tmp->pNext;
        }
        tmp->pNext = new Node();
        tmp->pNext->data = value;
    }
    size++;
}
template<typename T>
void MyList<T>::Printlist() {
    Node* tmp = pHead;
    int i = 0;
    while (tmp) {
        cout << "Node number '" << i << "' with data " << tmp->data << " and pNext " << tmp->pNext << endl;
        tmp = tmp->pNext;
        i++;
    }
    cout << "End of list" << endl;
}
template<typename T>
void MyList<T>::Delete(){
    Node* tmp = pHead;

    while(tmp->pNext->pNext)
    {
        tmp = tmp->pNext;
    }
    delete tmp->pNext;
    tmp->pNext = nullptr;
    size--;
}
template<typename T>
int MyList<T>::get_size() const {
    return size;
}
template<typename T>
T MyList<T>::get_Value(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index is out of range");
    }
    Node* tmp = pHead;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->pNext;
    }
    return tmp->data;
}

template<typename T>
int MyList<T>::get_index(T value) const {
    Node* tmp = pHead;
    int index = 0;

    while (tmp) {
        if (tmp->data == value) {
            return index;
        }
        tmp = tmp->pNext;
        index++;
    }

    return -1;
}
template<typename T>
void MyList<T>::insert(int index, T value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index is out of range");
    }

    Node* newNode = new Node();
    newNode->data = value;

    if (index == 0) {
        newNode->pNext = pHead;
        pHead = newNode;
    } else {
        Node* tmp = pHead;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp->pNext;
        }
        newNode->pNext = tmp->pNext;
        tmp->pNext = newNode;
    }

    ++size;
}
template<typename T>
void MyList<T>::erase(int index){
    Node* tmp = pHead;
    for (int i = 0; i < index - 1; ++i) {
        tmp = tmp->pNext;
    }
    Node* tmp2 = tmp->pNext;
    tmp->pNext = tmp->pNext->pNext;
    delete tmp2;
}

template<typename T>
void MyList<T>::Reverse()
{
    Node* prev = nullptr;
    Node* current = this->pHead;
    Node* next = nullptr;

    while (current)
    {
        next = current->pNext;
        current->pNext = prev;

        prev = current;
        current = next;
    }
    this->pHead = prev;
}

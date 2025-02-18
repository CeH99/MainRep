#include <iostream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int value;
        Node* next = nullptr;
    };
    Node* head = nullptr;
    int size = 0;
public:
    ~LinkedList()
    {
        Node* tmp = head;
        while(head)
        {
            head = head->next;
            delete tmp;
        }
    }
    LinkedList() = default;

    void Add(int ivalue);
    void PrintList();
    unsigned int Size() const
    {
        return size;
    }
    void Insert(int iValue, unsigned int uiIndex);
    int GetValue(unsigned int uiIndex) const;
    void SortList();
    int ValueOfCenter();
};

int main(void)
{
    LinkedList a;
    a.Add(3);
    a.Add(2);
    a.Add(96);
    a.Add(10);

    a.PrintList();
    cout << "\nSize of this list is " << a.Size() << endl;

    cout << "------------------------" << endl;

    a.Insert(9999, 1);
    a.PrintList();

    cout << "------------------------" << endl;

    cout << a.GetValue(4) << endl;
    cout << "Size of this list is " << a.Size() << endl;

    cout << "------------------------" << endl;
    a.SortList();
    a.PrintList();
    cout << "Center of list is " << a.ValueOfCenter() << endl;

    return 0;
}

void LinkedList::Add(int ivalue)
{

    Node* newNode = new Node{ivalue};
    
    if(head == nullptr)
        head = newNode;
    else
    {
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    size++;
}

void LinkedList::PrintList()
{
    if(head == nullptr)
    {
        return;
    }

    Node* tmp = head;
    for(int i = 1; tmp != nullptr; i++){
    cout << "element #" << i << " is " << tmp->value << endl;
    tmp = tmp->next;
    }
}

void LinkedList::Insert(int iValue, unsigned int uiIndex)
{
    if (uiIndex >= size) {
            Add(iValue);
            return;
        }
    
   Node* newNode = new Node{iValue};

    if (uiIndex == 0){
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* tmp = head;

        for(int i = 0; i < uiIndex - 1; i++)
        {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    size++;
}

int LinkedList::GetValue(unsigned int uiIndex) const
{
    Node* tmp = head;
    for(int i = 0; i < uiIndex ; i++)
        {
            tmp = tmp->next;
        }

    return tmp->value;
}

void LinkedList::SortList()
{
    bool swapped;
    do{
        swapped = false;
        Node* tmp = head;
        while(tmp->next)
        {
            if(tmp->value > tmp->next->value)
            {               
                int tmp2 = tmp->value;
                tmp->value = tmp->next->value;
                tmp->next->value = tmp2;
                swapped = true;
            }
            tmp = tmp->next;
        }
    }while(swapped);
}

int LinkedList::ValueOfCenter()
{
    Node* fast = head;
    Node* slow = head;
    Node* tmp;
    while(fast && fast->next)
    {   tmp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(size % 2 == 0)
    {
        return slow->value + tmp->value;
    }

    return slow->value;
}
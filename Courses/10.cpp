#include <iostream>
#include <map>

using namespace std;

template <typename TypeA>
TypeA Func(TypeA*& a)
{
   if(a != nullptr)
   {
        delete a;
        a = nullptr;
        cout << "deleted" << endl;
   }
   return 0;
}

template <typename TypeB>
int Func2(TypeB*& mp)
{
    if(mp != nullptr)
    {
        int size = mp->size();
        return size;
    }
    else
    {
        cout << "its zero" << endl;
        return -1;
    }
}

template <typename TypeC>
void Func3(TypeC*& ptr)
{
     if(ptr != nullptr)
    {
        map<int, string>::iterator it = ptr->begin();
        for(int i = 0; it != ptr->end(); it++, i++){
        cout << "element number #" << i+1 << " its: " << it->second << endl;
        }
    }
    else
    {
        cout << "its zero" << endl;
        return;
    }
}

int main(void)
{
    int* a = new int(10);
    map<int, string>* myMap = new map<int, string>{{1, "one"}, {2, "two"}, {3, "three"}};
    Func(a);
    cout << "size of map is: " << Func2(myMap) << endl;

    Func3(myMap);
    return 0;
}
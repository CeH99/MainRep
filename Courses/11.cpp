#include <iostream>
#include <stdexcept>
#include <iterator>

using namespace std;

template<typename T>
class MyVector {
private:
    T* data;
    int size;
    int capacity;

    void resize(int new_capacity);

public:
    MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    ~MyVector();

    void Add(T new_data);
    void clear();
    void Delete();
    int get_size() const;
    T get_Value(int index) const;
    int get_index(T value) const;
    void insert(int index, T value);
    void erase(int index);
    void print_vec() const;

    friend ostream& operator<<(ostream& out, const MyVector& vec) {
        for (int i = 0; i < vec.size; ++i) {
            out << "Element number #" << i + 1 << " " << vec.data[i] << endl;
        }
        return out;
    }


    class Iterator : public std::iterator<std::input_iterator_tag, T> {
        private:
            T* ptr;

        public:
            Iterator() : ptr(nullptr) {} // Конструктор по умолчанию

            void set_ptr(T* new_ptr) { // Метод для установки указателя
                ptr = new_ptr;
            }

            T& operator*() {
                return *ptr;
            }

            Iterator& operator++() {
                ++ptr;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++ptr;
                return temp;
            }

            bool operator==(const Iterator& other) const {
                return ptr == other.ptr;
            }

            bool operator!=(const Iterator& other) const {
                return ptr != other.ptr;
            }
        };

        Iterator begin();

        Iterator end();
};


int main() {
    MyVector<int> vec;

    vec.Add(10);
    vec.Add(20);
    vec.Add(30);
    vec.Add(15346);
    vec.Add(1689340);
    vec.Add(14350);
    vec.print_vec();
    cout << "size of vec is " << vec.get_size() << endl;

    cout << "-----------------------------" << endl;
    vec.Delete();
    vec.print_vec();
    cout << "size of vec is " << vec.get_size() << endl;

    cout << "-----------------------------" << endl;
    cout << "Element on this pos is " << vec.get_Value(7) << endl;
    

    cout << "-----------------------------" << endl;
    vec.insert(3, 6666);
    vec.print_vec();

    cout << "-----------------------------" << endl;
    vec.erase(3);
    vec.print_vec();

    cout << "-------------OPERATOR----------------" << endl;
    cout << vec;

    return 0;
}

template<typename T>
void MyVector<T>::resize(int new_capacity) {
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
MyVector<T>::MyVector() : data(nullptr), size(0), capacity(1) {
    data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template<typename T>
void MyVector<T>::Add(T new_data) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size++] = new_data;
}

template<typename T>
void MyVector<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void MyVector<T>::Delete() {
    if (size > 0) {
        size--;
    }
}

template<typename T>
int MyVector<T>::get_size() const {
    return size;
}

template<typename T>
T MyVector<T>::get_Value(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
int MyVector<T>::get_index(T value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void MyVector<T>::insert(int index, T value) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    if (size == capacity) {
        resize(capacity * 2);
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template<typename T>
void MyVector<T>::erase(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

template<typename T>
void MyVector<T>::print_vec() const {
    for (int i = 0; i < size; i++) {
        cout << "Element number #" << i + 1 << " " << data[i] << endl;
    }
}
template <typename T>
typename MyVector<T>::Iterator MyVector<T>::begin() {
    Iterator it;
    it.set_ptr(data);
    return it;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::end() {
    Iterator it;
    it.set_ptr(data + size);
    return it;
}

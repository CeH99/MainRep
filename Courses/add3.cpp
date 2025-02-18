#include <iostream>
#include <exception>


class out_of_array_range : public std::exception
{
    public:
    inline virtual const char* what() const noexcept override{
        return "out_of_array_range";
    }
};

class Myarr{
    private:
        
        int* arr;
        int size = 0;

    public:
    
    Myarr(int numofelem){
        arr = new int[numofelem];
        size = numofelem;
    }

    ~Myarr(){
        delete[] arr;
    }

    int At(int index)
    {
        if (index < 0 || index >= size) {
            out_of_array_range er;
            throw er;
        }
        return arr[index];
    }
};

int main(void)
{
    Myarr array(10);
    try{
    std::cout << "Enter element number 10 of array: " << "\n";
    int a = array.At(9);
    std::cin >> a;

    std::cout << "Enter element of array: ";
    std::cin >> a;
    array.At(a);
    }
    catch(std::exception& ex)
    {
        std::cout<< "Exception " << ex.what() << "\n";
    }

    return 0;
}
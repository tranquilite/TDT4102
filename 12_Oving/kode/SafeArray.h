#include<iostream>
#include<stdexcept>
#include<cstring>

template<class T>
class SafeArray {
    private:
        T *arr = nullptr;
        int size = 0;

    public:
        SafeArray(int size);
        bool push(T insert);
        bool pop(int index);

        //internals
        T& _gets(int index) const;
        T& _sets(int index);
        bool _resizes(int size);
        bool _validate_range(int e);

        //interface
        T& operator[](int e) const;
        T& operator[](int e);
        T& operator=(T& inp);
};

template<class T>
SafeArray<T>::SafeArray(int size) {
    this->size = size;
    this->arr = new T[size];
}

template<class T>
bool SafeArray<T>::_resizes(int size) {
    T *mv = new T[size];
    std::memcpy(mv, arr, sizeof(T)*(this->size));
}

template<class T>
bool SafeArray<T>::push(T insert) {
    // TODO implementering
    return true;
}

template<class T>
T& SafeArray<T>::operator[](int e) const{
    _validate_range(e);
    std::cout << "EH-const" << std::endl;
    return this->arr[e];
}

template<class T>
T& SafeArray<T>::operator[](int e) {
    _validate_range(e);
    std::cout << "EH-nonconst" << std::endl;
    return this->arr[e];

}

template<class T>
bool SafeArray<T>::_validate_range(int e) {
    if(e > this->size) {
        throw(std::out_of_range("OOR in []"));
    }
    return true;
}

template<class T>
T& SafeArray<T>::operator=(T& that) {}

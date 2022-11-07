// Hardin is doing this

#include "vector.h"

template <class T>
vector<T>::vector() : size_v{0}, elem{nullpt}, space{0} {}

template <class T>
explicit vector<T>::vector(int s) : size_v{s}, elem{new T[s]}, space{s} {}

template <class T>
vector<T>::vector(const vector &src) : size_v{src.size_v}, elem{new double[src.size_v]}, space{src.space}
{
    copy(src.elem, src.elem + size_v, elem); 
}

template <class T>
vector<T>& vector<T>::operator=(const vector& rhs) 
{
    if (this != &rhs)
    {
        T *p = new T[rhs.size_v];       
        copy(rhs.elem, rhs.elem + rhs.size_v, p);  
        delete[] elem;                            
        elem = p;                                 
        size_v = rhs.size_v;
    }

    return *this;  
}

template <class T>
vector<T>::vector(vector&& src) noexcept
: size_v{std::move(src.size_v)}, elem{std::move(src.elem)}, space{std::move(src.space)}
{
    src.size = 0;
    src.elem = NULL;
    src.space = 0;
}

template <class T>
vector<T>& vector<T>::operator=(vector&& rhs) noexcept
{
    delete[] elem;
    size_v = std::move(rhs.size_v);
    elem = std::move(rhs.elem);
    space = std::move(rhs.space);
    rhs.size_v = 0;
    rhs.elem = NULL;
    rhs.space = 0;
    
    return *this;
}

template <class T>
vector<T>::~vector()
{
    delete[] elem;
}

template <class T>
T& vector<T>::operator[] (int n)
{
    return elem[n];
}

template <class T>
const T& vector<T>::operator[] (int n)
{
    return elem[n];
}

template <class T>
int vector<T>::size() const
{
    return size_v;
}

template <class T>
int vector<T>::capacity() const
{
    return space;
}

template <class T>
void vector<T>::resize(int newsize)
{
    reserve(newsize);
    for (int i = size_v; i < newsize; ++i)
        elem[i] = 0;
    size_v = newsize;
}

template <class T>
void vector<T>::push_back(T val)
{
    if (space == 0)
        reserve(8);
    else if (size_v == space)
        reserve(2*space);
    elem[size_v] = val;
    ++size_v;
}

template <class T>
void vector<T>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;
    T *p = new T[newalloc];
    for (int i = 0; i < size_v; ++i)
    {
        p[i] = elem[i];
    }
    delete elem[];
    elem = p;
}

template <class T>
using iterator = T*;

template <class T>
using const_iterator = const T*;

template <class T>
iterator begin()
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

template <class T>
const_iterator begin() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[0]; 
}

template <class T>
iterator end()
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template <class T>
const_iterator end() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template <class T>
iterator insert(iterator p, const T& v)
{
    if (size_v == space)
        reserve(2*space);  
    for (iterator pos = end(); pos != p; --pos)
        *pos = *(pos - 1);
    *pos = &val;
    ++size_v;
    return p;
}

template <class T>
iterator erase(iterator p) 
{
    if (p == end())
        return p;
    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos; 
    --size_v;
    return p;
}
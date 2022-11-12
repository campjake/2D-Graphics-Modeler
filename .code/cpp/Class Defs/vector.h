// Hardin will work on this
// a vector which approximates the stl vector - provided by J.Kath from Canvas
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

template <typename T>
class vector
{
    public :

    vector();                                               // default constructor
    explicit vector(int s);                                 // alternate constructor
    vector(const vector&);                                  // copy constructor
    vector& operator=(const vector&);                 // copy assignment
    vector(vector&&) noexcept;                              // move constructor
    vector& operator=(vector&&) noexcept;             // move assignment
    ~vector();                                               // destructor

    T& operator[] (int n);                    // access: return reference
    const T& operator[] (int n);              // access: return reference

    int size() const;                         // the current size
    int capacity() const;                     // current available space
    void resize(int newsize);                 // grow
    void push_back(T val);                    // add element
    void reserve(int newalloc);               // get more space

    using iterator = T*;
    using const_iterator = const T*;
    iterator begin();                               // points to first element
    const_iterator begin() const;
    iterator end();                                 // points to one beyond the last element
    const_iterator end() const;
    iterator insert(iterator p, const T& v);       // insert a new element v before p
    iterator erase(iterator p);                     // remove element pointed to by p

    private :
    int size_v;      // the size
    T* elem;        // pointer to elements
    int space;      // size + free space
};

template <class T>
vector<T>::vector() : size_v{0}, elem{nullptr}, space{0} {}

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
        p[i] = std::move(elem[i]);
    }
    delete[] elem;
    elem = p;
}

template <class T>
using iterator = T*;

template <class T>
using const_iterator = const T*;

template <class T>
iterator<T> vector<T>::begin()
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

template <class T>
const_iterator<T> vector<T>::begin() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

template <class T>
iterator<T> vector<T>::end()
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template <class T>
const_iterator<T> vector<T>::end() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template <class T>
iterator<T> vector<T>::insert(iterator p, const T& v)
{
    if (size_v == space)
        reserve(2*space);
    for (iterator pos = end(); pos != p; --pos)
        *pos = *(pos - 1);
    p = &v;
    ++size_v;
    return p;
}

template <class T>
iterator<T> vector<T>::erase(iterator p)
{
    if (p == end())
        return p;
    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos;
    --size_v;
    return p;
}

#endif /* VECTOR_H_ */
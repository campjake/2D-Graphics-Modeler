// Hardin is doing this

#include "vector.h"

template <typename T>
vector::vector() : size_v{0}, elem{nullpt}, space{0} {}

explicit vector::vector(int s) : size_v{s}, elem{new T[s]}, space{s} {}

vector::vector(const vector &src) : size_v{src.size_v}, elem{new double[src.size_v]}, space{src.space}
{
    copy(src.elem, src.elem + size_v, elem); 
}

vector& vector::operator=(const vector& rhs) 
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

vector::vector(vector&& src) noexcept
: size_v{std::move(src.size_v)}, elem{std::move(src.elem)}, space{std::move(src.space)}
{
    src.size = 0;
    src.elem = NULL;
    src.space = 0;
}

vector& vector::operator=vector(vector&& rhs) noexcept
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

vector::~vector()
{
    delete[] elem;
}

T& operator[] (int n)
{
    return elem[n];
}

const T& operator[] (int n)
{
    return elem[n];
}

int size() const
{
    return size_v;
}

int capacity() const
{
    return space;
}

void resize(int newsize)
{
    reserve(newsize);
    for (int i = size_v; i < newsize; ++i)
        elem[i] = 0;
    size_v = newsize;
}

void push_back(T val)
{
    if (space == 0)
        reserve(8);
    else if (size_v == space)
        reserve(2*space);
    elem[size_v] = val;
    ++size_v;
}

void reserve(int newalloc)
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

iterator begin()
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

const_iterator begin() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[0]; 
}

iterator end()
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

const_iterator end() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

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

iterator erase(iterator p) 
{
    if (p == end())
        return p;
    for (iterator pos = p + 1; pos != end(); ++pos)
        *(pos - 1) = *pos; 
    --size_v;
    return p;
}
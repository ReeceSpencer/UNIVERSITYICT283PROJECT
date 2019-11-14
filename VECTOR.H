#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstddef>
#include <algorithm>

// The class declaration must have doxygen comments - put these in
// Follow the style in modelfile.h

/**
	 * @class Vector
	 * @brief  Manages and holds any data type (int, string, object, etc.)
	 *
	 * Data is being inputted through Pushback, putting a value in the next available spot
	 *      Data can also be chose to be inputted in a specific spot using overridden []
	 * Data is to be called and grabbed like any simple array (Array[i])
	 *
	 * Vector has a default size from the default constructor, otherwise a chosen size can be set
	 * If when pushBack is used and there isnt enough space or the vector fills, the vector size will double
	 *
	 *
	 * @author Reece
	 * @version 04
	 * @date 12/04/2019 Reece, Started
	 */

template <class T>
class Vector
{
private:
    T* pVec;
    size_t vecMSize = 0;
    size_t vecSize = 0;
    // the encapsulated dynamic array
    // fill in...
    void ResizeVec();

    /**
    * @brief  returns the current Vector class capacity
    *
    * @return integer
    */

    int VectorCap() const;
    //vector<T> m_vector;

public:
    Vector();
    Vector(size_t n);
    ~Vector();
    Vector(const Vector<T>& v);

    /**
    * @brief  returns the current Vector class filled size amount
    *
    * @return integer
    */
    int VectorSize() const;
    const Vector<T>& operator=(const Vector& v);
    T& operator[](size_t index);
    const T& operator [](size_t index) const;

    /**
    * @brief  Insert a new piece of data to be stored onto the end of the Vector class array (variable type unknown)
    *
    * @param  T - class template variable, variable type unknown to class
    */
    void VecPushBack(const T &val);
        // class declaration
        // you fill in the rest and include doxygen comments
};

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector& v){
    int n = v.VectorCap();
    pVec = new T[n]();
    for(int i=0; i<n; i++){
        pVec[i] = v.pVec[i];
    }
    vecMSize = v.vecMSize;
    vecSize = v.vecSize;
    return *this;
}

template <class T>
T& Vector<T>::operator[](size_t index){
    return pVec[index];
}

template <class T>
const T& Vector<T>::operator [](size_t index)const {
    return pVec[index];
}


template <class T>
Vector<T>::Vector()
{
    pVec = new T[1000]();
    vecMSize = 1000;
}

// class implementation follows with normal comments
// you fill in the rest
template <class T>
Vector<T>::Vector(size_t n)
{
    pVec = new T[n]();
    vecMSize = n;
}

template <class T>
Vector<T>::~Vector()
{
    delete [] pVec;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
    int n = v.VectorCap();
    pVec = new T[n]();
    for(int i=0; i<n; i++){
        pVec[i] = v.pVec[i];
    }
    vecMSize = v.vecMSize;
    vecSize = v.vecSize;
}

template <class T>
void Vector<T>::ResizeVec()
{
    size_t newSize = vecMSize*2;
    T*tmp = new T[newSize]{};

    std::copy_n(pVec,vecSize,tmp);

    delete [] pVec;

    pVec = tmp;
    vecMSize = newSize;
}

template <class T>
int Vector<T>::VectorCap() const
{
    return vecMSize;
}

template <class T>
Vector<T>::VectorSize() const
{
    return vecSize;
}

template <class T>
void Vector<T>::VecPushBack(const T &val)
{
    /**<
    bool okay = true;
    try
    {
        m_vector.push_back(val);
    }
    catch(...){
        okay = false;
    }

    //return okay;
    */
    if (vecMSize <= vecSize)
    {
        ResizeVec();
    }
    pVec[vecSize] = val;
    ++vecSize;

}

#endif // VECTOR_H

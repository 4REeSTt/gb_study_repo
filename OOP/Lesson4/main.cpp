#include <iostream>
#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // для assert()

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt():m_length(0), m_data(nullptr){};
    
    ArrayInt(int length);
    ~ArrayInt(){delete[] m_data;};

    int getLength(){return m_length;}

    void erase();
    void resize(int newLength);
    int& operator[](int index);

    void insertBefore(int value, int index);
    void push_back(int value);

//1.--------------------------------------------------
    void pop_back();
    void pop_front();
    void sort();
    void print();

};
#endif

ArrayInt::ArrayInt(int length)
:m_length(length)
{
    assert(length >= 0);
    if(length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}

void ArrayInt::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

void ArrayInt::resize(int newLength)
{
    if(newLength == m_length)
        return;
    if(newLength <= 0)
    {
        erase();
        return;
    }
    int* data = new int[newLength];
    
    if(m_length > 0)
    {
        int elementsToCopy = (newLength > m_length)? m_length : newLength;

        for(int index = 0; index < elementsToCopy; index++)
            data[index] = m_data[index];
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

int& ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void ArrayInt::insertBefore(int value, int index)
{
    assert(index >= 0 && index <= m_length);
    int* data = new int[m_length + 1];
    
    for(int before = 0; before < index; before++)
        data[before] = m_data[before];

    data[index] = value;

    for(int after = index; after < m_length; after++)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    m_length++;

}

void ArrayInt::push_back(int value)
{
    insertBefore(value, m_length);
}

void ArrayInt::pop_back()
{
    if(!m_length)
        return;

    int* data = new int[m_length -1];

    for(int i = 0; i < m_length -1; i++)
        data[i] = m_data[i];

    delete[] m_data;
    m_data = data;
    m_length--;
}

void ArrayInt::pop_front()
{
    if(!m_length)
        return;

    int* data = new int[m_length -1];

    for(int i = 1; i < m_length; i++)
        data[i - 1] = m_data[i];

    delete[] m_data;
    m_data = data;
    m_length--;
}

void ArrayInt::sort()
{
    int tmp;
    int length = m_length;
    while(length > 1){
        for(int i = 0; i < length -1; i++)
            if(m_data[i] > m_data[i+1])
            {
                tmp = m_data[i];
                m_data[i] = m_data[i+1];
                m_data[i+1] = tmp;
            }
        length--;
    }
}

void ArrayInt::print()
{
    std::cout << "( ";
    for(int i = 0; i < m_length; i++)
        std::cout << m_data[i] << ", ";
    std::cout << ")\n";
}



int main()
{
    ArrayInt array(1);    
    array[0] = 20;
    array.push_back(13);
    array.push_back(11);
    array.push_back(12);
    array.push_back(14);
    array.print();
    array.sort();
    array.print();
    array.pop_front();
    array.print();

    return 0;
}

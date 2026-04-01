#pragma once
#include<iostream>
using namespace std;

template <typename T>
class clsDynamicArray
{
protected:
    int _size = 0;
    T* tempArr;
public:
    T* _arr;
    clsDynamicArray(int size = 0)//if we don't pass capacity it will be 0
    {
        if (size <= 0)
            size = 0;

        _size = size;
        _arr = new T[_size]();//allocate memory and initialize to default value
    }

    ~clsDynamicArray()
    {
        delete[] _arr;//release memory
    }

    bool setItem(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;
        _arr[index] = value;
        return true;
    }

    bool isEmpty()
    {
        return _size == 0;
    }

    int size()
    {
        return _size;
    }

    void print()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

    void resize(int newSize)
    {
        if (newSize <= 0)
            _size = 0;
        else {
            tempArr = new T[newSize]();
            int elementsToCopy = (newSize < _size) ? newSize : _size;
            for (int i = 0; i < elementsToCopy; i++) {
                tempArr[i] = _arr[i]; // Copy existing elements to the new array
            }
            delete[] _arr; // Release the old array memory
            _arr = tempArr; // Point to the new array
            _size = newSize; // Update the size
        }
    }

    void reverse()
    {
        tempArr = new T[_size]();
        for (int i = 0; i < _size; i++)
        {
            tempArr[i] = _arr[_size - 1 - i]; // Copy elements in reverse order
        }
        delete[]_arr;
        _arr = tempArr; // Point to the new array
    }

    T getItem(int index)
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range");
        return _arr[index];
    }

    void clear()
    {
        delete[] _arr; // Release the old array memory
        _arr = nullptr; // Set pointer to null
        _size = 0; // Reset size to 0
    }

    bool deleteItemAt(int index)
    {
        if (index < 0 || index >= _size)
            return false;
        else {
            tempArr = new T[_size - 1]();
            for (int i = 0, j = 0; i < _size; i++) {
                if (i != index) {
                    tempArr[j++] = _arr[i]; // Copy elements except the one at the specified index
                }
            }
            delete[] _arr;
            _arr = tempArr;
            _size--;
            return true;
        }
    }

    void deleteFirstItem()
    {
        deleteItemAt(0);
    }

    void deleteLastItem()
    {
        deleteItemAt(_size - 1);
    }

    int find(T value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (_arr[i] == value)
                return i;
        }
        return -1; // Not found
    }

    bool deleteItemByValue(T value)
    {
        int index = find(value);
        if (index == -1)
            return false;
        deleteItemAt(index);
        return true;
    }
    
    bool InsertItemAt(int index, T value)
    {
        if (index < 0 || index > _size)
            return false;
        tempArr = new T[_size + 1]();
        for (int i =0;i<index;i++)
        {
			tempArr[i] = _arr[i]; // Copy elements before the specified index
        }
		tempArr[index] = value; // Insert the new value at the specified index
        for (int i = index; i < _size; i++)
        {
			tempArr[i + 1] = _arr[i]; // Copy elements after the specified index
        }
		delete[] _arr;
		_arr = tempArr; // Point to the new array
        _size++;
		return true;
    }

    void InsertAtBeginning(T value)
    {
        InsertItemAt(0, value);
	}

    bool InsertBefore(int index, T value)
    {
        if (index < 1)
            return InsertItemAt(0, value);
        return InsertItemAt(index-1, value);
	}

    bool InsertAfter(int index, T value)
    {
        if (index >= _size)
            return InsertItemAt(_size - 1, value);
		return
        InsertItemAt(index + 1, value);
    }

    bool InsertAtEnd(T value)
    {
        return InsertItemAt(_size, value);
	}
    
    bool updateItem(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;
        _arr[index] = value;
        return true;
	}
};


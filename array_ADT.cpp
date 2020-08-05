#include<iostream>
#include<limits.h>
using namespace std;

int get_int(string s)
{
    int i;
    cout << s;
    cin >> i;
    return i;
}

class myArray
{
public:
    int total_size;
    int used_size;
    int* base;
    bool* sett;

    myArray(int size)
    {
        total_size = size;
        used_size = 0;
        base = new int[size];
        sett = new bool[size] {false};
    }
    void set(int i, int data);
    int get(int i);
    int max();
    int min();
    int sum();
    //void append(int data);
    int search(int data);
};

void myArray::set(int i, int data)
{
    if (i >= total_size)
    {
        cout << "Index out of bound!" << endl;
    }
    base[i] = data;
    sett[i] = true;
    used_size++;
}

int myArray::get(int i)
{
    if (i >= total_size)
    {
        cout << "Index out of bound!" << endl;
    }
    else
    {
        if (sett[i])
        {
            return base[i];
        }
        else
        {
            cout << "Value is unused!" << endl;
        }
    }
    return -1;
}

int myArray::max()
{
    int m = INT16_MIN;
    for(int i = 0; i < total_size; i++)
    {
        if (sett[i] && m < base[i])
        {
            m = base[i];
        }
    }
    return m;
}

int myArray::min()
{
    int m = INT16_MAX;
    for (int i = 0; i < total_size; i++)
    {
        if (sett[i] && m > base[i])
        {
            m = base[i];
        }
    }
    return m;
}

int myArray::sum()
{
    int sum = 0;
    for (int i = 0; i < used_size; i++)
    {
        if (sett[i])
            sum += base[i];
    }
    return sum;
}

/*void myArray::append(int data)
{
    if (total_size != used_size)
    {
        base[used_size] = data;
        sett[i] = true;
        used_size++;
        cout << "Appended successfully!" << endl;
    }
    else
    {
        cout << "Size is full!" << endl;
    }
}*/

int myArray::search(int data)
{
    for (int i = 0; i < total_size; i++)
    {
        if (sett[i] && base[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Please enter size: ";
    cin >> size;
    myArray A(size);
    cout << "0-quit\n1-set\n2-get\n3-max\n4-min\n5-sum\n6-search\n";
    int choice, data, i;
    cin >> choice;
    while (true)
    {
        switch(choice)
        {
            case 0:
                return 0;
            case 1:
                i = get_int("index: ");
                data = get_int("data: ");
                A.set(i, data);
                break;
            case 2:
                i = get_int("Index: ");
                cout << "Data: " << A.get(i) << endl;
                break;
            case 3:
                cout << "Max: " << A.max() << endl;
                break;
            case 4:
                cout << "Min: " << A.min() << endl;
                break;
            case 5:
                cout << "Sum: " << A.sum() << endl;
                break;
            case 6:
                data = get_int("data: ");
                cout << "Found " << data << " at: " << A.search(data) << endl;
                break;
        }
        choice = get_int("Choice: ");
    }
}
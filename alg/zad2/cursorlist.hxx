#include <iostream>

using namespace std;

template <class T>
class CursorList
{
public:
    struct Node
    {
        T Data;
        int next;
    };

    int cap = 20;
    Node *arr;

    int head;
    int tail;
    int size;
    int spare;

    struct Iterator
    {

        Node *arr;

        int a;
        int nexti;

        bool operator==(const Iterator &lhs);
        bool operator!=(const Iterator &lhs);
        bool operator<=(const Iterator &lhs);
        bool operator<(const Iterator &lhs);
        bool operator>(const Iterator &lhs);
        bool operator>=(const Iterator &lhs);

        Iterator &operator++();
        Iterator &operator++(int);

        // Iterator &operator--();
        // Iterator &operator--(int);

        T &operator*();
        Iterator(Node *ar)
        {
            arr = ar;
            a = 0;
        };

        Iterator(){};

        Iterator(Node *ar, int pos)
        {
            arr = ar;
            a = pos;
        };
    };

    Iterator it;

    CursorList();

    // the copy constructor
    CursorList(const CursorList &source);

    // the move constructor
    CursorList(CursorList &&source);

    // the destructor to free memory
    ~CursorList();

    //uniwersalna referencja
    void push_front(T &&x); //wstawia element na początek
    T pop_front();          //usuwa element z początku i zwraca jego wartość lub wyjątek jeśli pusta

    void push_back(T &&x); //wstawia el na koniec
    T pop_back();          // usuwa el z końca i zwraca wartość lub wyjątek jeśli pusta

    Iterator find(const T &x); //wyszukuje el o wart x i zwraca jego poz

    Iterator erase(Iterator t); //usuwa el i zwraca iter do kolejnego ele

    Iterator insert(Iterator it, T &&x); // wstawia x przed poz it i zwraca pozycję x

    int remove(const T &x); //Usuwa wystąpienia x i zwraca ich liczbę
    int Size();             // zwraca liczę el w liście
    bool empty();           //zwraca true jeśli pusta
    Iterator begin();       //zwraca iterator na pierwszy el
    Iterator end();         //zwraca iterator na koniec
    T get(int);

    Iterator &operator++();
    Iterator &operator--();
    T &operator*();

    T test(int it);
    T test2(int it, int it2);

    int next(int it);
    int prev(int it);
    void Append(T &&aData);
    void Prepend(T &&aData);
    void Traverse();
};

template <class T>
bool CursorList<T>::Iterator::operator==(const Iterator &lhs)
{
    return lhs.a == this->a;
}

template <class T>
bool CursorList<T>::Iterator::operator!=(const Iterator &lhs)
{
    if (lhs.a == this->a)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
T &CursorList<T>::Iterator::operator*()
{

    return arr[a].Data;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::begin()
{
    Iterator it2 = Iterator(arr, head);
    return it2;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::end()
{
    Iterator it2 = Iterator(arr, spare);

    return it2;
}

template <class T>
CursorList<T>::CursorList()
{
    arr = new Node[cap];
    head = 0;
    tail = 0;
    size = 0;
    it = Iterator(arr);
    for (int i = 0; i < cap; ++i)
    {
        arr[i].next = i + 1;
    }
}

template <class T>
bool CursorList<T>::empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//move
template <class T>
CursorList<T>::CursorList(CursorList &&source)
{
    size = source.size;
    cap = source.cap;
    &arr = &source.arr;
    spare = source.spare;
    it = Iterator(arr);

    source.arr = nullptr;
    source.size = 0;
}

//copy
template <class T>
CursorList<T>::CursorList(const CursorList &source)
{
    size = source.size;
    cap = source.cap;
    arr = source.arr;
    spare = source.spare;
    it = Iterator(arr);
}

template <class T>
CursorList<T>::~CursorList()
{
    delete[] arr;
}

template <typename T>
void CursorList<T>::push_front(T &&aData)
{
    if (empty())
    {
        head = 0;
        tail = 0;
        spare = 1;
        size += 1;
        arr[0].Data = aData;
    }

    else
    {
        if (spare != cap)
        {

            arr[spare].Data = aData;
            int temp = arr[spare].next;
            arr[spare].next = head;

            head = spare;
            spare = temp;
            arr[tail].next = spare;

            size++;
        }
    }
}

template <typename T>
void CursorList<T>::Traverse()
{

    for (int a = 0; a <= 7; a++)
    {
        cout << "arr[" << a << "].Data=" << arr[a].Data << "    arr[" << a << "].next=" << arr[a].next << endl;
    }

    cout << "arr[" << spare << "].Data=" << arr[spare].Data << "    arr[" << spare << "].next=" << arr[spare].next << endl;

    cout << "head=" << head << "     tail=" << tail << endl;

    cout << "begin " << *begin() << "end" << *end() << endl;
    int h;
    Iterator i2 = end();
    Iterator i3 = Iterator(arr, spare);
    if (i2 == i3)
    {
        cout << "SOM TAKIE SAME" << *i2 << endl;
    }
    for (Iterator i = begin(); i != end(); ++i)
    {
        if (i == end())
        {
            cout << " no i tu się powinno zatrzymać" << endl;
        }
        std::cout << "tran" << *i << "->" << i.a << endl;
    }

    Iterator i = end();
    cout << "last" << *i << endl;
    cout << "find" << *find(77) << endl;
}

template <typename T>
T CursorList<T>::pop_front()
{

    if (empty())
    {
        throw runtime_error("pop:empty");
    }

    Iterator i = Iterator(arr, head);
    T temp = *i;

    head = arr[i.a].next;
    arr[i.a].next = spare;
    spare = i.a;
    arr[tail].next = spare;

    size--;

    return temp;
}

template <typename T>
void CursorList<T>::push_back(T &&aData)
{
    if (empty())
    {
        head = 0;
        tail = 0;
        spare = 1;
        size += 1;
        arr[0].Data = aData;
    }

    else
    {
        if (spare != cap)
        {

            arr[spare].Data = aData;
            arr[tail].next = spare;

            int s = arr[spare].next;

            tail = spare;
            spare = s;
            arr[tail].next = spare;

            size++;
        }
    }
}

template <typename T>
T CursorList<T>::pop_back()
{

    if (empty())
    {
        throw runtime_error("pop:empty");
    }

    Iterator itt = Iterator(arr, tail);
    Iterator it2 = Iterator(arr, head);
    Iterator it3 = Iterator(arr, head);

    while (it2 != itt)
    {

        it3 = it2;

        ++it2;
    }

    T temp = *it3;

    arr[it2.a].next = spare;
    spare = it2.a;
    tail = it3.a;
    size--;

    return temp;
}

template <class T>
typename CursorList<T>::Iterator &CursorList<T>::Iterator::operator++(int)
{

    a = arr[a].next;
    return *this;
}

template <class T>
typename CursorList<T>::Iterator &CursorList<T>::Iterator::operator++()
{

    a = arr[a].next;
    return *this;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::find(const T &x)
{
    for (Iterator i = Iterator(arr, head); i != end(); i++)
    {
        if (*i == x)
        {
            return i;
        }
    }

    return end();
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::erase(Iterator t)
{
    if (t == end())
    {
        return end();
    }
    Iterator it2 = Iterator(arr, head);
    Iterator it3 = Iterator(arr, head);

    while (it2 != t)
    {
        it3 = it2;

        ++it2;
    }

    arr[it3.a].next = arr[it2.a].next;
    ++it2;
    --size;
    return it2;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::insert(Iterator it, T &&x)
{

    if (it == end())
    {
        return end();
    }

    Iterator it2 = Iterator(arr, head);
    Iterator it3 = Iterator(arr, head);

    while (it2 != it)
    {
        it3 = it2;

        ++it2;
    }
    int temp = spare;
    arr[spare].Data = x;
    spare = arr[spare].next;
    arr[it3.a].next = temp;
    arr[temp].next = it2.a;
    size++;
    return it3;
}

template <class T>
int CursorList<T>::remove(const T &x)
{
    int w = 0;
    Iterator i = begin();

    for (Iterator i = begin(); i != end(); i = find(x))
    {

        w++;
        erase(i);
    }
    return --w;
}
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

        Node &operator*();
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
        Node *ptr;
        int si;
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

        Iterator(Node *aNext, int aData)
            : si(aData), arr(aNext)
        {
            ptr = &arr[aData];
        }
    };

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

    int find(const T &x); //wyszukuje el o wart x i zwraca jego poz

    int erase(int it); //usuwa el i zwraca iter do kolejnego ele

    int insert(int it, T &&x); // wstawia x przed poz it i zwraca pozycję x

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
    return lhs.ptr == this->ptr;
}

template <class T>
bool CursorList<T>::Iterator::operator!=(const Iterator &lhs)
{
    return lhs.ptr != this->ptr;
}

template <class T>
T &CursorList<T>::Iterator::operator*()
{

    return ptr->Data;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::begin()
{
    Iterator it2 = Iterator(arr, tail);
    return it2;
}

template <class T>
typename CursorList<T>::Iterator CursorList<T>::end()
{
    Iterator it2 = Iterator(arr, head);
    return it2;
}

template <class T>
CursorList<T>::CursorList()
{
    arr = new Node[cap];
    head = 0;
    tail = 0;
    size = 0;
    Iterator it = Iterator(arr, 0);
    for (int i = 0; i < cap; ++i)
    {
        arr[i].next = i;
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

// template <class T>
// CursorList<T>::CursorList(const CursorList &source)
// {
//     if (!source.isEmpty())
//     {
//         size = source.size;
//         cap = source.cap;
//         spare = source.spare;

//         arr = new *Node();
//         for (int i = 0; i < size; i += 1)
//         {
//             arr[i] = source.arr[i];
//         }
//     }
// }

template <class T>
CursorList<T>::CursorList(CursorList &&source)
{
    size = source.size;
    cap = source.cap;
    arr = source.arr;
    spare = source.spare;

    source.arr = nullptr;
    source.size = 0;
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

            // Iterator it = Iterator(arr, spare);

            arr[spare].Data = aData;
            arr[spare].next = head;
            head = spare;
            spare = arr[head].next;
            size++;

            // int s = arr[spare].next;
            // arr[spare].next = head;
            // head = spare;
            // spare = s;
        }
    }
}

template <class T>
typename CursorList<T>::Node &CursorList<T>::Node::operator*()
{

    this->Data = arr[next].Data;
    this->next = arr[next].next;
    return *this;
}

template <typename T>
void CursorList<T>::Traverse()
{
    for (Iterator i = end(); i != begin(); ++i)
    {
        int h = i.ptr->Data;
        ;
        std::cout << "tran" << h << "i=" << i.si << std::endl;
    }
    // int h = arr[tail].Data;

    std::cout << "tran" << head << "i=" << tail << std::endl;
}

template <typename T>
T CursorList<T>::pop_front()
{

    if (empty())
    {
        throw runtime_error("pop:empty");
    }

    T temp = arr[head].Data;
    int sp = spare;
    spare = head;
    head = arr[head].next;
    arr[spare].next = sp;


    cout << temp << "<<";

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
        ;
    }

    else
    {
        if (spare != cap)
        {

            arr[spare].Data = aData;
            int s = arr[spare].next;
            arr[tail].next = spare;
            tail = spare;
            spare = s;
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

    Iterator it = Iterator(arr, tail);

    T temp = *it;

    cout << temp << "<<<<" << endl;

    int s = arr[tail].next;
    arr[tail].next = spare;
    spare = tail;
    tail = s;

    size--;
    return temp;
}

template <class T>
typename CursorList<T>::Iterator &CursorList<T>::Iterator::operator++(int)
{

    // ptr = &arr[ptr->next];
    ptr = arr++;

    si = ptr->next - si;
    return *this;
}

template <class T>
typename CursorList<T>::Iterator &CursorList<T>::Iterator::operator++()
{
    // this->s = s2;
    ptr = arr++;
    si = ptr->next - si;
    return *this;
}

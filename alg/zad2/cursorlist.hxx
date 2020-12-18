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
        Node *sptr;
        bool operator==(const Iterator &lhs);
        bool operator!=(const Iterator &lhs);
        bool operator<=(const Iterator &lhs);
        bool operator<(const Iterator &lhs);
        bool operator>(const Iterator &lhs);
        bool operator>=(const Iterator &lhs);

        Iterator &operator++();
        Iterator &operator++(int);

        Iterator &operator--();
        Iterator &operator--(int);

        T &operator*();
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
    int begin();            //zwraca iterator na pierwszy el
    int end();              //zwraca iterator na koniec
    T get(int);

    int &operator++();
    int &operator--();
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
CursorList<T>::CursorList()
{
    arr = new Node[cap];
    head = 0;
    tail = 0;
    size = 0;
    for (int i = 0; i < cap; i++)
    {
        // arr[arr[i].next].Data = i;
        arr[i].next = i + 1;
        arr[i].next;
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

            arr[spare].Data = aData;
            int s = arr[spare].next;
            arr[spare].next = head;
            head = spare;
            spare = s;
            size++;
        }
    }
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
            int s = arr[spare].next;
            arr[tail].next = spare;
            tail = spare;
            spare = s;
            size++;
        }
    }
}

template <class T>
typename CursorList<T>::Node &CursorList<T>::Node::operator*()
{

    return *this;
}

template <typename T>
void CursorList<T>::Traverse()
{
    for (int i = head; i != tail; i = arr[i].next)
    {
        int h = arr[i].Data;
        std::cout << "tran" << h << "i=" << i << std::endl;
    }
    int h = arr[tail].Data;

    std::cout << "tran" << h << "i=" << tail << std::endl;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T, int N>
class Queue
{
    T *tab;
    int head;
    int tail;
    int q_size;

public:
    Queue();
    Queue<T, N>(const Queue<T, N> &s1);
    Queue<T, N>(Queue<T, N> &&s1);
    ~Queue();
    Queue &operator=(const Queue &S)
    {
        cout << "Ocoppy";
        tab = S.tab;
        q_size = S.q_size;
        head = S.head;
        tail = S.tail;
        return *this;
    };
    Queue &operator=(Queue &&S)
    {
        cout << "Omove";
        tab = S.tab;
        q_size = S.q_size;
        head = S.head;
        tail = S.tail;

        return *this;
    };

    void push(T &&x);
    T pop();
    T &front();
    int size();
    bool empty();
};

template <class T, int N>
Queue<T, N>::Queue()
{
    q_size = N + 1;
    tab = (T *)malloc(N);
    head = 0;
    tail = 0;
}

template <class T, int N>
Queue<T, N>::Queue(const Queue<T, N> &s1)
{

    tab = (T *)malloc(N);
    tab = s1.tab;
    q_size = s1.q_size;
    head = s1.head;
    tail = s1.tail;
}

template <class T, int N>
Queue<T, N>::Queue(Queue<T, N> &&s1)
{

    tab = (T *)malloc(N);
    tab = s1.tab;
    q_size = s1.q_size;
    head = s1.head;
    tail = s1.tail;
}

template <class T, int N>
Queue<T, N>::~Queue()
{
}

template <class T, int N>
void Queue<T, N>::push(T &&x)
{
    int temp_head;
    temp_head = (head + 1) % q_size;
    if (temp_head == tail)
    {
        throw out_of_range("queue full");
    }
    else
    {
        tab[head] = x;
        head = temp_head;
    }
}

template <class T, int N>
T Queue<T, N>::pop()

{
    int temp;
    if (tail == head)
    {
        throw out_of_range("queue empty");
    }
    else
    {
        temp = tab[tail];
        tail = (tail + 1) % q_size;
        return temp;
    }
}

template <class T, int N>
T &Queue<T, N>::front()
{
    return tab[tail];
}

template <class T, int N>
int Queue<T, N>::size()
{
    if (tail > head)
    {

        int temp;
        temp = head + (q_size - tail);
        return temp;
    }
    else
    {

        return head - tail;
    }
}

template <class T, int N>
bool Queue<T, N>::empty()
{
    if (tail == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
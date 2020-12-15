

using namespace std;

template <class T>
class ArrayList
{
public:
    int siz;
    T *ptr;
    int cap;

    struct Iterator
    {
        T *sptr;
        bool operator==(const Iterator &lhs);
        bool operator!=(const Iterator &lhs);
        bool operator<=(const Iterator &lhs);
        bool operator<(const Iterator &lhs);
        bool operator>(const Iterator &lhs);
        bool operator>=(const Iterator &lhs);

        Iterator &operator++();

        Iterator &operator--();
        T &operator*();
    };

    ArrayList();

    // the copy constructor
    ArrayList(const ArrayList &source);

    // the move constructor
    ArrayList(ArrayList &&source);

    // the destructor to free memory
    ~ArrayList();
    //uniwersalna referencja
    void push_front(T &&x); //wstawia element na początek
    T pop_front();          //usuwa element z początku i zwraca jego wartość lub wyjątek jeśli pusta

    void push_back(T &&x); //wstawia el na koniec
    T pop_back();          // usuwa el z końca i zwraca wartość lub wyjątek jeśli pusta

    Iterator find(const T &x); //wyszukuje el o wart x i zwraca jego poz

    Iterator erase(Iterator); //usuwa el i zwraca iter do kolejnego ele

    Iterator insert(Iterator it, T &&x); // wstawia x przed poz it i zwraca pozycję x

    int remove(const T &x); //Usuwa wystąpienia x i zwraca ich liczbę
    int size();             // zwraca liczę el w liście
    bool empty();           //zwraca true jeśli pusta
    Iterator begin();       //zwraca iterator na pierwszy el
    Iterator end();         //zwraca iterator na koniec
    T get(Iterator);
    Iterator &operator++();
    Iterator &operator--();

    T test(Iterator it);
    T test2(Iterator it, Iterator it2);

    Iterator next(Iterator it);
    Iterator prev(Iterator it);
};

template <class T>
ArrayList<T>::ArrayList()
{

    ptr = new T[100]{};
    cap = 100;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList &source)
{
    if (!source.isEmpty())
    {
        siz = source.siz;
        cap = source.cap;

        ptr = new T[siz];
        for (int i = 0; i < siz; i += 1)
        {
            ptr[i] = source.ptr[i];
        }
    }
}

template <class T>
ArrayList<T>::ArrayList(ArrayList &&source)
{
    // transfer owenership from the source
    siz = source.siz;
    cap = source.cap;
    ptr = source.ptr;

    // clear the cource
    source.ptr = nullptr;
    source.siz = 0;
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete[] ptr;
}

template <class T>
bool ArrayList<T>::empty()
{
    if (siz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void ArrayList<T>::push_back(T &&x)
{

    if (siz == cap)
    {
        throw runtime_error("siz==cap");
    }

    *(ptr + siz) = x;
    cout << "push_back" << *(ptr + siz) << endl;
    siz++;
}

template <class T>
T ArrayList<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("list is empty!");
    }

    cout << "size" << siz;
    cout << "pop_back" << *(ptr + --siz) << endl;
    return *(ptr + siz);
}

template <class T>
typename ArrayList<T>::Iterator ArrayList<T>::begin()
{

    Iterator a;
    a.sptr = ptr;

    return a;
}

template <class T>
typename ArrayList<T>::Iterator ArrayList<T>::end()
{
    Iterator a;
    a.sptr = ptr + siz - 1;
    return a;
}

template <class T>
T ArrayList<T>::get(Iterator it)
{
    end();
    return Iterator::sptr;
}

template <class T>
typename ArrayList<T>::Iterator ArrayList<T>::insert(Iterator it, T &&x)
{

    cout << "ah";
    int i = *ptr;
    int e = *end().sptr;
    int s = *begin().sptr;

    T *ii = it.sptr;
    T *ee = end().sptr;
    T *ss = begin().sptr;
    cout << "insert:" << *ee << endl;

    for (Iterator iii = end(); iii >= begin(); iii = prev(iii))
    {
        *(iii.sptr + 1) = *iii.sptr;
    }
    *it.sptr = x;
    siz++;
}

template <class T>
typename ArrayList<T>::Iterator &ArrayList<T>::operator++()
{
    Iterator::sptr++;
    return *this;
}

template <class T>
typename ArrayList<T>::Iterator &ArrayList<T>::Iterator::operator++()
{
    Iterator::sptr++;
    return *this;
}

template <class T>
typename ArrayList<T>::Iterator &ArrayList<T>::operator--()
{
    Iterator::sptr--;
    return *this;
}

template <class T>
T ArrayList<T>::test(ArrayList<T>::Iterator it)
{
    return *it.sptr;
}

template <class T>
typename ArrayList<T>::Iterator ArrayList<T>::next(Iterator it)
{
    Iterator temp = it;
    temp.sptr++;
    return temp;
}

template <class T>
typename ArrayList<T>::Iterator ArrayList<T>::prev(Iterator it)
{
    Iterator temp = it;
    temp.sptr--;
    return temp;
}

template <class T>
bool ArrayList<T>::Iterator::operator==(const Iterator &lhs)
{
    return lhs.sptr == this->sptr;
}

template <class T>
bool ArrayList<T>::Iterator::operator!=(const Iterator &lhs)
{
    return lhs.sptr != this->sptr;
}

template <class T>
T ArrayList<T>::test2(Iterator it, Iterator it2)
{
    if (it == it2)
    {
    }
    return 0;
}

template <class T>
T &ArrayList<T>::Iterator::operator*()
{

    return *sptr;
}
template <class T>
bool ArrayList<T>::Iterator::operator<=(const Iterator &lhs)
{
    if (this->sptr >= lhs.sptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArrayList<T>::Iterator::operator<(const Iterator &lhs)
{
    if (this->sptr < lhs.sptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArrayList<T>::Iterator::operator>(const Iterator &lhs)
{
    if (this->sptr > lhs.sptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArrayList<T>::Iterator::operator>=(const Iterator &lhs)
{
    if (this->sptr >= lhs.sptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

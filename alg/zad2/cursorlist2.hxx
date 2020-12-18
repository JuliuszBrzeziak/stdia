#ifndef LIST_H
#define LIST_H

#include <assert.h> // for assert
#include <memory>   // for std::unique_ptr

template <typename T>
class List
{
public:
    struct Node // All it's members are public by default.
    {
        Node(T aData, Node *aNext)
            : mData(aData), mNext(aNext)
        {
        }

        ~Node() {}

        T mData;
        Node *mNext;
    };

    List();
    ~List();

    void Append(T aData);
    void Prepend(T aData);

    typedef void (*Callback)(Node *aNode);

private:
    // No need to use smart pointer in low-level data structure.
    // It's more efficient for managing memory on our own.
    Node *mCursor;
    Node *mHead;
};

// nullptr is introduced in C++11.
template <typename T>
List<T>::List()
    : mCursor(nullptr), mHead(nullptr)
{
}

template <typename T>
List<T>::~List()
{
    for (mCursor = mHead; mCursor != nullptr;)
    {
        std::unique_ptr<Node> autoRelease(mCursor);
        // Update mCursor here instead of afterthought in for-loop,
        // in case mCursor is already released.
        mCursor = mCursor->mNext;
        // The memory chuck pointed by old mCursor will be destroyed
        // upon leaving the '}'.
    }
}

template <typename T>
void List<T>::Append(T aData)
{
    Node *n = new Node(aData, nullptr);
    if (!mHead)
    { // the list is empty.
        assert(!mCursor);
        mHead = n;
    }
    else
    {
        assert(mCursor);
        mCursor->mNext = n;
    }
    mCursor = n;
}

template <typename T>
void List<T>::Prepend(T aData)
{
    Node *n = new Node(aData, mHead);
    mHead = n;
    if (!mCursor)
    { // The list is empty before inserting value.
        mCursor = n;
    }
}

template <typename T>
void List<T>::Traverse(Callback aCallback)
{
    for (Node *cur = mHead; cur != nullptr; cur = cur->mNext)
    {
        aCallback(cur);
    }
}

#endif // LIST_H
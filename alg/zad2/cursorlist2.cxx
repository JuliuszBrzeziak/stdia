#include "cursorlist.hxx"
#include <iostream>

using namespace std;
// template <typename T>
// void Print(T aData, bool aBreakline)
// {
//     std::cout << aData << ((aBreakline) ? "->" : "\n");
// }

// void PrintInt(CursorList<int>::Node *aNode)
// {
//     Print(aNode->Data, aNode->next);
// }

// void PrintFloat(CursorList<float>::Node *aNode)
// {
//     Print(aNode->Data, aNode->next);
// }

int main()
{
    int dataInt[6] = {11, 22, 33, 44, 55, 66};
    float dataFloat[6] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};

    CursorList<int> li;
    // li.Prepend(11);
    li.push_front(0);
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);

    li.push_back(4);
    li.push_back(5);
    // li.push_front(7);
    li.Traverse();

    int p = li.pop_front();
    int b = li.pop_front();
    li.push_front(3);
    b = li.pop_front();

    li.Traverse();

    cout << "<<<" << p << "<<<"
         << "<<<" << b << "<<<" << endl;

    return 0;
}
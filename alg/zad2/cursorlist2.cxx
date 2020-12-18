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
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_front(44);

    li.push_back(66);
    li.push_back(88);
    li.push_front(7);

    li.Traverse();
    cout << li.arr[0].Data << li.arr[1].Data << li.arr[2].Data << li.arr[3].Data << endl;

    // CursorList<float> lf;
    // lf.Prepend(dataFloat[0]);
    // lf.Append(dataFloat[1]);
    // lf.Append(dataFloat[2]);
    // lf.Prepend(dataFloat[3]);
    // lf.Append(dataFloat[4]);
    // lf.Prepend(dataFloat[5]);
    // lf.Traverse(PrintFloat);

    return 0;
}
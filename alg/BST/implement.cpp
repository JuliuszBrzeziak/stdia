// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
    int key;
    BST *left, *right;

public:
    BST();

    BST(int);

    BST *Insert(BST *, int);

    int find(BST *, int);
};

BST ::BST()
    : key(0), left(NULL), right(NULL)
{
}

BST ::BST(int value)
{
    key = value;
    left = right = NULL;
}

BST *BST ::Insert(BST *root, int value)
{
    if (!root)
    {
        return new BST(value);
    }

    if (value > root->key)
    {
        root->right = Insert(root->right, value);
    }

    else
    {
        root->left = Insert(root->left, value);
    }

    return root;
}

int BST::find(BST *root, int i)
{
    if (root->key == i)
    {
        return root->key;
    }

    if (i > root->key)
    {
        return find(root->right, i);
    }

    else
    {
        return find(root->left, i);
    }
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);


    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 0);
    b.Insert(root, 60);
    b.Insert(root, 80);

    
    cout << b.find(root, 0);

    return 0;
}

// This code is contributed by pkthapa

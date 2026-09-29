#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

struct DSU
{
    Node* root;
};

Node* CreateNode(const int x)
{
    Node* p = new Node;
    p->data = x;

    p->parent = nullptr;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

DSU* Create()
{
    DSU* d = new DSU;

    d->root = nullptr;

    return d;
}

void DestroyNode(const Node* n)
{
    if (n->left != nullptr)
    {
        DestroyNode(n->left);
    }

    if (n->right != nullptr)
    {
        DestroyNode(n->right);
    }

    delete n;
}

void Delete(const DSU* r)
{
    if (r->root != nullptr)
    {
        DestroyNode(r->root);
    }

    delete r;
}

void egyesit(DSU d, const int x, const int y)
{

}

void keres(DSU d, const int x, const int y)
{
    if (t[x] == t[y]) cout << '1';
    else cout << '0';
}
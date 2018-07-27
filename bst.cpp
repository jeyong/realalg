#include <iostream>

struct Node {
    int val;
    Node *left, *right;
};

struct Tree {
    Node* root;
};

using namespace std;

int add(Tree& t, int val)
{
    auto item = new Node {val, nullptr, nullptr};
    
    if (t.root == nullptr)
    {
        t.root = item;
        return 1;
    }
    auto cur = t.root;
    while (cur != nullptr)
    {
            if (cur->val < val)
            {
                if (cur->right == nullptr)
                {
                    cur->right = item;
                    return 1;
                }
                cur = cur->right;
            }
            else
            {
                if (cur->left == nullptr)
                {
                    cur->left = item;
                    return 1;
                }
                cur = cur->left;
            }
    }
    return 0;
}

bool find(Tree& t, int val)
{
    auto cur = t.root;
    while(cur != nullptr)
    {
        if (cur->val == val)
        {
            return true;
        }
        if (cur->val < val)
        {
            cur = cur->right;
        }
        else {
            cur = cur->left;
        }
    }
    return false;
}

int main(int argc, const char * argv[])
{
    Tree t = {nullptr};
   
    add(t, 10);
    add(t, 5);
    add(t, 12);
    add(t, 4);
    add(t, 17);
    add(t, 3);
    add(t, 9);

    cout<<t.root->val<<endl;
    cout<<t.root->left->val<<endl;
    cout<<t.root->right->val<<endl;
    
    cout<<"found : "<<9<<" "<<find(t, 9)<<endl;
    cout<<"found : "<<3<<" "<< find(t, 3)<<endl;
    cout<<"found : "<<21<<" "<<find(t, 21)<<endl;

}

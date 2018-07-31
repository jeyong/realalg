//
//  main.cpp
//  cppstl
//
//  Created by jeyong on 27/07/2018.
//  Copyright © 2018 jeyong. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Node {
public:
    Node() { }
    Node(T v){val = v;}
    
    T val;
    
    bool operator== (const Node& obj) const
    {
        if (obj.val == this->val)
        {
            return true;
        }
        return false;
    }
    bool operator> (const Node& obj) const
    {
        if(obj.val < this->val)
        {
            return true;
        }
        return false;
    }
    
    bool operator< (const Node& obj) const
    {
        if(obj.val > this->val)
        {
            return true;
        }
        return false;
    }
    
    shared_ptr<Node<int>> left, right = nullptr;
};

template<typename T>
class BSTree {
private:
    size_t  size = 0;
public:
    BSTree() { size = 0;}
    
    shared_ptr<Node<T>> root;
    void add(shared_ptr<Node<T>> n)
    {
        if (n == nullptr)
        {
            return ;
        }
        
        auto cur = root;
        if (root == nullptr)
        {
            root = n;
            size++;
            return;
        }
        
        while(cur != nullptr)
        {
            if (*cur < *n)
            {
               if(cur->right == nullptr)
               {
                   cur->right = n;
                   size++;
                   return;
               }
                cur = cur->right;
            }
            else
            {
                if(cur->left == nullptr)
                {
                    cur->left = n;
                    size++;
                    return;
                }
                cur = cur->left;
            }
        }
    }
    
    size_t GetSize()
    {
        return size;
    }
    
    void BFTraversal()
    {
        queue<Node<T>> q;
        if (root == nullptr)
            return;
        q.push(*root);
        
        while(!q.empty())
        {
            auto n = q.front();
            q.pop();
            cout<<n.val<<endl;
            if (n.left != nullptr) { q.push(*n.left); }
            if (n.right != nullptr) { q.push(*n.right); }
        }
    }
};


int main()
{
    auto t = make_shared<BSTree<int>>();
    for (auto i=0; i<10; i++ )
    {
        t->add(make_shared<Node<int>>(10+i));
    }
    
    t->BFTraversal();
    return 0;
}

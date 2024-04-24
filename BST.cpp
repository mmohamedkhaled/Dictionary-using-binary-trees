#include <iostream>
#include <queue>
#include <fstream>
#include "BST.h"
using namespace std;

template <typename Key, typename Data>

BST<Key, Data>::BST()
{
    root = nullptr;
}

template <typename Key, typename Data>
BST<Key, Data>::~BST()
{
    delete_tree(root);
}

template <typename Key, typename Data>
void BST<Key, Data>::delete_tree(TreeNode<Key, Data> *r)
{
    if (!empty(r))
    {
        delete_tree(r->left);
        delete_tree(r->right);
        delete r;
    }
}
template <typename Key, typename Data>

bool BST<Key, Data>::empty(TreeNode<Key, Data> *&r) const
{
    return r == nullptr;
}

template <typename Key, typename Data>

bool BST<Key, Data>::insert_master(TreeNode<Key, Data> *&r, const Key &p_key, const Data &p_data)
{

    if (empty(r))
    {

        r = new TreeNode<Key, Data>(p_key, p_data);

        return true;
    }
    else if (r->key == p_key)
    {
        r->key = p_key;
        // cout << "you already exist\n";
        return false;
    }
    else if (r->key < p_key)
    {

        return insert_master(r->left, p_key, p_data);
    }
    else
    {
        return insert_master(r->right, p_key, p_data);
    }

    return false;
}

template <typename Key, typename Data>
bool BST<Key, Data>::insert(const Key &p_key, const Data &p_data)
{

    if (insert_master(root, p_key, p_data))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

template <typename Key, typename Data>
bool BST<Key, Data>::search_master(TreeNode<Key, Data> *&r, Key p_key)
{
    if (empty(r))
    {

        return false;
    }
    else if (r->key == p_key)
    {
        return true;
    }
    else if (r->key < p_key)
    {
        return search_master(r->left, p_key);
    }
    else
    {
        return search_master(r->right, p_key);
    }
}

template <typename Key, typename Data>

bool BST<Key, Data>::search(Key p_key)
{
    if (search_master(root, p_key))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Key, typename Data>

int BST<Key, Data>::traverse_master(TreeNode<Key, Data> *&r, int determine, int &count)
{

    if (r != nullptr)
    {
        if (determine == 1)
        {
            count = traverse_master(r->left, determine, count);
            count++;
            count = traverse_master(r->right, determine, count);
        }
        else if (determine == 2)
        {
            traverse_master(r->left, determine, count);
            cout << r->key << endl;
            traverse_master(r->right, determine, count);
        }
    }
    return count;
}

template <typename Key, typename Data>

int BST<Key, Data>::traverse(int determine)
{
    int count = 0;
    count = traverse_master(root, determine, count);
    return count;
}

// template <typename Key, typename Data>
// bool BST<Key, Data>::retrieve_master(TreeNode<Key, Data> *&r, Key p_key, Data &p_data)
// {

//     if (search_master(r, p_key))
//     {
//         cout << "Retrieving data part of " << p_key;
//         cout << "= " << r->data << endl;
//         return true;
//     }
//     return false;
// }
template <typename Key, typename Data>
bool BST<Key, Data>::retrieve(Key p_key, Data &p_data)
{
    if (retrieve_master(root, p_key, p_data))
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename Key, typename Data>
bool BST<Key, Data>::retrieve_master(TreeNode<Key, Data> *&r, Key p_key, Data &p_data)
{
    if (empty(r))
    {
        return false;
    }
    if (p_key > r->key)
    {
        return retrieve_master(r->left, p_key, p_data);
    }
    else if (p_key < r->key)
    {
        return retrieve_master(r->right, p_key, p_data);
    }
    else
    {
        cout << "Retrieving data part of " << p_key;
        cout << " = " << r->data << endl;
        p_data = r->data;
        return true;
    }
}
template <typename Key, typename Data>

void BST<Key, Data>::preorder_master(TreeNode<Key, Data> *&r)
{
    if (!empty(r))
    {
        cout << "the key is " << r->key << " the data is " << r->data << endl;
        preorder_master(r->left);
        preorder_master(r->right);
    }
}
template <typename Key, typename Data>
void BST<Key, Data>::preorder()
{
    preorder_master(root);
}

template <typename Key, typename Data>
void BST<Key, Data>::levelorder_master(TreeNode<Key, Data> *&r)
{
    if (!empty(r))
    {
        std::queue<TreeNode<Key, Data> *> q;
        q.push(r);
        while (!q.empty())
        {
            TreeNode<Key, Data> *current = q.front();
            q.pop();
            cout << current->key << " " << current->data << endl;
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
}
template <typename Key, typename Data>
void BST<Key, Data>::levelorder()
{
    levelorder_master(root);
}
template <typename Key, typename Data>
void BST<Key, Data>::levelorder_master_to_screen(TreeNode<Key, Data> *&r, ofstream &outStream)
{
    if (r != nullptr)
    {
        std::queue<TreeNode<Key, Data> *> q;
        q.push(r);
        while (!q.empty())
        {
            TreeNode<Key, Data> *current = q.front();
            q.pop();
            outStream << current->key <<  endl;
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
}

template <typename Key, typename Data>
void BST<Key, Data>::levelorder_to_screen(ofstream &outStream)
{

    levelorder_master_to_screen(root, outStream);
}

template <typename Key, typename Data>
void BST<Key, Data>::remove_master(TreeNode<Key, Data> *&r, Key p_key)
{
    if (empty(r))
    {
        return;
    }

    if (r->key < p_key)
    {
        remove_master(r->right, p_key);
    }
    else if (r->key > p_key)
    {
        remove_master(r->left, p_key);
    }
    else
    {

        if (r->left == nullptr && r->right == nullptr)
        {
            delete r;
            r = nullptr;
        }
        else if (r->left)
        {
            TreeNode<Key, Data> *temp = r;
            r = r->left;
            delete temp;
        }
        else
        {
            TreeNode<Key, Data> *temp = r;
            r = r->right;
            delete temp;
        }
    }
}

template <typename Key, typename Data>
void BST<Key, Data>::remove(Key p_key)
{
    remove_master(root, p_key);
}

template <typename Key, typename Data>
void BST<Key, Data>::traverse_master_to_screen(TreeNode<Key, Data> *&r, ofstream &outStream)
{
    if (r != nullptr)
    {
        traverse_master_to_screen(r->left, outStream);
        outStream << r->key << endl;
        traverse_master_to_screen(r->right, outStream);
    }
}

template <typename Key, typename Data>
void BST<Key, Data>::traverse_to_screen(ofstream &outStream)
{

    traverse_master_to_screen(root, outStream);
}

template <typename Key, typename Data>
typename BST<Key, Data>::TreeNode<Key, Data> *BST<Key, Data>::getroot()
{
    return root;
}
// void BST<Key, Data>::reverse_traverse_master_to_screen(TreeNode<Key, Data> *&r, ofstream &outStream) {
//     if (!empty(r)) {
//         reverse_traverse_master_to_screen(r->right, outStream); // Traverse right subtree first
//         outStream << r->key << endl; // Write current node to file
//         reverse_traverse_master_to_screen(r->left, outStream); // Traverse left subtree
//     }
// }

// template <typename Key, typename Data>
// void BST<Key, Data>::reverse_traverse_to_screen(ofstream &outStream) {
//     reverse_traverse_master_to_screen(root, outStream);
// }

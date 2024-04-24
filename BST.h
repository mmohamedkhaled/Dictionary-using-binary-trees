#ifndef BST_H
#define BST_H
#include <string>

template <typename Key, typename Data>
class BST
{
public:
    template <typename K, typename D>

    class TreeNode
    {
    public:
        K key;
        D data;
        TreeNode<K, D> *left;
        TreeNode<K, D> *right;
        TreeNode(K p_key, D p_data) : key(p_key), data(p_data), left(nullptr), right(nullptr) {}
    };
    BST();
    ~BST();
    void delete_tree(TreeNode<Key, Data> *r);
    bool insert(const Key &p_key, const Data &p_data);
    bool empty(TreeNode<Key, Data> *&root) const;
    bool search(Key key);
    bool retrieve(Key p_key, Data &p_data);
    void remove(Key p_key);
    int traverse(int determine);
    void preorder();
    void levelorder();
    void traverse_to_screen(std::ofstream &outStream);
    void levelorder_to_screen(std::ofstream &outStream);
    
    TreeNode<Key, Data> *getroot();
    // void reverse_traverse_to_screen(ofstream &outStream);
private:
    TreeNode<Key, Data> *root;
    bool insert_master(TreeNode<Key, Data> *&r, const Key &p_key, const Data &p_data);
    bool search_master(TreeNode<Key, Data> *&r, Key p_key);
    bool retrieve_master(TreeNode<Key, Data> *&r, Key p_key, Data &p_data);
    int traverse_master(TreeNode<Key, Data> *&r, int determine, int &count);
    void levelorder_master(TreeNode<Key, Data> *&r);
    void preorder_master(TreeNode<Key, Data> *&r);
    void remove_master(TreeNode<Key, Data> *&r, Key p_key);
    void traverse_master_to_screen(TreeNode<Key, Data> *&r, std::ofstream &outStream);
    void levelorder_master_to_screen(TreeNode<Key, Data> *&r,std:: ofstream &outStream);
    // void reverse_traverse_master_to_screen(TreeNode<Key, Data> *&r, std:: ofstream &outStream);

};

#include "BST.cpp"
#endif // BST_H

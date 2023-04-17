#include <bits/stdc++.h>
#include "binary_tree_node.h"
using namespace std;

class bst
{
    binary_tree_node<int> *root;

public:
    bst()
    {
        root = NULL;
    }

    ~bst()
    {
        delete root;
    }

private:
    binary_tree_node<int> *insert_helper(int data, binary_tree_node<int> *root)
    {
        if (root == NULL)
        {
            auto node = new binary_tree_node<int>(data);
            return node;
        }

        if (data > root->data)
        {
            root->right = insert_helper(data, root->right);
        }
        else
        {
            root->left = insert_helper(data, root->left);
        }
        return root;
    }

    bool binary_search_helper(binary_tree_node<int> *root, int data)
    {
        if (root == NULL)
            return false;

        int root_data = root->data;
        if (root_data == data)
        {
            return true;
        }
        if (root_data > data)
        {
            return binary_search_helper(root->left, data);
        }
        return binary_search_helper(root->right, data);
    }

    binary_tree_node<int> *delete_node(binary_tree_node<int> *root, int data)
    {
        if (root == NULL)
            return NULL;

        int root_data = root->data;
        if (root_data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if (root->left == NULL)
            {
                auto new_root = root->right;
                root->right = NULL;
                delete root;
                return new_root;
            }
            if (root->right == NULL)
            {
                auto new_root = root->left;
                root->left = NULL;
                delete root;
                return new_root;
            }
            // Replace with inorder successor(smallest element to the right of the node)
            auto temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        else if (root_data > data)
        {
            root->left = delete_node(root->left, data);
        }
        else
        {
            root->right = delete_node(root->right, data);
        }
        return root;
    }

public:
    void insert(int data)
    {
        this->root = insert_helper(data, root);
        return;
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }
        queue<binary_tree_node<int> *> pending_nodes;
        pending_nodes.push(root);
        pending_nodes.push(NULL);
        while (pending_nodes.size())
        {
            auto current = pending_nodes.front();
            pending_nodes.pop();
            if (current == NULL)
            {
                cout << endl;
                if (pending_nodes.size() == 0)
                {
                    break;
                }
                pending_nodes.push(NULL);
                continue;
            }
            cout << current->data << ' ';
            if (current->left != NULL)
                pending_nodes.push(current->left);
            if (current->right != NULL)
                pending_nodes.push(current->right);
        }
        return;
    }

    bool binary_search(int data)
    {
        return binary_search_helper(root, data);
    }

    void delete_node(int data)
    {
        this->root = delete_node(this->root, data);
        return;
    }
};
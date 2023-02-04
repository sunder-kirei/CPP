#include <bits/stdc++.h>
#include "treeNode.h"
using namespace std;

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ':';
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ',';
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    return;
}

TreeNode<int> *takeInput()
{
    int data;
    cout << "Enter root\n";
    cin >> data;
    TreeNode<int> *newRoot = new TreeNode<int>(data);
    int size;
    cout << "Enter the number of children\n";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        newRoot->children.push_back(takeInput());
    }
    return newRoot;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size())
    {
        root = q.front();
        q.pop();
        cout << root->data << ':';
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ',';
            q.push(root->children[i]);
        }
        cout << endl;
    }
    return;
}

TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> q;
    int data;
    cout << "Enter data\n";
    cin >> data;
    TreeNode<int> *newNode = new TreeNode<int>(data);
    TreeNode<int> *newRoot = newNode;
    q.push(newNode);
    while (q.size())
    {
        TreeNode<int> *root = q.front();
        q.pop();
        cout << "Enter the number of children of " << root->data << endl;
        int size;
        cin >> size;
        cout << "Enter children\n";
        for (int i = 0; i < size; i++)
        {
            cin >> data;
            newNode = new TreeNode<int>(data);
            q.push(newNode);
            root->children.push_back(newNode);
        }
    }
    return newRoot;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
}
#include <bits/stdc++.h>
#include "binary_tree_node.h"
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    node()
    {
        this->data = 0;
        next = NULL;
    }
};

binary_tree_node<int> *take_input()
{
    queue<binary_tree_node<int> *> pending_nodes;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    auto root = new binary_tree_node<int>(data);
    pending_nodes.push(root);
    while (pending_nodes.size())
    {
        auto current = pending_nodes.front();
        pending_nodes.pop();

        cin >> data;
        if (data != -1)
        {
            auto new_node = new binary_tree_node<int>(data);
            current->left = new_node;
            pending_nodes.push(new_node);
        }
        cin >> data;
        if (data != -1)
        {
            auto new_node = new binary_tree_node<int>(data);
            current->right = new_node;
            pending_nodes.push(new_node);
        }
    }

    return root;
}

void print_tree(binary_tree_node<int> *root)
{
    queue<binary_tree_node<int> *> pending_nodes;
    pending_nodes.push(root);

    while (pending_nodes.size())
    {
        auto current_node = pending_nodes.front();
        pending_nodes.pop();
        if (current_node == NULL)
            continue;
        cout << current_node->data << ':';
        if (current_node->left != NULL)
        {
            cout << current_node->left->data << ',';
        }
        if (current_node->right != NULL)
        {
            cout << current_node->right->data << ',';
        }
        cout << endl;
        pending_nodes.push(current_node->left);
        pending_nodes.push(current_node->right);
    }
    return;
}

bool search_in_bst(binary_tree_node<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (root->data > x)
        return search_in_bst(root->left, x);

    return search_in_bst(root->right, x);
}

void print_in_range(binary_tree_node<int> *root, int a, int b)
{
    if (root == NULL)
    {
        return;
    }
    int root_data = root->data;
    if (root_data > a)
    {
        print_in_range(root->left, a, b);
    }

    if (root->data >= a && root->data <= b)
    {
        cout << root->data << endl;
    }

    if (root_data < b)
    {
        print_in_range(root->right, a, b);
    }
    return;
}

//(max, min, is_bst)

pair<pair<int, int>, bool> is_bst_helper(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return make_pair(make_pair(INT_MIN, INT_MAX), true);
    }

    auto left = is_bst_helper(root->left);
    auto right = is_bst_helper(root->right);

    int root_data = root->data;
    int max_data = max(root_data, max(left.first.first, right.first.first));
    int min_data = min(root_data, min(left.first.second, right.first.second));
    bool is_bst = left.second && right.second && (root_data > left.first.first) && (root_data < right.first.second);

    return make_pair(make_pair(max_data, min_data), is_bst);
}

bool is_bst(binary_tree_node<int> *root)
{
    return is_bst_helper(root).second;
}

binary_tree_node<int> *construct_bst(int arr[], int si, int ei)
{
    if (si > ei)
        return NULL;

    int mi = si + ((ei - si) / 2);
    auto left = construct_bst(arr, si, mi - 1);
    auto right = construct_bst(arr, mi + 1, ei);

    auto root = new binary_tree_node<int>(arr[mi]);
    root->left = left;
    root->right = right;

    return root;
}

pair<node *, node *> bst_to_ll(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        node *new_head = NULL;
        node *new_tail = NULL;
        return make_pair(new_head, new_tail);
    }
    auto left = bst_to_ll(root->left);
    auto right = bst_to_ll(root->right);

    node *new_node = new node(root->data);
    if (left.first == NULL)
    {
        node *new_head = new_node;
        new_node->next = right.first;
        if (right.first == NULL)
        {
            right.second = new_node;
        }
        return make_pair(new_head, right.second);
    }
    left.second->next = new_node;
    new_node->next = right.first;
    return make_pair(left.first, right.second);
}

void print_ll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
    return;
}

vector<int> *path_in_bst(binary_tree_node<int> *root, int n)
{
    if (root == NULL)
    {
        return NULL;
    }

    int root_data = root->data;
    vector<int> *ans = new vector<int>;
    if (root_data == n)
    {
        ans->push_back(root_data);
        return ans;
    }
    if (root_data > n)
    {
        ans = path_in_bst(root->left, n);
    }
    else
    {
        ans - path_in_bst(root->right, n);
    }
    if (ans != NULL)
    {
        ans->push_back(root_data);
    }
    return ans;
}

// Assignment

void duplicate_nodes(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;

    auto new_left = new binary_tree_node<int>(root->data);
    new_left->left = root->left;
    root->left = new_left;
    duplicate_nodes(root->left->left);
    duplicate_nodes(root->right);
    return;
}

void pair_sum(binary_tree_node<int> *root, int sum)
{
    vector<int> tree_arr;
    queue<binary_tree_node<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size())
    {
        auto current_node = pending_nodes.front();
        pending_nodes.pop();
        tree_arr.push_back(current_node->data);
        if (current_node->left != NULL)
            pending_nodes.push(current_node->left);
        if (current_node->right != NULL)
            pending_nodes.push(current_node->right);
    }
    sort(tree_arr.begin(), tree_arr.end());
    int i = 0, j = tree_arr.size();
    while (i < j)
    {
        int current_sum = tree_arr[i] + tree_arr[j];
        if (current_sum == sum)
        {
            cout << tree_arr[i] << ' ' << tree_arr[j] << endl;
            i++;
            continue;
        }
        if (current_sum < sum)
        {
            i++;
            continue;
        }
        if (current_sum > sum)
        {
            j--;
            continue;
        }
    }
    return;
}

int lca_better(binary_tree_node<int> *root, int a, int b)
{
    if (root == NULL)
        return -1;

    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    auto left = lca_better(root->left, a, b);
    auto right = lca_better(root->right, a, b);
    if (left != -1 && right != -1)
        return root->data;
    if (left != -1)
        return left;
    if (right != -1)
        return right;

    return -1;
}

int lca_bst(binary_tree_node<int> *root, int a, int b)
{
    if (root == NULL)
        return -1;

    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    int left = -1, right = -1;
    if (root->data > min(a, b))
        left = lca_bst(root->left, a, b);

    if (root->data < max(a, b))
        right = lca_bst(root->right, a, b);

    if (left != -1 && right != -1)
        return root->data;

    if (left != -1)
        return left;

    if (right != -1)
        return right;

    return -1;
}

//(max,min),height
pair<pair<int, int>, int> largest_bst_helper(binary_tree_node<int> *root)
{
    if (root == NULL)
        return make_pair(make_pair(INT_MIN, INT_MAX), 0);

    auto left = largest_bst_helper(root->left);
    auto right = largest_bst_helper(root->right);

    int max_height = max(left.second, right.second);

    if (right.first.first == INT_MIN && left.first.first == INT_MIN)
    {
        return make_pair(make_pair(root->data, root->data), 1);
    }

    if (root->data > left.first.first && root->data < right.first.second)
    {
        int max_data = right.first.first;
        int min_data = left.first.second;
        if (left.first.first == INT_MIN)
        {
            min_data = min(root->data, right.first.second);
        }
        if (right.first.first == INT_MIN)
        {
            max_data = max(root->data, left.first.first);
        }
        max_height += 1;
        return make_pair(make_pair(max_data, min_data), max_height);
    }

    return make_pair(make_pair(INT_MAX, INT_MIN), max_height);
}

int largest_bst(binary_tree_node<int> *root)
{
    return largest_bst_helper(root).second;
}

int replace_with_sum(binary_tree_node<int> *root, int bias)
{
    if (root == NULL)
    {
        return bias;
    }

    int right = replace_with_sum(root->right, bias);
    root->data += right;
    replace_with_sum(root->left, root->data);
    return root->data;
}

void replace_with_sum(binary_tree_node<int> *root)
{
    replace_with_sum(root, 0);
    return;
}

void root_to_leaf(binary_tree_node<int> *root, int sum, vector<int> ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    sum -= root->data;
    if (root->left == NULL && root->right == NULL && sum == 0)
    {
        for (int x : ans)
            cout << x << ' ';
        cout << endl;
        return;
    }
    root_to_leaf(root->left, sum, ans);
    root_to_leaf(root->right, sum, ans);
}

void root_to_leaf(binary_tree_node<int> *root, int sum)
{
    vector<int> ans;
    return root_to_leaf(root, sum, ans);
}

int main()
{
    auto root = take_input();

    return 0;
}
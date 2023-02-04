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
};

binary_tree_node<int> *take_input()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    queue<binary_tree_node<int> *> pending_nodes;
    binary_tree_node<int> *root = new binary_tree_node<int>(data);
    pending_nodes.push(root);

    while (pending_nodes.size())
    {
        auto current_node = pending_nodes.front();
        pending_nodes.pop();

        cin >> data;
        if (data != -1)
        {
            binary_tree_node<int> *left = new binary_tree_node<int>(data);
            current_node->left = left;
            pending_nodes.push(left);
        }
        cin >> data;
        if (data != -1)
        {
            binary_tree_node<int> *right = new binary_tree_node<int>(data);
            current_node->right = right;
            pending_nodes.push(right);
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

int count_nodes(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

bool is_node_present(binary_tree_node<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    return (is_node_present(root->left, x) || is_node_present(root->right, x));
}

int tree_height(binary_tree_node<int> *root)
{
    if (root == NULL)
        return 0;

    return (1 + max(tree_height(root->left), tree_height(root->right)));
}

void mirror_binary_tree(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;
    auto temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirror_binary_tree(root->left);
    mirror_binary_tree(root->right);
    return;
}

void in_order(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    cout << root->data << endl;
    in_order(root->right);
    return;
}

void pre_order(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;
    pre_order(root->left);
    pre_order(root->right);
    return;
}

void post_order(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << endl;
    return;
}

binary_tree_node<int> *construct_from_pre_in(int pre_order[], int in_order[], int pre_start, int pre_end, int in_start, int in_end)
{
    if (pre_start > pre_end || in_start > in_end)
    {
        return NULL;
    }

    int root_data = pre_order[pre_start];

    for (int i = in_start; i <= in_end; i++)
    {
        if (in_order[i] == root_data)
        {
            root_data = i;
            break;
        }
    }

    int left_in_start = in_start;
    int left_in_end = root_data - 1;
    int right_in_start = root_data + 1;
    int right_in_end = in_end;

    int left_pre_start = pre_start + 1;
    int left_pre_end = left_in_end - left_in_start + left_pre_start;
    int right_pre_start = left_pre_end + 1;
    int right_pre_end = pre_end;

    binary_tree_node<int> *left = construct_from_pre_in(pre_order, in_order, left_pre_start, left_pre_end, left_in_start, left_in_end);
    binary_tree_node<int> *right = construct_from_pre_in(pre_order, in_order, right_pre_start, right_pre_end, right_in_start, right_in_end);

    binary_tree_node<int> *root = new binary_tree_node<int>(pre_order[pre_start]);
    root->left = left;
    root->right = right;
    return root;
}

binary_tree_node<int> *construct_from_post_in(int post_order[], int in_order[], int post_start, int post_end, int in_start, int in_end)
{
    if (post_start > post_end || in_start > in_end)
    {
        return NULL;
    }

    int root_data = post_order[post_end];
    int root_index = -1;

    for (int i = in_start; i <= in_end; i++)
    {
        if (in_order[i] == root_data)
        {
            root_index = i;
            break;
        }
    }

    int left_in_start = in_start;
    int left_in_end = root_index - 1;
    int right_in_start = root_index + 1;
    int right_in_end = in_end;

    int left_post_start = post_start;
    int left_post_end = left_in_end - left_in_start + left_post_start;
    int right_post_start = left_post_end + 1;
    int right_post_end = post_end - 1;

    binary_tree_node<int> *root = new binary_tree_node<int>(root_data);
    root->left = construct_from_post_in(post_order, in_order, left_post_start, left_post_end, left_in_start, left_in_end);
    root->right = construct_from_post_in(post_order, in_order, right_post_start, right_post_end, right_in_start, right_in_end);

    return root;
}

pair<int, int> tree_min_max(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return make_pair(INT_MAX, INT_MIN);
    }

    auto left = tree_min_max(root->left);
    auto right = tree_min_max(root->right);

    return make_pair(min(root->data, min(left.first, right.first)), max(root->data, max(left.second, right.second)));
}

int tree_sum(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = tree_sum(root->left);
    int right = tree_sum(root->right);

    return root->data + left + right;
}

pair<int, bool> is_balanced_helper(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return make_pair(0, true);
    }

    auto left = is_balanced_helper(root->left);
    auto right = is_balanced_helper(root->right);

    int depth = 1 + max(left.first, right.first);
    bool is_balanced = ((abs(left.first - right.first) <= 1) && left.second && right.second);

    return make_pair(depth, is_balanced);
}

bool is_balanced(binary_tree_node<int> *root)
{
    auto ans = is_balanced_helper(root);
    return ans.second;
}

binary_tree_node<int> *remove_leaf_nodes(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }

    root->left = remove_leaf_nodes(root->left);
    root->right = remove_leaf_nodes(root->right);

    return root;
}

void level_order(binary_tree_node<int> *root)
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

vector<node *> linked_list_from_tree(binary_tree_node<int> *root)
{
    vector<node *> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<binary_tree_node<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);

    node *head = new node(-1);
    node *current_head = head;
    while (pending_nodes.size())
    {
        auto current = pending_nodes.front();
        pending_nodes.pop();
        if (current == NULL)
        {
            ans.push_back(head->next);
            head = new node(-1);
            current_head = head;
            if (pending_nodes.size() == 0)
            {
                break;
            }
            pending_nodes.push(NULL);
            continue;
        }
        node *new_node = new node(current->data);
        current_head->next = new_node;
        current_head = current_head->next;

        if (current->left != NULL)
            pending_nodes.push(current->left);
        if (current->right != NULL)
            pending_nodes.push(current->right);
    }

    return ans;
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

void zig_zag_print(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<binary_tree_node<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    int level_count = 2;
    while (pending_nodes.size())
    {
        auto current = pending_nodes.front();
        pending_nodes.pop();
        if (current == NULL)
        {
            cout << endl;
            level_count++;
            if (pending_nodes.size() == 0)
            {
                break;
            }
            pending_nodes.push(NULL);
            continue;
        }
        cout << current->data << ' ';
        if (level_count % 2 != 0)
        {
            if (current->left != NULL)
                pending_nodes.push(current->left);
            if (current->right != NULL)
                pending_nodes.push(current->right);
        }
        else
        {
            if (current->right != NULL)
                pending_nodes.push(current->right);
            if (current->left != NULL)
                pending_nodes.push(current->left);
        }
    }
    return;
}

void nodes_without_siblings(binary_tree_node<int> *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL && root->right == NULL)
    {
        cout << root->left->data << endl;
    }
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << endl;
    }
    nodes_without_siblings(root->left);
    nodes_without_siblings(root->right);

    return;
}

int main()
{
    auto root = take_input();
    nodes_without_siblings(root);
    return 0;
}
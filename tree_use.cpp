#include <bits/stdc++.h>
using namespace std;

class tree_node
{
public:
    int data;
    vector<tree_node *> children;

    tree_node(int data)
    {
        this->data = data;
    }
};

bool contains_x(tree_node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    for (auto child : root->children)
    {
        if (contains_x(child, x))
        {
            return true;
        }
    }
    return false;
}

tree_node *take_input()
{
    int data;
    cin >> data;
    tree_node *root = new tree_node(data);
    queue<tree_node *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size())
    {
        tree_node *current_node = pending_nodes.front();
        pending_nodes.pop();
        int size;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cin >> data;
            tree_node *new_node = new tree_node(data);
            current_node->children.push_back(new_node);
            pending_nodes.push(new_node);
        }
    }
    return root;
}

void print_tree(tree_node *root)
{
    if (root == NULL)
        return;
    queue<tree_node *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size())
    {
        tree_node *current_node = pending_nodes.front();
        pending_nodes.pop();
        cout << current_node->data << ':';
        int size = current_node->children.size();
        for (int i = 0; i < size; i++)
        {
            pending_nodes.push(current_node->children[i]);
            cout << current_node->children[i]->data << ',';
        }
        cout << endl;
    }
    return;
}

int count_nodes(tree_node *root, int x)
{
    if (root == NULL)
        return 0;
    int size = root->children.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += count_nodes(root->children[i], x);
    }
    if (root->data > x)
    {
        sum += 1;
    }
    return sum;
}

pair<int, int> max_child_sum(tree_node *root)
{
    if (root == NULL)
    {
        return make_pair(0, -1);
    }
    int max_sum = root->data;
    int size = root->children.size();
    for (int i = 0; i < size; i++)
    {
        max_sum += root->children[i]->data;
    }
    int max_node = root->data;
    for (int i = 0; i < size; i++)
    {
        auto child_sum = max_child_sum(root->children[i]);
        if (child_sum.second > max_sum)
        {
            max_sum = child_sum.second;
            max_node = child_sum.first;
        }
    }
    return make_pair(max_node, max_sum);
}

bool is_identical(tree_node *tree_one, tree_node *tree_two)
{
    queue<tree_node *> pending_nodes_one, pending_nodes_two;
    pending_nodes_one.push(tree_one);
    pending_nodes_two.push(tree_two);
    while (pending_nodes_one.size() && pending_nodes_two.size())
    {
        auto current_node_one = pending_nodes_one.front();
        auto current_node_two = pending_nodes_two.front();

        pending_nodes_one.pop();
        pending_nodes_two.pop();

        int size_one = current_node_one->children.size();
        int size_two = current_node_two->children.size();

        if (size_one != size_two)
        {
            return false;
        }

        for (int i = 0; i < size_one; i++)
        {
            if (current_node_one->children[i]->data == current_node_two->children[i]->data)
            {
                pending_nodes_one.push(current_node_one->children[i]);
                pending_nodes_two.push(current_node_two->children[i]);
            }
            else
            {
                return false;
            }
        }
    }
    if (pending_nodes_one.size() != pending_nodes_two.size())
    {
        return false;
    }

    return true;
}

int just_greater(tree_node *root, int n)
{
    if (root == NULL)
    {
        return -1;
    }
    int greater = INT_MAX;
    int size = root->children.size();

    for (int i = 0; i < size; i++)
    {
        int ans = just_greater(root->children[i], n);
        if (ans < greater)
        {
            greater = ans;
        }
    }

    if (root->data > n)
    {
        greater = min(greater, root->data);
    }
    return greater;
}

pair<int, int> second_largest(tree_node *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    int size = root->children.size();
    int first_max = root->data, second_max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        auto ans = second_largest(root->children[i]);
        if (ans.first > first_max)
        {
            int prev_max = first_max;
            first_max = ans.first;
            second_max = max(prev_max, ans.second);
        }
        else
        {
            second_max = max(ans.first, second_max);
        }
    }

    return make_pair(first_max, second_max);
}

void replace_with_depth(tree_node *root, int current_depth)
{
    if (root == NULL)
    {
        return;
    }
    int size = root->children.size();
    for (int i = 0; i < size; i++)
    {
        replace_with_depth(root->children[i], current_depth + 1);
    }
    root->data = current_depth;
    return;
}

int main()
{
    auto root = take_input();
    replace_with_depth(root, 0);
    print_tree(root);
    return 0;
}
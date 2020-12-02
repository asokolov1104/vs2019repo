//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//
vector<vector<int>> levelOrderv1(TreeNode* root) {
    vector<vector<int>> result;
    deque<pair<int, TreeNode*>> worklist;
    if (root != nullptr)
        worklist.push_back(pair<int, TreeNode*>{ 0, root });

    result.push_back(vector<int>());
    while (!worklist.empty())
    {
        pair<int, TreeNode*> front = worklist.front();
        if (front.second->left != nullptr)
            worklist.push_back(pair<int, TreeNode*>{ front.first + 1 , front.second->left});
        if (front.second->right != nullptr)
            worklist.push_back(pair<int, TreeNode*>{ front.first + 1, front.second->right});
        
        if (front.first == (int)result.size())
            result.push_back(vector<int>());
        result[front.first].push_back(front.second->val);
        worklist.pop_front();
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    typedef pair<int, TreeNode*> workelem;
    deque<workelem> worklist;
    if (root != nullptr)
        worklist.push_back(workelem{ 0, root });

    result.push_back(vector<int>());
    while (!worklist.empty())
    {
        pair<int, TreeNode*> front = worklist.front();
        if (front.second->left != nullptr)
            worklist.push_back(workelem{ front.first + 1, front.second->left});
        if (front.second->right != nullptr)
            worklist.push_back(workelem{ front.first + 1, front.second->right});

        if (front.first == (int)result.size())
            result.push_back(vector<int>());
        result[front.first].push_back(front.second->val);
        worklist.pop_front();
    }
    return result;
}

vector<vector<int>> levelOrderBarrier(TreeNode* root) {
    vector<vector<int>> result;
    TreeNode* barrier = new TreeNode(-1);
    deque<TreeNode*> worklist;
    int level = 0;
    if (root != nullptr)
    {
        worklist.push_back(root);
        worklist.push_back(barrier);
        result.push_back(vector<int>());
    }

    while (!worklist.empty())
    {
        TreeNode *front = worklist.front();
        if (front->val == -1)
        {
            if (worklist.size() > 1) {
                worklist.push_back(barrier);
                result.push_back(vector<int>());
                level++;
            }
        }
        else
        {

            if (front->left != nullptr)
                worklist.push_back(front->left);
            if (front->right != nullptr)
                worklist.push_back(front->right);

            result[level].push_back(front->val);
        }
        worklist.pop_front();
    }
    delete barrier;
    return result;
}

//
auto main() -> int {

    TreeNode* root = nullptr;
    root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(42);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrderBarrier(root);
    //vector<vector<int>> res = levelOrder(root);

    for (auto& vec : res) {
        for (auto& el : vec)
            cout << el << " ";
        cout << endl;
    }
    
    return 0;
}
//

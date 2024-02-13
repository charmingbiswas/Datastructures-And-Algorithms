#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

std::vector<int> topViewOfBinaryTree(TreeNode* root) {
    std::vector<int> answer;
    if(root == nullptr) return answer;
    // map containing horizontal distance and the value stored for that horizontal distance
    std::map<int, int> mp;
    // node for a particular horizontal distance
    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 0));

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        auto node = curr.first;
        int horizontalDistance = curr.second;

        if(mp.find(horizontalDistance) == mp.end())
            mp[horizontalDistance] = node->data;
        
        if(node->left) q.push(std::make_pair(node->left, horizontalDistance - 1));
        if(node->right) q.push(std::make_pair(node->right, horizontalDistance + 1));
    }

    for(auto i : mp) {
        answer.push_back(i.second);
        std::cout << i.second;
    }
    std::cout << std::endl;

    return answer;
}
    

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    topViewOfBinaryTree(root);
    return 0;
};
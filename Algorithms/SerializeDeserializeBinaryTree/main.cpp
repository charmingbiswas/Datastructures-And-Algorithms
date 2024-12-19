#include <iostream>
#include <string>
#include <queue>
#include <sstream>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {};
};


std::string serialize(TreeNode* root) {
    std::queue<TreeNode*> mq;
    mq.push(root);
    std::string answer = "";
    while(!mq.empty()) {
        auto current = mq.front();
        mq.pop();
        if(current) {
            answer += std::to_string(current->val) + ",";
            mq.push(current->left);
            mq.push(current->right);
        } else answer += "#,";
    }
    return answer;
}

TreeNode* deserialize(std::string s) {
    std::stringstream stream(s);
    std::string curr;
    TreeNode* root = nullptr;
    std::getline(stream, curr, ',');
    root = new TreeNode(std::stoi(curr));
    std::queue<TreeNode*> mq;
    mq.push(root);
    while(!mq.empty()) {
        auto node = mq.front();
        mq.pop();

        // add left child
        if(std::getline(stream, curr, ',')) {
            if(curr != "#") {
                auto leftNode = new TreeNode(std::stoi(curr));
                node->left = leftNode;
                mq.push(leftNode);
            }
        }

        // add right child
        if(std::getline(stream, curr, ',')) {
            if(curr != "#") {
                auto rightNode = new TreeNode(std::stoi(curr));
                node->right = rightNode;
                mq.push(rightNode);
            }
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    std::queue<TreeNode*> mq;
    mq.push(root);
    while(!mq.empty()) {
        auto current = mq.front();
        mq.pop();
        if(current == nullptr) {
            std::cout << "null";
        } else {
            std::cout << current->val;
            mq.push(current->left);
            mq.push(current->right);
        }
    }
    std::cout << std::endl;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    std::string s = serialize(root);
    std::cout << s << std::endl;
    TreeNode* r = deserialize(s);
    printTree(r);
    return 0;
}

/*
    寻找数组中的第k小元素

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int height; 
    int size;   
    int count;  

    TreeNode(int value) 
        : key(value), height(1), size(1), count(1), left(nullptr), right(nullptr) {}
};

class BalancedBST {
private:
    TreeNode* root;

    int getHeight(TreeNode* node) const {
        return node ? node->height : 0;
    }

    int getSize(TreeNode* node) const {
        return node ? node->size : 0;
    }

    void updateNodeInfo(TreeNode* node) const {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
            node->size = node->count + getSize(node->left) + getSize(node->right);
        }
    }

    int getBalanceFactor(TreeNode* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // 右旋
    TreeNode* rightRotate(TreeNode* y) const {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateNodeInfo(y);
        updateNodeInfo(x);

        return x;
    }
    TreeNode* leftRotate(TreeNode* x) const {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateNodeInfo(x);
        updateNodeInfo(y);

        return y;
    }

    TreeNode* balanceNode(TreeNode* node) const {
        if (!node) return nullptr;

        updateNodeInfo(node);
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* insertHelper(TreeNode* node, int value){
        if (!node) {
            return new TreeNode(value);
        }

        if (value < node->key) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->key) {
            node->right = insertHelper(node->right, value);
        } else {
            node->count++;
            node->size++;
            return node;
        }

        return balanceNode(node);
    }

    TreeNode* findMinNode(TreeNode* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* removeHelper(TreeNode* node, int value){
        if (!node) return nullptr;

        if (value < node->key) {
            node->left = removeHelper(node->left, value);
        } else if (value > node->key) {
            node->right = removeHelper(node->right, value);
        } else {
            if (node->count > 1) {
                node->count--;
                node->size--;
                return node;
            }

            if (!node->left || !node->right) {
                TreeNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    delete node;
                    return nullptr;
                } else {
                    *node = *temp;
                    delete temp;
                }
            } else {
                TreeNode* successor = findMinNode(node->right);
                node->key = successor->key;
                node->count = successor->count;
                successor->count = 1;
                node->right = removeHelper(node->right, successor->key);
            }
        }

        return balanceNode(node);
    }

    bool searchHelper(TreeNode* node, int value) const {
        if (!node) return false;
        if (value == node->key) return true;
        if (value < node->key) return searchHelper(node->left, value);
        return searchHelper(node->right, value);
    }

    void inorderHelper(TreeNode* node, std::vector<int>& result) const {
        if (!node) return;
        inorderHelper(node->left, result);
        for (int i = 0; i < node->count; ++i) {
            result.push_back(node->key);
        }
        inorderHelper(node->right, result);
    }

    int rankHelper(TreeNode* node, int value) const {
        if (!node) return 0;
        
        if (value < node->key) {
            return rankHelper(node->left, value);
        } else if (value > node->key) {
            return getSize(node->left) + node->count + rankHelper(node->right, value);
        } else {
            return getSize(node->left) + 1;
        }
    }

    int selectHelper(TreeNode* node, int k) const {
        if (!node) return -1;
        
        int leftSize = getSize(node->left);
        
        if (k <= leftSize) {
            return selectHelper(node->left, k);
        } else if (k <= leftSize + node->count) {
            return node->key;
        } else {
            return selectHelper(node->right, k - leftSize - node->count);
        }
    }

    void clearHelper(TreeNode* node) {
        if (!node) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }

public:
    BalancedBST() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void remove(int value) {
        root = removeHelper(root, value);
    }

    bool search(int value) const {
        return searchHelper(root, value);
    }

    int min() const {
        TreeNode* node = findMinNode(root);
        return node ? node->key : -1;
    }

    int max() const {
        TreeNode* node = root;
        while (node && node->right) {
            node = node->right;
        }
        return node ? node->key : -1;
    }

    std::vector<int> inorder() const {
        std::vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    int rank(int value) const {
        return rankHelper(root, value);
    }

    int select(int k) const {
        return selectHelper(root, k);
    }

    void clear() {
        clearHelper(root);
        root = nullptr;
    }

    int size() const {
        return getSize(root);
    }

    int height() const {
        return getHeight(root);
    }
};
int main(){
    int n;cin >> n;
    BalancedBST bst;
    for(int i = 1;i <= n;i++){
        int tmp;cin >> tmp;
        bst.insert(tmp);
    }
    int x;
    cin >> x;
    cout << bst.select(x);
    return 0;
}
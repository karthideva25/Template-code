#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    int height;

    Node(int x) {
        val = x;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right Rotation (LL)
Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* yR = y->right;

    y->right = x;
    x->left = yR;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Left Rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* yL = y->left;

    y->left = x;
    x->right = yL;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert
Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->val)
        return rightRotate(root);

    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Min value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// Delete
Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
          // has no children (leaf node)
            if (!temp) {
                delete root;
                return nullptr;
            } else { // has one children
                *root = *temp;
                delete temp;
            }
        } else { // has two children
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    cout << "Hello Geek!";
    return 0;
}

#pragma once
#include "Book.h"

class AVLNode {
public:
    Book info;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Book b) {
        info = b;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    AVLNode* root;

    // ---------- Basic Utilities ----------
    int getHeight(AVLNode* node) const {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(AVLNode* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // ---------- Rotations ----------
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // ---------- Insert ----------
    AVLNode* insertHelper(AVLNode* node, Book book) {
        if (!node)
            return new AVLNode(book);

        if (book.id < node->info.id)
            node->left = insertHelper(node->left, book);
        else if (book.id > node->info.id)
            node->right = insertHelper(node->right, book);
        else
            return node; // No duplicates allowed

        updateHeight(node);

        int balance = getBalance(node);

        // LL
        if (balance > 1 && book.id < node->left->info.id)
            return rightRotate(node);

        // RR
        if (balance < -1 && book.id > node->right->info.id)
            return leftRotate(node);

        // LR
        if (balance > 1 && book.id > node->left->info.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && book.id < node->right->info.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // ---------- Delete ----------
    AVLNode* minValueNode(AVLNode* node) const {
        while (node && node->left)
            node = node->left;
        return node;
    }

    AVLNode* deleteHelper(AVLNode* node, int id) {
        if (!node)
            return node;

        if (id < node->info.id)
            node->left = deleteHelper(node->left, id);
        else if (id > node->info.id)
            node->right = deleteHelper(node->right, id);
        else {
            // Node found — 0 or 1 child
            if (!node->left) {
                AVLNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                AVLNode* temp = node->left;
                delete node;
                return temp;
            }

            // 2 children: get inorder successor
            AVLNode* temp = minValueNode(node->right);
            node->info = temp->info;
            node->right = deleteHelper(node->right, temp->info.id);
        }

        if (!node)
            return node;

        updateHeight(node);
        int balance = getBalance(node);

        // Rebalance after deletion
        // LL
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // LR
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // RL
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // ---------- Search ----------
    AVLNode* searchHelper(AVLNode* node, int id, int& steps) const {
        if (!node)
            return nullptr;

        steps++;
        if (node->info.id == id)
            return node;

        if (id > node->info.id)
            return searchHelper(node->right, id, steps);
        return searchHelper(node->left, id, steps);
    }

    // ---------- Traversal ----------
    void inorderHelper(AVLNode* node) const {
        if (node) {
            inorderHelper(node->left);
            cout << "ID: " << node->info.id
                 << " | Title: " << node->info.title
                 << " | Author: " << node->info.author << "\n";
            inorderHelper(node->right);
        }
    }

    // ---------- Part 3: Range Search ----------
    void rangeSearchHelper(AVLNode* node, int low, int high) const {
        if (!node) return;

        if (node->info.id > low)
            rangeSearchHelper(node->left, low, high);

        if (node->info.id >= low && node->info.id <= high)
            cout << "ID: " << node->info.id
                 << " | " << node->info.title
                 << " | " << node->info.author << "\n";

        if (node->info.id < high)
            rangeSearchHelper(node->right, low, high);
    }

    // ---------- Part 3: Closest ID ----------
    AVLNode* closestHelper(AVLNode* node, int target) const {
        if (!node) return nullptr;

        AVLNode* best = node;
        AVLNode* curr = node;

        while (curr) {
            if (abs(curr->info.id - target) < abs(best->info.id - target))
                best = curr;

            if (curr->info.id == target)
                break;
            else if (target < curr->info.id)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return best;
    }

public:
    // Constructor
    AVL() : root(nullptr) {}

    // ---------- Public Wrappers ----------
    void insert(int id, string title, string author) {
        Book b = {id, title, author};
        root = insertHelper(root, b);
    }

    void remove(int id) {
        root = deleteHelper(root, id);
    }

    // Simple search (bool only)
    bool search(int id) {
        int steps = 0;
        return searchHelper(root, id, steps) != nullptr;
    }

    // Search that counts steps
    bool search(int id, int& steps) {
        steps = 0;
        return searchHelper(root, id, steps) != nullptr;
    }

    void inorder() {
        inorderHelper(root);
    }

    void rangeSearch(int low, int high) {
        cout << "\n[Range Search] Books with IDs between " << low << " and " << high << ":\n";
        rangeSearchHelper(root, low, high);
    }

    void closest(int target) {
        AVLNode* res = closestHelper(root, target);
        if (!res) {
            cout << "\n[Closest] Library is empty.\n";
            return;
        }
        cout << "\n[Closest] Target: " << target
             << "  ->  Found ID " << res->info.id
             << " (" << res->info.title << " by " << res->info.author << ")\n";
    }

    // ---------- Part 4: Height ----------
    int height() {
        return getHeight(root);
    }
};
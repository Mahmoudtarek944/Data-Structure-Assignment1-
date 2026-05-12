#pragma once
#include "Book.h"
class BSTNode{
    public:
        BSTNode* left ;
        BSTNode* right ;
        Book info;
        BSTNode(Book b) {
            info = b;
            left = NULL;
            right = NULL;
        }
};
class BST{
    private :
        BSTNode* root ;

        void inorderTraversal(BSTNode * p) const {
            if( p != NULL) {
                inorderTraversal(p->left) ;
                cout << "The Book Id : "<< p->info.id << " The Book Title : " << p->info.title << " The Book Author : " << p->info.author << "\n" ;
                inorderTraversal(p->right) ;
            }
        }
        // Deleted Node
        void deleteNode(BSTNode * &p){
            // by reference , p hold the arrow that it between the parent 'prev' and the delete child
            // We Have 4 cases :
            // 1 - The Delteed Node is leave :: null
            // 2 - The Delteed Node have only left child :: parent refer to the intenal child
            // 3 - The Delteed Node have only right child :: parent refer to the intenal child
            // 4 - The Delteed Node have right anf left child :: successor / predecessor

            BSTNode *temp ; // General Temp Node To Hold The deleted Node
            // Case 1:
            if(p->left == NULL && p->right == NULL){
                temp = p ;
                p = NULL ;
                delete temp ;
                return ;
            }
            // Case 2 :
            if(p->left != NULL && p->right == NULL){
                temp = p ;
                p = temp->left ;  // the arrow of the parent node refer to the internal right child
                delete temp ;
                return ;
            }
            // Case 3 :
            if(p->right != NULL && p->left == NULL){
                temp = p ;
                p = temp->right ; // the arrow of the parent node refer to the internal left child
                delete temp ;
                return ;
            }
            // Case 4 :
            if(p->left != NULL && p->right != NULL){
                // Note :
                // If We Use The Sucessor :: the successor is the less node in the right path , so it not have left child
                // If We Use The Predecessor :: the predessor is the largest node in the left path , so it not have rigth child

                BSTNode* curr = p->left ; // we go to the left path (to use predecessor)
                BSTNode* prev = NULL ; // to hold the parent of the predecessor
                while(curr->right != NULL){
                    prev = curr ;
                    curr = curr->right ;
                }

                p->info= curr->info; // we swap the value , we need to delete the predcessor

                if(prev == NULL){ // of the curr is the first left child(stil the prev NULL 'initial value')
                    p->left = curr->left ;// we no join in the while
                    // 10 -> 5 -> 3 (the predecessor is 5) then 10 -> 3
                }else{
                    prev->right = curr->left ;
                    // beacuse the predecessor not have left child (no node greater than predecessor)
                }
                delete curr ;
            }
        }
        // ---------- Part 3 & 4 Helpers ----------
        void rangeSearchHelper(BSTNode* node, int low, int high) const {
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

        BSTNode* closestHelper(BSTNode* node, int target) const {
                if (!node) return nullptr;

                BSTNode* best = node;
                BSTNode* curr = node;

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

        int getHeightHelper(BSTNode* node) const {
                if (!node) return 0;
                return 1 + max(getHeightHelper(node->left), getHeightHelper(node->right));
            }
    public :
        BST(){
            root = NULL ;
        }
        BSTNode* insert (int _id , string _title , string _author){
            if(root == NULL){
                root =new BSTNode({_id  , _title , _author}) ;
                return root ;
            }

            BSTNode* curr = root , *prev = NULL ;
            while(curr != NULL){
                prev = curr ; // to hold the parent
                if(curr->info.id < _id){
                    curr = curr->right ;
                }else if(curr->info.id > _id){
                    curr = curr->left ;
                }else{
                    cerr << "Cannot duplicate IDs\n";
                    return root;
                }
            }

            if (prev->info.id < _id){
                prev->right = new BSTNode({_id , _title, _author}) ;
            }else {
                prev->left = new BSTNode({_id , _title, _author}) ;
            }
            return root ;
        }

        bool search(int _id) const {
            bool found = false ;
            if(root == NULL){
                throw runtime_error("The Book System is Empty") ;
            }
            BSTNode* curr = root ;
            while(curr != NULL && !found) {
                if(curr->info.id == _id){
                    found = true ;
                }
                else if(curr->info.id > _id){
                    curr = curr->left ;
                }
                else{
                    curr = curr->right ;
                }
            }
            return found ;
        }

        void inorder() {
            inorderTraversal(root) ;
        }

        void searchDeletedNode(int _id){
            if(root == NULL){
                throw runtime_error("The Book System is Empty") ;
            }
            BSTNode* curr = root, *prev = NULL;
            bool found = false ;
            while(curr != NULL){
                if(curr->info.id == _id ){
                    found = true ;
                    break;
                }
                prev = curr ;
                if(curr->info.id < _id){
                    curr = curr->right ;
                }
                else{
                    curr = curr->left ;
                }
            }
            if(!found) { // == curr == NULL
                cerr << "This id not exist" ;
                return ;
            }
            else{
                if (curr == root){
                    deleteNode(root) ;
                }
                else if(prev->info.id < _id){
                    deleteNode(prev->right) ;
                }
                else{
                    deleteNode(prev->left) ;
                }
            }
        }
        // ---------- Part 3: Range Search ----------
        void rangeSearch(int low, int high) const {
                cout << "\n[Range Search] Books with IDs between " << low << " and " << high << ":\n";
                rangeSearchHelper(root, low, high);
            }

        // ---------- Part 3: Closest ID ----------
        void closest(int target) const {
                BSTNode* res = closestHelper(root, target);
                if (!res) {
                    cout << "\n[Closest] Library is empty.\n";
                    return;
                }
                cout << "\n[Closest] Target: " << target
                     << "  ->  Found ID " << res->info.id
                     << " (" << res->info.title << " by " << res->info.author << ")\n";
            }

        // ---------- Part 4: Height ----------
        int height() const {
                return getHeightHelper(root);
            }

        // ---------- Part 4: Search with Step Counter ----------
        bool search(int _id, int& steps) const {
                steps = 0;
                if (root == NULL)
                    throw runtime_error("The Book System is Empty");

                BSTNode* curr = root;
                while (curr != NULL) {
                    steps++;
                    if (curr->info.id == _id)
                        return true;
                    else if (curr->info.id > _id)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                return false;
            }

};
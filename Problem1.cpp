#include <bits/stdc++.h>
using namespace std;
struct Book {
    int id;
    string title;
    string author;
};
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

};
int main (){
    BST library;

    library.insert(50, "Data Structures", "Mahmed Tarel");
    library.insert(30, "C++ Basics", "Ahmed Bahaa");
    library.insert(70, "Algorithms", "Karem Ahmed");
    library.insert(20, "Operating Systems", "Ramez Rizk");
    library.insert(40, "Database Systems", "Osama Ahmed");
    library.insert(60, "Computer Networks", "Yosef Aymen");
    library.insert(80, "Artificial Intelligence", "Amr Atef");

    library.inorder();

    cout << "Search for Book ID 40: ";
    if (library.search(40))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Search for Book ID 100: ";
    if (library.search(100))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    library.searchDeletedNode(20); // Delete Leaf Node (20) =====
    library.inorder();

    library.searchDeletedNode(30); // Delete Node with One Child (30) 
    library.inorder();

    library.searchDeletedNode(70); // Delete Node with Two Children (70)
    library.inorder();

    library.searchDeletedNode(50); // Delete Root Node (50)
    library.inorder();

    library.insert(60, "Duplicate Book", "Unknown"); //  Duplicate Insert Test

    library.searchDeletedNode(999); // Delete Non-Existing Node 
    return 0;
}
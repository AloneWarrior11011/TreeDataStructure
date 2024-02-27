#include<bits/stdc++.h>
using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data -> ";
    cin>>data;

    if(data == -1) return NULL;

    root = new node(data); // create new node, here constructor is call.
    cout<<"Enter the data for inserting at left node-> "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting at right node-> "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void inorder(node* root){
    if(root == NULL) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}
void preOrder(node* root){
    if(root == NULL) return;

        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
}
void postOrder(node* root){
    if(root == NULL) return;

        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
}
void level_order_trav(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); // adding a separator as NULL for printing tree like pattern....level order printing of tree node data.

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
             cout<<endl; // next line mai chle gye
             if(!q.empty()){ // queue still has some element.
                q.push(NULL);
             }
        }
        else{
            cout<<temp->data;
            if(temp->left != NULL){
                 q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrderTraversal(node* root){
    // step 1 : we need a queue over there for pushing the root and use them later for building a tree
    queue<node*> q;
    cout<<"Enter the data for root -> ";
    int data;
    cin>>data;
    root = new node(data); // constructor call and initialize field such as data, left , right 

    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter the left node for -> "<<temp->data<<" -> ";
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter the right node for -> "<<temp->data<<" ->";
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
main(){
    node* root = NULL;
   //  root = buildTree(root);

    /*        7  
          /      \ 
          4      17
        /   \    /  \
        11  12   13  19

    */
    // 7 4 11 -1 12 -1 -1 -1 17 13 -1 -1 19 -1 -1
    buildFromLevelOrderTraversal(root);
    level_order_trav(root);
}
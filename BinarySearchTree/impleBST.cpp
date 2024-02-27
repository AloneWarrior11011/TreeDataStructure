#include<bits/stdc++.h>
using namespace std;

class Node{
   public : 
   int data;
   Node* left;
   Node* right;

   Node(int data){
     this->data = data;
     this->left = NULL;
     this->right = NULL;
   }
};
Node* insertData(Node* root, int key){
    if(root == NULL){
        Node* temp = new Node(key);
        return temp;
    }

    if(key > root->data){
       root->right =  insertData(root->right,key);
    }
    else{
        root->left = insertData(root->left,key);
    }
}
void getInputBst(Node* root){
   int data;
   cout<<"Enter the data to create BST : "<<endl;
   cin>>data;

   while(data != -1){
      cin>>data;
      insertData(root,data);
   }
}
main(){
    Node* root = NULL;
    getInputBst(root);

}
//Insert Data Into Tree
#include <iostream>
using namespace std;
struct BstNode{
int data;
BstNode* left;
BstNode* right;
};
//Function to create new node in heap
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//To Insert data in BST, return address of node
BstNode* Insert(BstNode* root, int data){
   if(root==NULL){
       //empty tree
       root = GetNewNode(data);
   }
   //if data to be inserted is lesser, insert inleft subtree.
   else if(data <= root->data){
       root->left = Insert(root->left, data);
   }else{
       root->right = Insert(root->right, data);
   }
   return root;
}
bool Search(BstNode* root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data<=root->data){
        return Search(root->left, data);
    }else{
        return Search(root->right, data);
    }
}
int main(){
    /*
      15
      /\
     10 20
     /\   \
    8 12   25
    */
    BstNode* root = NULL; //Creating Empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    int number;
    cout<<"Enter number be searched \n";
    cin>>number;

    if(Search(root,number)==true){
        cout<<"FOUND";
    }else{
        cout<<"Not FOUND";
    }

}
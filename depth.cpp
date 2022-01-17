//Depth First: Preorder, Inorder, Postorder
#include <iostream>
using namespace std;
struct BstNode{
int data;
BstNode* left;
BstNode* right;
};
//Function to visit nodes in Preorder
void Preorder(BstNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<"\n"; //Print Data
    Preorder(root->left); //visit left subtree
    Preorder(root->right); //visit right subtree
}
//Function to visit nodes in Inorder
void Inorder(BstNode* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<"\n";
    Inorder(root->right);
}
//Function To visit nodes in Postorder
void Postorder(BstNode* root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<"\n";
    
}
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
    BstNode* root = NULL; //Creating Empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

   /* int number;
    cout<<"Enter number be searched \n";
    cin>>number;

    if(Search(root,number)==true){
        cout<<"FOUND";
    }else{
        cout<<"Not FOUND";
    }*/
     //Print Nodes in Preorder
     cout<<"Preorder";
     Preorder(root);
     cout<<"/n";
     //Print Nodes in Inorder
     cout<<"Inorder";
     Inorder(root);
     cout<<"/n";
     //Print Nodes in Postorder
     cout<<"Postorder";
     Postorder(root);
     cout<<"/n";

}
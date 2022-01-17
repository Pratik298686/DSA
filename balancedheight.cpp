//Balanced Height Tree -> For each node the difference between the heights of the left subtree and right subtree <=1
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

int height(BstNode* root){
    if(root  == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh)+1;
}

bool isBalanced(BstNode* root){
    if(root == NULL){
        return true;
    }
    /*if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == false){
        return false;
    }*/
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh)<=1){
        return true;
    }else{
        return false;
    }
}
int main(){
    BstNode* root = NULL; //Creating Empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,26);
     root = Insert(root,27);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    //Height Balanced Tree
    if(isBalanced(root)){
        cout<<"Balanced tree"<<"\n";
    }else{
        cout<<"Unbalanced Tree"<<"\n";
    }

}
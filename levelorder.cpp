//Levelorder Tree
#include <iostream>
#include <queue>
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
//Function to print Nodes in a binary tree in level order
void LevelOrder(BstNode* root){
    if(root == NULL){return;}
        queue<BstNode*> Q; //Define the Q data structure
        Q.push(root);
    
        //While there is at least one discovered node
        while(!Q.empty()){
            int size = Q.size();
            
            for(int i=0; i<size; i++){
            BstNode* current = Q.front(); //Taking the current node
            Q.pop(); //removing the element at front
            cout<<current->data<<endl;
            if(current->left!= NULL){
                Q.push(current->left);
            }
            if(current->right!= NULL){
                Q.push(current->right);
            }
            }
        }

    
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
int main(){
    BstNode* root = NULL; //Creating Empty tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    
    
    //Print node in level order
     LevelOrder(root);
}
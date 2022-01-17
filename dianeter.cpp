//Find The Diameter: Number of nodes in the longest path between any 2 leaves
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

int calcHeight(BstNode* root){
    if(root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight)+1;
}

int calcDiameter(BstNode* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight+1 ;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
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
   
   //Height of binary Tree
   cout<<calcHeight(root)<<endl;
   //
   cout<<calcDiameter(root)<<endl;

   return 0;
    

}
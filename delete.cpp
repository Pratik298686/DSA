//Delete Node
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
//Function to find minimum in a tree
BstNode* FindMin(BstNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
//Delete
BstNode* Delete(BstNode* root, int data){
   if(root == NULL){
       return root;
   }
   else if(data < root->data){
       root->left = Delete(root->left, data);
   }
   else if(data > root->data){
       root->right = Delete(root->right,data);
   }
   //Get ready to be deleted
   else{
       //Case 1: No Child
    if(root == NULL){
        return root;
    }
    //Case 2. One child
    else if(root->left == NULL){
        BstNode *temp = root;
        root = root->right;
        delete temp;
    }
    //Case 3. two children
    else{
        BstNode *temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
   }
    return root;
}
//Function to visit nodes in Inorder
void Inorder(BstNode *root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
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
     //Deleting node with 8 value, 
      root = Delete(root,8);

      //Print Nodes in Inorder
      cout<<"Inorder: ";
      Inorder(root);
      cout<<"\n";
}
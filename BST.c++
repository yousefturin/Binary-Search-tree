#include <iostream>
using namespace std;
 
struct BstNode {
    int data;
    BstNode* left; 
    BstNode* right;
};

int FindMin(BstNode* root)
{
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}

int FindMax(BstNode* root)
{
    while(root->right!=NULL)
        root = root->right;
    return root->data;
}

BstNode* CreateNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if(root == NULL)
    {
        root = CreateNode(data);
        return root;
    }
    else if(data<=root->data)
    {
        root->left = Insert(root->left, data);
    }
    else 
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

BstNode* deleteNode(BstNode* root, int data)
{
   if (root == NULL) 
    return root;
      
        if (data < root->data)
            root->left = deleteNode(root->left, data);

        else if (data > root->data)
             root->right = deleteNode(root->right, data);

   else{
    
      if (root->left==NULL and root->right==NULL)
      {
         return NULL;
      }

      else if (root->right == NULL)
      {
         BstNode* temp = root->left;
         free(root);
         return temp;
      }
      
      else if (root->left == NULL)
      {
         BstNode* temp = root->right;
         free(root);
         return temp;
      }
   }
   return root;
}


void InOrder(BstNode* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }  
}

bool Search(BstNode* root, int key)
{
    if(root==NULL)
        return false;
    else if(key==root->data)
        return true;
    else if(key<=root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}



int main()
{
    BstNode* root = NULL;
    root = Insert(root, 19);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 7);
    root = Insert(root, 23);
    root = Insert(root, 15);
    root = Insert(root, 4);
    root = Insert(root, 37);
    root = Insert(root, 40);
    root = Insert(root, 10);
    root = Insert(root, 5);

    cout<<"Minimum Value: "<< FindMin(root)<<endl;
    cout<<"Maximum Value: "<< FindMax(root) <<endl;
    InOrder(root);
    if(Search(root, 37))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    cout << "Delete 15"<<endl;
    root = deleteNode(root, 15);
    InOrder(root);
}




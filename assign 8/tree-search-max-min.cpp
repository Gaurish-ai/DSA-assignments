#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
bool searchelement(Node* node,int val)
{
    if(node==NULL)
    return false;
    if(val==node->data)
    {
        return true;
    }
    if(val < node->data)
    {
        return searchelement(node->left,val);
    }
    if(val > node->data)
    {
        
       return searchelement(node->right,val);
    }
    return false;
}
int findMax(Node* node) {
    if (node == NULL) return -1;

    while (node->right != NULL)
        node = node->right;         

    return node->data;
}
int findMin(Node* node) {
    if (node == NULL) return 100000000;
    while (node->left != NULL)
        node = node->left;          
    return node->data;
}
int main()
{
    
}
/**
* @author Jatin Sharma
* @date 26 June 2024
* @problem https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/solutions/5369158/0ms-c-recursion-no-extra-functions/
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//Definition for a binary tree node.

struct TreeNode {
     int val = 0;
     TreeNode *left = nullptr;
     TreeNode *right = nullptr;
 };

class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right != nullptr) bstToGst(root->right);
        root->val += sum;
        sum = root->val;
        if(root->left != nullptr) bstToGst(root->left);
        return root;
    }
};

class BST{
private:
    TreeNode* root = nullptr;
public:
    TreeNode* createBST(vector<int>& arr)
    {
        for(int i=0 ; i< arr.size() ; i++)
        {
            if (arr[i] != -1)
            {
                TreeNode* new_node = new TreeNode;
                new_node->val = arr[i];
                if(root == nullptr) 
                {
                    root = new_node;
                }
                else
                {
                    TreeNode* temp_root = root;
                    while(temp_root)
                    {
                        if(temp_root->val > arr[i])
                        {
                            if(temp_root->left)
                                temp_root = temp_root->left;
                            else 
                            {
                                temp_root->left = new_node;
                                break;
                            }
                        }
                        else
                        {
                            if(temp_root->right)
                                temp_root = temp_root->right;
                            else 
                            {
                                temp_root->right = new_node;
                                break;
                            }
                        }
                            
                    }
                    
                }
            }
        }
        return root;
    }

    void printBsd(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            cout << temp->val << " ";
            q.pop();
            if(temp->left) q.push(temp->left);
            else {
                if(temp->val != -1)
                {
                    TreeNode* empty = new TreeNode;
                    empty -> val = -1;
                    q.push(empty);
                }
            }
            if(temp->right) q.push(temp->right);
            else {
                if(temp->val != -1)
                {
                    TreeNode* empty = new TreeNode;
                    empty -> val = -1;
                    q.push(empty);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    BST bst;
    TreeNode* root = bst.createBST(arr);
    bst.printBsd(root);
    Solution sol;
    sol.bstToGst(root);
    bst.printBsd(root);
    return 0;
}
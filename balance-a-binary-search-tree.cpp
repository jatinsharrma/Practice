/**
* @author Jatin Sharma
* @date 26-June-2024
* @problem https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2024-06-26
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief Definition for a binary tree node.
 * 
 * This struct represents a node in a binary tree. Each node has an integer value and pointers to its left and right child nodes.
 */
struct TreeNode {
    int val = 0; /**< The value stored in the node. */
    TreeNode *left = nullptr; /**< Pointer to the left child node. */
    TreeNode *right = nullptr; /**< Pointer to the right child node. */
};
struct TreeNode {
     int val = 0;
     TreeNode *left = nullptr;
     TreeNode *right = nullptr;
};

/**
 * @class BST
 * @brief Represents a Binary Search Tree (BST).
 * 
 * The BST class provides functionality to create and print a binary search tree.
 * It supports operations like creating a BST from an array and printing the BST in breadth-first order.
 */
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


/**
 * @class Solution
 * @brief Class that provides a solution for balancing a binary search tree.
 */
class Solution {
private:
    /**
     * @brief Helper function to traverse the binary search tree in-order and store the values in a vector.
     * @param root The root of the binary search tree.
     * @param sorted A reference to the vector to store the sorted values.
     */
    void traverse(TreeNode* root, vector<int> &sorted)
    {
        if(root == nullptr) return;
        traverse(root->left,sorted);
        sorted.push_back(root->val);
        traverse(root->right,sorted);
    }

    /**
     * @brief Helper function to construct a balanced binary search tree from a sorted vector of values.
     * @param sorted The sorted vector of values.
     * @param l The left index of the subarray.
     * @param r The right index of the subarray.
     * @return The root of the constructed binary search tree.
     */
    TreeNode* constructBST(vector<int> sorted,int l, int r)
    {
        if(r<l) return NULL;
        TreeNode* root = new TreeNode;
        int mid = (r+l)/2;
        root->val = sorted[mid];
        root->left = constructBST(sorted,l,mid-1);
        root->right = constructBST(sorted,mid+1,r);
        return root;
    }

public:
    /**
     * @brief Balances a binary search tree.
     * @param root The root of the binary search tree to be balanced.
     * @return The root of the balanced binary search tree.
     */
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        TreeNode* temp_root = root;
        traverse(temp_root,sorted);
        for(int i=0; i<sorted.size();i++) cout << sorted[i] << " "; 
        return constructBST(sorted,0,sorted.size()-1);;
    }
};
int main()
{
    vector<int> arr {2,1,3};
    BST bst;
    TreeNode* root = bst.createBST(arr);
    Solution sol;
    root = sol.balanceBST(root);
    bst.printBsd(root);
    return 0;
}
/**
* @author Jatin Sharma
* @date 16 Jul 2024
* @problem https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2024-07-15
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    unordered_map<int,TreeNode*> Map;
    /**
     * Better Solution in terms of time and space
     * 
     * Creates a binary tree from a vector of descriptions.
     * Each description is a vector of three integers: [parent, child, direction].
     * The parent and child nodes are represented by their values.
     * The direction indicates whether the child node should be placed on the left (1) or right (0) of the parent node.
     * If a node is already created, it will not be created again.
     * 
     * @param descriptions A vector of descriptions representing the binary tree.
     * @return The root node of the created binary tree.
     */
    TreeNode* createBinaryTree2(vector<vector<int>>& descriptions) {
        for(auto &v:descriptions)
        {
            if ( !Map.count( v[0]) ) Map[v[0]] = new TreeNode(v[0]);
            if ( !Map.count( v[1]) ) Map[v[1]] = new TreeNode(v[1]);   
            if (v[2] == 1)
            {
                Map[v[0]]->left  = Map[v[1]];
            }
            else
            {
                Map[v[0]]->right = Map[v[1]];
            }        
        }
        return getParent(descriptions);        
    }
    /**
     * Returns the parent node of a binary tree constructed from the given descriptions.
     * 
     * @param descriptions A vector of vectors representing the descriptions of the binary tree nodes.
     *                     Each inner vector contains two integers: the first integer represents the node value,
     *                     and the second integer represents the parent node value.
     * @return The parent node of the binary tree.
     */
    TreeNode* getParent(vector<vector<int>>& descriptions)
    {        
        for(auto &v:descriptions)
        {
            Map[v[1]] = nullptr;
        } 
        for (auto & [k,v]: Map)
        {
            if (v)
            {
                return v;
            }
        }
        return nullptr;
    }

    /**
     * Creates a binary tree from a vector of descriptions.
     * Each description is a vector of three integers: [parent, child, isLeftChild].
     * The function returns the root of the created binary tree.
     *
     * @param descriptions A vector of descriptions representing the binary tree.
     * @return The root of the created binary tree.
     */
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_map<int, TreeNode*> root;
        for(auto i : descriptions)
        {
            if(!map.contains(i[0]) && !map.contains(i[1]))
            {
                TreeNode* node1 = new TreeNode(i[0]);
                TreeNode* node2 = new TreeNode(i[1]);
                if(i[2]) node1 -> left = node2;
                else node1 -> right = node2;
                map[i[0]] = node1;
                map[i[1]] = node2;
                root[i[0]] = node1;
            }
            else
            {
                TreeNode* node1 = (map.contains(i[0])) ? map[i[0]] : new TreeNode(i[0]);
                TreeNode* node2 = (map.contains(i[1])) ? map[i[1]] : new TreeNode(i[1]);
                if(i[2]) node1 -> left = node2;
                else node1 -> right = node2;
                
                if(root.contains(i[1]) && root.contains(i[0]))
                {
                    root.erase(i[1]);
                }
                else if(map.contains(i[0]) && map.contains(i[1]))
                {
                    root.erase(i[1]);
                }
                else if (root.contains(i[1]))
                {
                    root.erase(i[1]);
                    root[i[0]] = node1;
                }
                map[i[0]] = node1;
                map[i[1]] = node2;
            }
        }
        TreeNode* ans;
        for(auto i: root) ans = i.second;
        return ans;
    }

    /**
     * Traverses the binary tree in level order and prints the values of each node.
     * 
     * @param root A pointer to the root node of the binary tree.
     */
    void traverse(TreeNode* root)
    {
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty())
        {
            cout << que.front()->val << " ";
            if (que.front()->left) que.push(que.front()->left);
            else cout << "null" << " ";
            if (que.front()->right) que.push(que.front()->right);
            else cout << "null" << " ";
            que.pop();
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> descriptions {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    sol.traverse(sol.createBinaryTree(descriptions));
    return 0;
}
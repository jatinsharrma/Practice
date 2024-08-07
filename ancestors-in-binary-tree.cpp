/**
* @author Jatin Sharma
* @date 7 Jul 2024
* @problem https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function template for C++

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

/**
 * @class Solution
 * @brief Class that provides methods to find ancestors of a target node in a binary tree.
 */
class Solution {
  private:
    bool search(Node* root, vector<int> & ans, int target)
    {
        if(!root) return false;
        if(root->data == target) return true;
        if(search(root->left,ans,target)||search(root->right,ans,target))
        {
            ans.push_back(root->data);
            return true;
        }
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        search(root,ans,target);
        return ans;
        
    }
    vector<int> Ancestors2(struct Node *root, int target) {
        // Code here
        queue<Node*> q1;
        queue<vector<int>> q2;
        if(root->left)
        {
            q1.push(root->left);
            q2.push({root->data});
        }
        if(root->right)
        {
            q1.push(root->right);
            q2.push({root->data});
        }
        while(!q1.empty())
        {
            Node* curr_node = q1.front();
            vector<int> parents = q2.front();
            q1.pop();
            q2.pop();
            if (curr_node->data == target) 
            {
                reverse(parents.begin(), parents.end());
                return parents;
            }
            parents.push_back(curr_node->data);
            if(curr_node->left)
            {
                q1.push(curr_node->left);
                q2.push(parents);
            }
            if(curr_node->right)
            {
                q1.push(curr_node->right);
                q2.push(parents);
            }
        }
        return {};
        
    }
};



//{ Driver Code Starts.
int main() {
    int t = 1;
    while (t--) {
        string s = "1 2 3 N 4 5 N 7 8";

        int target = 8;

        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root, target);
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
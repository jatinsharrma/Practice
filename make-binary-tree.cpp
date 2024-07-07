/**
* @author Jatin Sharma
* @date 1 Jul 2024
* @problem https://www.geeksforgeeks.org/problems/make-binary-tree
*/

#include <iostream>
#include <queue>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    T = 1;

    while (T--) {
        struct Node *head = NULL;

        n = 5;
        int arr[] = {1,2,3,4,5};
        for (i = 0; i < n; i++) {
            push(&head, arr[i]);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    root = new TreeNode(head->data);
    head = head->next;
    queue <TreeNode*> q;
    q.push(root);
    while(head)
    {
        TreeNode* temp = q.front();
        q.pop();
        temp->left = new TreeNode(head->data);
        q.push(temp->left);
        head = head->next;
        if(head)
        {
            temp->right = new TreeNode(head->data);
            q.push(temp->right);
            head = head->next;
        }
    }
}

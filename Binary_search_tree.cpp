#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

    Node* insert(Node* root,int d)
    {
        if(root == NULL)
        {
            return new Node(d);
        }

        if(d > root -> data)
        {
            root -> left = insert(root -> left, d);
        }
        else if(d < root -> data)
        {
            root -> right = insert(root -> right, d);
        }

        return root;

    }

    void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            cout << temp -> data << " ";

            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }

        cout << endl;
    }

}

};

int main()
{
    Node* root = NULL;
    Node n(3);
    root = n.insert(root,10);
    root = n.insert(root,20);
    root = n.insert(root,30);

    n.levelOrderTraversal(root);
}

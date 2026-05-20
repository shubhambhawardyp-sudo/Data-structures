// File: expression_tree.cpp

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class ExpressionTree {
private:
    Node* root;

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' ||
               ch == '*' || ch == '/' ||
               ch == '^';
    }

public:
    ExpressionTree() {
        root = nullptr;
    }

    void constructFromPrefix(const string& prefix) {
        stack<Node*> st;

        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix[i];

            if (isOperator(ch)) {
                Node* node = new Node(ch);

                if (st.size() < 2) {
                    cout << "Invalid Prefix Expression\n";
                    return;
                }

                node->left = st.top();
                st.pop();

                node->right = st.top();
                st.pop();

                st.push(node);
            } else {
                st.push(new Node(ch));
            }
        }

        if (!st.empty()) {
            root = st.top();
        }

        cout << "Expression Tree Constructed Successfully\n";
    }

    void postorderNonRecursive() {
        if (root == nullptr) {
            cout << "Tree is Empty\n";
            return;
        }

        stack<Node*> s1;
        stack<Node*> s2;

        s1.push(root);

        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left) {
                s1.push(temp->left);
            }

            if (temp->right) {
                s1.push(temp->right);
            }
        }

        cout << "Postorder Traversal: ";

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }

        cout << endl;
    }

    void deleteTree() {
        if (root == nullptr) {
            cout << "Tree Already Empty\n";
            return;
        }

        stack<Node*> s1;
        stack<Node*> s2;

        s1.push(root);

        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left) {
                s1.push(temp->left);
            }

            if (temp->right) {
                s1.push(temp->right);
            }
        }

        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();

            delete temp;
        }

        root = nullptr;

        cout << "Entire Tree Deleted Successfully\n";
    }
};

int main() {
    ExpressionTree tree;

    int choice;
    string prefix;

    do {
        cout << "\n====== Expression Tree Menu ======\n";
        cout << "1. Construct Expression Tree\n";
        cout << "2. Postorder Traversal (Non-Recursive)\n";
        cout << "3. Delete Entire Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Prefix Expression: ";
                cin >> prefix;

                tree.constructFromPrefix(prefix);
                break;

            case 2:
                tree.postorderNonRecursive();
                break;

            case 3:
                tree.deleteTree();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}
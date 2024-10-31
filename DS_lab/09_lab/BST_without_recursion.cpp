#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data){
			this->data = data;
			left = nullptr;
			right = nullptr;
		}
};
class Tree {
	private:
		Node* root;
	public:
		Tree(){
			root = nullptr;
		}
		
		Node* getRoot(){
			return root;
		}
		void insert(int val) {
    		Node* newNode = new Node(val);
    		if (root == nullptr) {
        		root = newNode;
        		return ;
    		}
    		Node* curr = root;  // Start at the root node
    		Node* par = nullptr; // To keep track of the parent node
    		
	    	while (curr != nullptr) {
	        	par = curr;
	        	if (val < curr->data) {
	            	curr = curr->left;
				}
				else {
	            	curr = curr->right;
	        	}
			}

			// Insert the new node in the correct position
	    	if (val < par->data) {
	        	par->left = newNode;
	    	} 
			else {
	        	par->right = newNode;
	    	}
		}
		
		void inorder(){
			inorder(root);
		}
		void inorder(Node* root) {
    		if (root == nullptr) {
        		return;
			}
		    // Traverse the left subtree
		    inorder(root->left);
		    // Visit the root node
		    cout << root->data << " ";
		    // Traverse the right subtree
		    inorder(root->right);
		}
		
        Node* findMin(Node* node) {
            Node* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        Node* deleteNode(Node* root, int key) {
            if (root == nullptr) {
                return root;
            }

            // Traverse the tree to find the node to be deleted
            if (key < root->data) {
                root->left = deleteNode(root->left, key); 
            } else if (key > root->data) {
                root->right = deleteNode(root->right, key);  
            } else {
                // Node to be deleted found
                // Case 1: Node has no child (leaf node)
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                }
                // Case 2: Node has one child (left or right)
                else if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // Case 3: Node has two children
                Node* temp = findMin(root->right);  // Find the in-order successor (smallest in the right subtree)
                root->data = temp->data;  // Replace the data of the node to be deleted with the successor's data
                root->right = deleteNode(root->right, temp->data);  // Delete the successor node
            }
            return root;
        }

        void deleteValue(int key) {
            root = deleteNode(root, key);
        }	
};
int main(){
	Tree tree;
	
	tree.insert(42);
    tree.insert(28);
    tree.insert(62);
    tree.insert(31);
    tree.insert(21);
    tree.insert(71);
    tree.insert(59);
    tree.insert(23);
    tree.insert(17);
    tree.insert(57);
    tree.insert(35);
    tree.insert(30);
    tree.insert(82);
    tree.insert(60);
    tree.insert(67);
    
	cout<<"Inorder Traversal: \n";
	tree.inorder();
	cout<<endl;
	
	tree.deleteValue(31);
	cout<<"AFter Deletion: Inorder Traversal: \n";
	tree.inorder();
	cout<<endl;
	
}
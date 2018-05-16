#include <iostream>
using namespace std;

template <typename T> class BST;
template <typename T> class TreeNode
{
    friend class BST<T>;
    public:
        TreeNode()
        {
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
    private:
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;
};
template <typename T> class BST
{
    public:
        BST()
        {
            this->root = NULL;
        }
        bool isEmpty ()
        {
            if (this->root == NULL)
                return true;
            else
                return false;
        }
        void add_element (T insert)
        {
            TreeNode<T> *temp = new TreeNode();
            temp->data = insert;
            TreeNode<T> *current = this->root;
            if (this->root == NULL)
                root = temp;
            else
            {
                while ((current->leftChild != NULL) && (current->rightChild != NULL)) 
                {
                    if (temp->data < current->data)
                        current = current->leftChild;
                    else
                        current = current->rightChild;
                }
                if (temp->data < current->data)
                    current->leftChild = temp;
                else
                    current->rightChild = temp;
            }
        }
        void in_order ()
        {
            in_order(this->root);
        }
        void in_order (TreeNode<T>* current)
        {
            if (current)
            {
                in_order(current->leftChild);
                cout << current->data << " ";
                in_order(current->rightChild);
            }
        }
    private:
        TreeNode<T> *root;
};

int main() 
{ 
    return 0; 
}
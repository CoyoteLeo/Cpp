#include <iostream>
using namespace std;
template <typename T>
class BinaryTree;
template <typename T>
T minimum(BinaryTree<T> *bt);

template <typename T>
class TreeNode {
    friend class BinaryTree<T>;
    friend T minimum<T>(BinaryTree<T> *bt);

   public:
    TreeNode(T value) {
        left = NULL;
        right = NULL;
        data = value;
    }

   private:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <typename T>
class BinaryTree {
    friend class TreeNode<T>;

   public:
    BinaryTree() {
        root = NULL;
    }
    BinaryTree(TreeNode<T> node) {
        *root = node;
    }
    bool IsEmpty() {
        return root == NULL;
    }
    TreeNode<T> *LeftSubtree() {
        return root->left;
    }

    BinaryTree<T> *RightSubtree() {
        return root->right;
    }

    T RootData() {
        return root->data;
    }

    void insert(T value) {
        if (root == NULL)
            root = new TreeNode<T>(value);
        else
            _insert(root, value);
    }

    void in_order() {
        return _in_order(root);
    }

   protected:
    T _insert(TreeNode<T> *node, T value) {
        if (value > node->data) {
            if (node->right == NULL)
                node->right = new TreeNode<T>(value);
            else
                return _insert(node->right, value);
        } else if (value < node->data) {
            if (node->left == NULL)
                node->left = new TreeNode<T>(value);
            else
                return _insert(node->left, value);
        }
        return value;
    }

    void _in_order(TreeNode<T> *r) {
        if (r == NULL)
            return;
        if (r->left != NULL)
            _in_order(r->left);
        cout << r->data << ' ';
        if (r->right != NULL)
            _in_order(r->right);
    }

   private:
    TreeNode<T> *root;
};

template <typename T>
T minimum(BinaryTree<T> *bt) {
    if (bt->LeftSubtree() == NULL)
        return bt->RootData();
    else
        return minimum(bt->LeftSubtree());
}

// template <typename T>
// T Least_Bound(BinaryTree<T> *bt, T bound) {
//     if (bt->RootData() > bound) {
//         if (bt->LeftSubtree() == NULL)
//             return bt->RootData();
//         else
//             return Least_Bound(bt->LeftSubtree(), bound);
//     } else {
//         if (bt->RightSubtree() == NULL)
//             return bound;
//         else
//             return Least_Bound(bt->RightSubtree(), bound);
//     }
// }

// template <typename T>
// T PairLeastBound(BinaryTree<T> *bt, int target) {
//     // This list a1 is passed as an argument
//     // in treeToList method
//     // which is later on filled by the values of BST
//     ArrayList<Integer> a1 = new ArrayList<>();

//     // a2 list contains all the values of BST
//     // returned by treeToList method
//     ArrayList<Integer> a2 = treeToList(node, a1);

//     int start = 0;  // Starting index of a2

//     int end = a2.size() - 1;  // Ending index of a2

//     while (start < end) {
//         if (a2.get(start) + a2.get(end) == target)  // Target Found!
//         {
//             System.out.println("Pair Found: " + a2.get(start) + " + " + a2.get(end) + " " +
//             "= "
//             +
//                                target);
//             return true;
//         }

//         if (a2.get(start) + a2.get(end) > target)  // decrements end
//         {
//             end--;
//         }

//         if (a2.get(start) + a2.get(end) < target)  // increments start
//         {
//             start++;
//         }
//     }
// }
int main() {
    BinaryTree<int> root;
    root.insert(10);
    root.insert(4);
    root.insert(8);
    root.insert(11);
    root.insert(13);
    root.insert(9);
    root.in_order();
    cout << '\n' << minimum<int>(&root) << endl;
    // cout << Least_Bound<int>(&root, 11) << endl;
    return 0;
}
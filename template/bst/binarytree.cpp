#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
using namespace std;

template <typename T>
class BinaryTree {
   public:
    BinaryTree() {
        data = NULL;
        left = NULL;
        right = NULL;
    }
    bool IsEmpty() {
        return data == NULL;
    }
    BinaryTree<T> *LeftSubtree() {
        return this->left;
    }

    BinaryTree<T> *RightSubtree() {
        return this->right;
    }

    T RootData() {
        return *data;
    }

    T insert(T value) {
        if (data == NULL) {
            data = new T(value);
        } else if (value > *data) {
            if (right == NULL)
                right = new BinaryTree<T>;
            return right->insert(value);
        } else if (value < *data) {
            if (left == NULL)
                left = new BinaryTree<T>;
            return left->insert(value);
        }
        return *data;
    }
    void in_order() {
        if (data == NULL)
            return;
        if (left != NULL)
            left->in_order();
        cout << *data << ' ';
        if (right != NULL)
            right->in_order();
    }
    /* method in tree class for Q5.Q6.Q7 */
    T minimum() {
        if (left == NULL)
            return *data;
        else
            return left->minimum();
    }
    T Least_Bound(T bound) {
        if (*data > bound) {
            if (left == NULL)
                return *data;
            else
                return left->Least_Bound(bound);
        } else if (*data == bound) {
            return bound;
        } else {
            if (right == NULL)
                return LONG_MIN;
            // if the bound greater than all elements in the tree return the long int minium
            else
                return right->Least_Bound(bound);
        }
    }
    T Least_Combined(T bound) {
        return Least_Combined(bound, this, T(LONG_MAX));
    }
    T Least_Combined(T bound, BinaryTree<T> *root, T tmpAns) {
        T least = root->Least_Bound(bound - *data);
        if (least != LONG_MIN) {
            tmpAns = min(tmpAns, least + (*data));
            if (left != NULL)
                tmpAns = min(tmpAns, left->Least_Combined(bound, root, tmpAns));
        }
        if (right != NULL) {
            tmpAns = min(tmpAns, right->Least_Combined(bound, root, tmpAns));
        }
        return tmpAns;
    }

   private:
    T *data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
};

/* independent function for Q5.Q6.Q7 */
template <typename T>
T minimum(BinaryTree<T> *bt) {
    if (bt->LeftSubtree() == NULL)
        return bt->RootData();
    else
        return minimum(bt->LeftSubtree());
}

template <typename T>
T Least_Bound(BinaryTree<T> *bt, T bound) {
    if (bt->RootData() > bound) {
        if (bt->LeftSubtree() == NULL)
            return bt->RootData();
        else
            return Least_Bound(bt->LeftSubtree(), bound);
    } else if (bt->RootData() == bound) {
        return bound;
    } else {
        if (bt->RightSubtree() == NULL)
            return LONG_MIN;
        // if the bound greater than all elements in the tree return the long int minium
        else
            return Least_Bound(bt->RightSubtree(), bound);
    }
}

template <typename T>
T Least_Combined(T bound, BinaryTree<T> *nowNode, BinaryTree<T> *root, T tmpAns) {
    T least = Least_Bound(root, bound - nowNode->RootData());
    if (least != LONG_MIN) {
        tmpAns = min(tmpAns, least + nowNode->RootData());
        if (nowNode->LeftSubtree() != NULL)
            tmpAns = min(tmpAns, Least_Combined(bound, nowNode->LeftSubtree(), root, tmpAns));
    }
    if (nowNode->RightSubtree() != NULL)
        tmpAns = min(tmpAns, Least_Combined(bound, nowNode->RightSubtree(), root, tmpAns));
    return tmpAns;
}

int main() {
    BinaryTree<int> root;
    cout << "tree -> inorder:";
    root.insert(10);
    root.insert(4);
    root.insert(8);
    root.insert(11);
    root.insert(13);
    root.insert(9);
    root.in_order();
    cout << endl;
    cout << "tree -> minium:" << endl;
    cout << minimum<int>(&root) << endl;  // independent function
    // cout << root.minimum() << endl;  // in tree operation
    cout << "tree -> Least_bound for 7:" << endl;
    cout << Least_Bound<int>(&root, 7) << endl;  // independent function
    // cout << root.Least_Bound(7) << endl;  // in tree operation
    cout << "tree -> Least_Combined for 15:" << endl;
    cout << Least_Combined<int>(15, &root, &root, LONG_MAX) << endl;  // independent function
    // cout << root.Least_Combined(15) << endl;  // in tree operation
    return 0;
}
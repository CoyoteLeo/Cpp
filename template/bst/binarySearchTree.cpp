#include <bits/stdc++.h>
using namespace std;
#define INF 99999
template <class T>
class ansForm {
   public:
    T m;
    T n;
    T sum;
    bool operator<(ansForm& other) {
        return sum < other.sum;
    }
};

template <class T>
class BinaryTree {
   public:
    BinaryTree() {
        empty = true;
        leftSubTree = rightSubTree = NULL;
    }
    BinaryTree(T root) {
        empty = false;
        this->root = root;
        leftSubTree = rightSubTree = NULL;
    }

    bool isEmpty() {
        return empty;
    }
    T getRootData() {
        return root;
    }

    BinaryTree<T> getLeftSubtree() {
        return *leftSubTree;
    }
    BinaryTree<T> getRightSubtree() {
        return *rightSubTree;
    }

    void add(T data) {
        if (empty) {
            root = data;
            empty = false;
            return;
        }
        if (data < root) {
            if (leftSubTree == NULL) {
                leftSubTree = new BinaryTree(data);
                return;
            } else {
                leftSubTree->add(data);
            }
        } else {
            if (rightSubTree == NULL) {
                rightSubTree = new BinaryTree(data);
                return;
            } else {
                rightSubTree->add(data);
            }
        }
    }

    T getMin() {
        if (empty) {
            // empty
            printf("It's empty!\n");
            return root;
        }
        if (leftSubTree == NULL) {
            return root;
        } else {
            return leftSubTree->getMin();
        }
    }

    // has answer, ans
    pair<bool, T> Least_Bound(T k) {
        if (empty) {
            // empty
            return pair<bool, T>(false, root);
        }
        if (k > root) {
            if (rightSubTree != NULL) {
                return rightSubTree->Least_Bound(k);
            } else {
                return pair<bool, T>(false, root);
            }
        } else {
            if (leftSubTree != NULL) {
                if (k <= leftSubTree->root) {
                    return leftSubTree->Least_Bound(k);
                }
            }
        }
        return pair<bool, T>(true, root);
    }

    T Least_Combined(T k) {
        return Least_Combined(k, *this, T(INF));
    }
    T Least_Combined(T k, BinaryTree<T>& rootTree, T tmpAns) {
        pair<bool, T> least = rootTree.Least_Bound(k - root + 1);
        if (least.first) {
            tmpAns = min(tmpAns, least.second + root);
        }
        if (leftSubTree != NULL) {
            tmpAns = min(tmpAns, leftSubTree->Least_Combined(k, rootTree, tmpAns));
        }
        if (rightSubTree != NULL) {
            tmpAns = min(tmpAns, rightSubTree->Least_Combined(k, rootTree, tmpAns));
        }
        return tmpAns;
    }

   private:
    bool empty;
    T root;
    BinaryTree<T>* leftSubTree;
    BinaryTree<T>* rightSubTree;
};

int main() {
    BinaryTree<int> myTree = BinaryTree<int>();
    puts("---min---");
    printf("%d\n", myTree.getMin());
    myTree.add(4);
    printf("%d\n", myTree.getMin());
    myTree.add(6);
    myTree.add(1);
    // myTree.add(8);
    // myTree.add(5);
    // myTree.add(7);
    // myTree.add(3);
    printf("%d\n", myTree.getMin());

    puts("\n---Least Bound---");
    pair<bool, int> ans = myTree.Least_Bound(0);
    if (ans.first) {
        printf("0 : %d\n", ans.second);
    }

    ans = myTree.Least_Bound(3);
    if (ans.first) {
        printf("3 : %d\n", ans.second);
    }

    ans = myTree.Least_Bound(9);
    if (ans.first) {
        printf("9 : %d\n", ans.second);
    }
    puts("\n---Least Combined---");
    printf("grater 13 : %d\n", myTree.Least_Combined(13));
    printf("grater 8 : %d\n\n", myTree.Least_Combined(8));
}
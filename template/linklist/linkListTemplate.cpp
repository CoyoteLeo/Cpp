#include <bits/stdc++.h>
using namespace std;
template <typename T>
class linkList;

template <typename T>
class node {
    friend linkList<T>;

   private:
    T value;
    node* next;

   public:
    node(){};
    node(T v) {
        value = v;
        next = NULL;
    }
};

template <typename T>
class linkList {
   private:
    node<T>* first;
    node<T>* last;

   public:
    linkList() {
        first = new node<T>();
        last = first;
    }
    void push_back(T v) {
        last->next = new node<T>(v);
        last = last->next;
    }
    void erase(int n) {
        node<T>* p = first;
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        delete (p->next);
    }
    void print() {
        for (node<T>* p = first->next; p != last; p = p->next) {
            cout << p->value << " ";
        }
        cout << endl;
    }
};

int main() {
    linkList<int> terry;
    for (int i = 0; i < 5; i++) {
        terry.push_back(i);
    }
    terry.print();
}
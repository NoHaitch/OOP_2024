#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree(){
            numChildren = 0;
        }

        // Copy constructor
        BinaryTree(const BinaryTree<T>& other){
            value = other.value;
            children = other.children;
            numChildren = other.numChildren;
        }

        // Destruktor
        ~BinaryTree(){}

        // Setter untuk value
        void setValue(const T & newVal){
            value = newVal;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T childValue){
            if(numChildren < 2){
                children.push_back(BinaryTree<T>());
                children.back().setValue(childValue);
                numChildren++;
                return children.back();
            } else{
                throw "Tidak bisa memiliki lebih dari dua children\n";
            }
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& stream, BinaryTree<T> tree){
            stream << tree.value;

            if(tree.numChildren > 0){
                stream << "(" << tree.children[0] << ")";
            } else{
                stream << "()";
            }

            if(tree.numChildren > 1){
                stream << "(" << tree.children[1] << ")";
            } else{
                stream << "()";
            }

            return stream;
        }

        
};

#endif
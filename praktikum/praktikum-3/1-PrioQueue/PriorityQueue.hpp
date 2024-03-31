#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue(){
        size = 0;
    }
    
    /*
        Destructor
    */
    ~PriorityQueue(){
    }

    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
        size++;
        content.push_back(value);
        sort(content.begin(), content.end());
        for(int i = 0; i < size/2; i++){
            T temp = content[i];
            content[i] = content[size - i - 1];
            content[size - i - 1] = temp;
        }
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T temp = content.front();
        content.erase(content.begin());
        size--;
        return temp;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        return content.front();
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(const PriorityQueue<T> pq){
        for(int i = 0; i < pq.size; i++){
            content.push_back(pq.content[i]);
        }
        size += pq.size;
        sort(content.begin(), content.end());
        for(int i = 0; i < size/2; i++){
            T temp = content[i];
            content[i] = content[size - i - 1];
            content[size - i - 1] = temp;
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize(){
        return size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& stream, PriorityQueue<T> q){
        if(q.size == 0){
            stream << "()" << endl;
        } else{
            stream << "(";
            for(int i = 0; i < q.size; i++){
                stream << q.content[i];
                if(i != q.size - 1){
                    stream << ", ";
                }
            }
            stream << ")" << endl;
        }
        return stream;
    }

};



#endif
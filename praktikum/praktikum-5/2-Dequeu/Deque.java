import java.util.ArrayList;
import java.util.List;

// Class Deque berikut merupakan suatu kelas Generic yang merepresentasikan suatu Deque.
// Deque merupakan suatu struktur data yang mirip dengan Queue, namun Deque memiliki dua ujung, yaitu front dan back.
// Deque disimpan dengan memanfaatkan ArrayList.
// Elemen front pada Deque disimpan pada indeks paling kiri, sedangkan elemen back disimpan pada indeks paling kanan.
public class Deque<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_Deque_SIZE = 500;

  //Constructor dengan size default
  public Deque(){
    lastElmIdx = 0;
    size = DEFAULT_Deque_SIZE;
    data = new ArrayList<T>(DEFAULT_Deque_SIZE);
  }

  //Constructor dengan size = n
  public Deque(int n){
    lastElmIdx = 0;
    size = n;
    data = new ArrayList<T>(n);
  }

  //Copy Constructor dari Deque lain
  public Deque(final Deque<T> q){
    lastElmIdx = q.lastElmIdx;
    size = q.size;
    data = new ArrayList<T>(q.data);
  }

  //Method untuk menambahkan elemen pada ujung front Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushFront(T t) throws Exception{
    if(data.size() < size){
        data.add(0, t);
        lastElmIdx++;
    } else{
        throw new Exception("Deque is full");
    }
  }

  //Method untuk menambahkan elemen pada ujung back Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushBack(T t) throws Exception{
    if(data.size() < size){
        data.add(lastElmIdx, t);
        lastElmIdx++;
    } else{
        throw new Exception("Deque is full");
    }
  }

  //Method untuk menghapus elemen pada ujung front Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popFront() throws Exception{
    if(data.size() > 0){
        lastElmIdx--;
        T temp = data.remove(0);
        return temp;
    } else{
        throw new Exception("Deque is empty");
    }
  }

  //Method untuk menghapus elemen pada ujung back Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popBack() throws Exception{
    if(data.size() > 0){
        lastElmIdx--;
        T temp = data.remove(lastElmIdx);
        return temp;
    } else{
        throw new Exception("Deque is empty");
    }
  }

  //Method untuk membalikkan urutan elemen pada Deque
  public void reverse(){
    List<T> temp = new ArrayList<T>(data);
    try{
        while(true){
            data.remove(0);
        }
    } catch (Exception e){

    }

    for(T elmt : temp){
        data.add(0, elmt);
    }
  }

  //Method untuk mengecek apakah Deque kosong
  public boolean isEmpty(){
    return data.isEmpty();
  }
  
  //Method untuk mengecek apakah Deque penuh
  public boolean isFull(){
    return data.size() == size;
  }

  //Method untuk mendapatkan ukuran Deque
  public int size(){
    return data.size();
  }
}
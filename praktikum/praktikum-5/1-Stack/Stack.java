import java.util.ArrayList;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_STACK_SIZE = 500;


  //Constructor dengan size default
  public Stack(){
    size = DEFAULT_STACK_SIZE;
    lastElmIdx = 0;
    data = new ArrayList<T>(DEFAULT_STACK_SIZE);
  }
  
  public List<T> getData(){
    return data;
  }
  //Constructore dengan size = n
  public Stack(int n){
    size = n;
    lastElmIdx = 0;
    data = new ArrayList<T>(n);
  }

  //Copy constructor dari stack lain
  public Stack(final Stack<T> q){
    size = q.size;
    lastElmIdx = q.lastElmIdx;
    data = new ArrayList<T>(q.data);
  }

  //Tambahkan elemen t ke dalam stack
  //Jika stack penuh, lempar exception "Stack is full"
  public void push(T t) throws Exception{
    if(data.size() < size){
      data.add(t);
      lastElmIdx++;

    } else{
      throw new Exception("Stack is full");
    }
  }

  //Hapus elemen terakhir dari stack
  //Jika stack kosong, lempar exception "Stack is empty"
  public T pop() throws Exception{
    if(data.size() > 0){
      lastElmIdx--;
      T temp = data.remove(lastElmIdx);
      return temp;

    } else{
      throw new Exception("Stack is empty");
    }
  }

  //Cek apakah stack kosong
  public boolean isEmpty(){
    return data.isEmpty();
  }

  //Cek apakah stack penuh
  public boolean isFull(){
    return data.size() == size;
  }
}
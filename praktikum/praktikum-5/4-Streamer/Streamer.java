import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.Collections;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = data;
    }

    // memanggil fungsi consumer untuk setiap elemen dalam stream
    public void forEach(Function<T, Void> consumer) {
        for(T elmt : data){
            consumer.apply(elmt);
        }
    }

    // mengembalikan stream baru yang berisi hasil kembalian fungsi mapper untuk setiap elemen dalam stream
    public <R> IStreamer<R> map(Function<T, R> mapper) {
        List<R> mappedData = data.stream()
                .map(mapper::apply)
                .collect(Collectors.toList());
        return new Streamer<>(mappedData);
    }

    // melakukan filter terhadap elemen dalam stream, jika fungsi predicate mengembalikan true, elemen tersebut akan dimasukkan ke dalam stream baru, jika false, elemen tersebut akan diabaikan
    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        List<T> filteredData = data.stream()
                .filter(predicate::apply)
                .collect(Collectors.toList());
        return new Streamer<>(filteredData);    
    }

    // mengumpulkan semua elemen dalam stream menjadi satu nilai
    // initialValue adalah nilai awal yang akan digunakan dalam proses reduksi
    // reducer adalah fungsi yang akan digunakan dalam proses reduksi
    // reducer merupakan suatu fungsi yang mengembalikan suatu fungsi lain
    // reducer menerima hasil reduksi sampai saat ini dan mengembalikan fungsi yang menerima elemen
    // stream dan mengembalikan hasil reduksi setelah elemen stream tersebut di proses Contoh:
    // stream.reduce(0.0, (Double acc) -> (Double item) -> acc + item);
    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R acc = initialValue;
        for (T item : data) {
            acc = reducer.apply(acc).apply(item);
        }
        return acc;
    }

    // panggil fungsi mapper untuk setiap elemen dalam stream, kemudian gabungkan hasilnya menjadi satu stream baru
    // misalkan stream berisi [1, 2, 3] dan mapper mengembalikan stream baru [1, 2, 3] untuk setiap elemen, maka hasilnya adalah stream baru [1, 2, 3, 1, 2, 3, 1, 2, 3]
    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        List<R> flatMappedData = data.stream()
                .flatMap(item -> mapper.apply(item).collect().stream())
                .collect(Collectors.toList());
        return new Streamer<>(flatMappedData);
    }

    // mengembalikan elemen pertama dalam stream yang memenuhi kondisi dari fungsi predicate
    // jika tidak ada elemen yang memenuhi kondisi, kembalikan null
    public T findFirst(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    // mengembalikan elemen terakhir dalam stream yang memenuhi kondisi dari fungsi predicate
    // jika tidak ada elemen yang memenuhi kondisi, kembalikan null
    public T findLast(Function<T, Boolean> predicate) {
        for (int i = data.size() - 1; i >= 0; i--) {
            T item = data.get(i);
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    // mengembalikan elemen pertama dalam stream
    // jika stream kosong, kembalikan null
    public T head() {
        if (isEmpty()) {
            return null;
        } else {
            return data.get(0);
        }
    }

    // mengembalikan stream baru yang berisi semua elemen dalam stream kecuali elemen pertama
    // jika stream kosong, kembalikan stream kosong
    public IStreamer<T> tail() {
        if (isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(1, data.size()));
    }

    // mengembalikan elemen terakhir dalam stream
    // jika stream kosong, kembalikan null
    public T last() {
    if (isEmpty()) {
        return null;
    } else {
        for (int i = 0; i < count(); i++) {
            if (i == count() - 1) {
                return data.get(i);
            }
        }
        return null;
    }
    }

    // mengembalikan stream baru yang berisi semua elemen dalam stream kecuali elemen terakhir
    // jika stream kosong, kembalikan stream kosong
    public IStreamer<T> init() {
        if (isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(0, data.size() - 1));
    }

    // mengembalikan stream baru yang berisi n elemen pertama dalam stream
    // jika n lebih besar dari jumlah elemen dalam stream, ambil semua elemen dalam stream
    public IStreamer<T> takeFirst(int n) {
        int limit = Math.min(n, count());
        return new Streamer<>(data.subList(0, limit));
    }

    // mengembalikan stream baru yang berisi n elemen terakhir dalam stream
    // contoh: [1, 2, 3, 4, 5].takeLast(3) -> [3, 4, 5]
    // jika n lebih besar dari jumlah elemen dalam stream, ambil semua elemen dalam stream
    public IStreamer<T> takeLast(int n) {
        int startIndex = Math.max(data.size() - n, 0);
        return new Streamer<>(data.subList(startIndex, data.size()));
    }

    // mengembalikan true jika stream kosong, false jika tidak
    public Boolean isEmpty() {
        return count() == 0;
    }

    // mengembalikan jumlah elemen dalam stream
    public Integer count() {
        return data.size();
    }

    // mengembalikan true jika stream mengandung minimal satu elemen yang memenuhi kondisi dari fungsi predicate, false jika tidak
    public Boolean some(Function<T, Boolean> predicate) {
        return data.stream().anyMatch(predicate::apply);
    }

    // mengembalikan true jika semua elemen dalam stream memenuhi kondisi dari fungsi predicate, false jika tidak
    public Boolean every(Function<T, Boolean> predicate) {
        return data.stream().allMatch(predicate::apply);
    }

    // mengembalikan list yang berisi semua elemen dalam stream
    public List<T> collect() {
        return new ArrayList<>(data);
    }

    // membalik urutan elemen dalam stream
    public void reverse() {
        Collections.reverse(data);
    }
}
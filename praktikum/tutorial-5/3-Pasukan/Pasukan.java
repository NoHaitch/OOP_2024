import java.util.*;

public class Pasukan<T extends List<Integer>> {
    private T list;
    private int n;

    public Pasukan(T _list, int _n) {
        list = _list;
        n = _n;
    }

    public void reset() {
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }

    public long get(int idx) {
        reset();

        long start = Util.getTime();
        int elmt = list.get(idx);
        long finish = Util.getTime();

        return finish - start;
    }

    public long del(int idx, int t){
        reset();

        long start = Util.getTime();
        for(int i = 0; i < t; i++){
            list.remove(idx);
        }
        long finish = Util.getTime();

        return finish - start;

    }
}

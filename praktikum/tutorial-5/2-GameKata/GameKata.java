import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> titoMap = new HashMap<>();
        Map<String, Integer> wiwidMap = new HashMap<>();

        for (String word : tito) {
            if (!titoMap.containsKey(word)) {
                titoMap.put(word, 1);
            } else {
                titoMap.put(word, titoMap.get(word) + 1);
            }
        }

        for (String word : wiwid) {
            if (!wiwidMap.containsKey(word)) {
                wiwidMap.put(word, 1);
            } else {
                wiwidMap.put(word, wiwidMap.get(word) + 1);
            }
        }

        for (String word : titoMap.keySet()) {
            if (wiwidMap.containsKey(word)) {
                System.out.println(word);
            }
        }
    }
}
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Creating a streamer with some integer data
        List<Integer> temp = new ArrayList<>();
        Streamer<Integer> streamertemp = new Streamer<>(temp);
        // Testing isEmpty: Checks if the stream is empty
        System.out.println("Testing isEmpty:");
        System.out.println("Stream is empty: " + streamertemp.isEmpty());
        System.out.println();

        temp.add(1);
        temp.add(2);
        temp.add(3);
        temp.add(4);
        temp.add(5);
        temp.add(6);
        temp.add(7);
        temp.add(8);
        temp.add(9);
        temp.add(10);
        Streamer<Integer> streamer = new Streamer<>(temp);
    
        // Testing forEach: Prints each element in the stream
        System.out.println("Testing forEach:");
        streamer.forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println("\n");
    
        // Testing map: Maps each element to a new value
        System.out.println("Testing map:");
        IStreamer<String> mappedStream = streamer.map(s -> "Mapped " + s);
        mappedStream.forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing filter: Filters the stream based on a predicate
        System.out.println("Testing filter:");
        IStreamer<Integer> filteredStream = streamer.filter(s -> s % 2 == 1);
        filteredStream.forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing reduce: Reduces the stream to a single value
        System.out.println("Testing reduce:");
        Integer sum = streamer.reduce(0, acc -> item -> acc + item);
        System.out.println("Sum: " + sum);
        System.out.println();
    
        // Testing flatMap: Maps each element to a new stream and flattens the result
        System.out.println("Testing flatMap:");
        IStreamer<Integer> flattenedStream = streamer.flatMap(s -> new Streamer<>(Arrays.asList(s, s * 2, s * 3)));
        flattenedStream.forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing findFirst: Finds the first element satisfying a predicate
        System.out.println("Testing findFirst:");
        Integer firstEven = streamer.findFirst(s -> s % 2 == 0);
        System.out.println("First even number: " + firstEven);
        System.out.println();
    
        // Testing findLast: Finds the last element satisfying a predicate
        System.out.println("Testing findLast:");
        Integer lastEven = streamer.findLast(s -> s % 2 == 0);
        System.out.println("Last even number: " + lastEven);
        System.out.println();
    
        // Testing head: Gets the first element of the stream
        System.out.println("Testing head:");
        System.out.println("Head: " + streamer.head());
        System.out.println();
    
        // Testing tail: Gets the tail of the stream (all elements except the first)
        System.out.println("Testing tail:");
        streamer.tail().forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing last: Gets the last element of the stream
        System.out.println("Testing last:");
        System.out.println("Last: " + streamer.last());
        System.out.println();
    
        // Testing init: Gets the init of the stream (all elements except the last)
        System.out.println("Testing init:");
        streamer.init().forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing takeFirst: Takes the first n elements of the stream
        System.out.println("Testing takeFirst:");
        streamer.takeFirst(3).forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
        // Testing takeLast: Takes the last n elements of the stream
        System.out.println("Testing takeLast:");
        streamer.takeLast(3).forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
        System.out.println();
    
    
        // Testing count: Gets the count of elements in the stream
        System.out.println("Testing count:");
        System.out.println("Stream count: " + streamer.count());
        System.out.println();
    
        // Testing some: Checks if some elements satisfy a predicate
        System.out.println("Testing some:");
        System.out.println("Some even number exists: " + streamer.some(s -> s % 2 == 0));
        System.out.println();
    
        // Testing every: Checks if all elements satisfy a predicate
        System.out.println("Testing every:");
        System.out.println("All numbers are even: " + streamer.every(s -> s % 2 == 0));
        System.out.println();
    
        // Testing collect: Collects the elements of the stream into a list
        System.out.println("Testing collect:");
        List<Integer> collected = streamer.collect();
        System.out.println("Collected: " + collected);
        System.out.println();
    
        // Testing reverse: Reverses the order of elements in the stream
        System.out.println("Testing reverse:");
        streamer.reverse();
        streamer.forEach(s -> {
            System.out.println(s);
            return null; // Returning null to satisfy the Void return type
        });
    }    
}

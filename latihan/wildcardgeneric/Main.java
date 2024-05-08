import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void printListOfUnknowns(List<?> l) {
        for (Object e : l)
            System.out.println(e);
    }

    public static void printListOfObjects(List<Object> l) {
        for (Object e : l)
            System.out.println(e);
    }

    public static void main(String[] args) {
        List<Object> listString = new ArrayList<>();
        List<?> listUnknown = new ArrayList<String>();

        listString.add("ciko");
        listString.add("bagas");
        listString.add("farhan");
        listString.add(1);
        listString.add(2);
        listString.add(true);

        // listUnknown.add("a");
        // listUnknown.add(1);
        // listUnknown.add(true);
        // listUnknown.add(new Object());

        printListOfObjects(listString);
        // printListOfObjects(listUnknown);

        System.out.println("");

        printListOfUnknowns(listString);
        printListOfUnknowns(listUnknown);
    }
}

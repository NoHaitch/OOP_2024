import java.util.*;

public class Person {
    @JsonField(name = "full_name") private String name;
    @JsonField(serialized = false) private int age;
    private boolean isStudent;
    private String[] hobbies;
    private List<String> friends;
    private Map<String, String> address;
  
    public Person(String name, int age, boolean isStudent, String[] hobbies, List<String> friends, Map<String, String> address) {
      this.name = name;
      this.age = age;
      this.isStudent = isStudent;
      this.hobbies = hobbies;
      this.friends = friends;
      this.address = address;
    }
}
  
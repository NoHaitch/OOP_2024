public class Main {
    public static void main(String[] args) {
        Person person = new Person(
                            "John Doe", 
                            25, 
                            true, 
                            new String[] {"Reading", "Coding"},                   
                            Arrays.asList("Alice", "Bob", "Charlie"),
                            new HashMap<String, String>() {
                                {
                                    put("city", "New York");
                                    put("state", "NY");
                                }
                            });

        JsonLoader jsonLoader = new JsonLoader();
        String json = jsonLoader.serialize(person);
        // {"full_name":"John Doe","isStudent":true,"hobbies":["Reading","Coding"],"friends":["Alice","Bob","Charlie"],"address":{"city":"New York","state":"NY"}}
    }    
}

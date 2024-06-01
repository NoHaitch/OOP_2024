public class House {
    private String color;
    private int floors;
    private int rooms;
    private String owner;
    private String address;
  
    public House(String color, int floors, int rooms, String owner, String address) {
      this.color = color;
      this.floors = floors;
      this.rooms = rooms;
      this.owner = owner;
      this.address = address;
    }
  
    public String toString() {
      return "House{color="+color+",floors="+floors+",rooms="+rooms+",owner="+owner+",address="+address+"}";
    }
  }
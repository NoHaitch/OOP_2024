public class HouseBuilder implements IHouseBuilder {
    private String color = null;
    private int floors = 0;
    private int rooms = 0;
    private String owner = null;
    private String address = null;

    public IHouseBuilder withColor(String color){
        this.color = color;
        return this;
    }

    public IHouseBuilder withFloors(int floors){
        this.floors = floors;
        return this;
    }

    public IHouseBuilder withRooms(int rooms){
        this.rooms = rooms;
        return this;
    }

    public IHouseBuilder withOwner(String owner){
        this.owner = owner;
        return this;
    }
    
    public IHouseBuilder withAddress(String address){
        this.address = address;
        return this;
    }
    
    public House build(){
        return new House(this.color, this.floors, this.rooms, this.owner, this.address);
    }
}

public interface IHouseBuilder {
    public IHouseBuilder withColor(String color);
    public IHouseBuilder withFloors(int floors);
    public IHouseBuilder withRooms(int rooms);
    public IHouseBuilder withOwner(String owner);
    public IHouseBuilder withAddress(String address);
    public House build();
  }
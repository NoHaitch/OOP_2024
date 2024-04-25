public class Strength extends Hero {
    private double nilai = 0.2;

    public Strength(){
        super();
    }

    public Strength(int level){
        super(level);
    }

    public Double value(){
        return level + nilai;
    }

    public void printInfo(){
        System.out.print("Strength Hero (Lvl ");
        System.out.print(level);
        System.out.println(")");
    }
}

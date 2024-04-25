public class Agility extends Hero {
    private double nilai = 0.3;

    public Agility(){
        super();
    }

    public Agility(int level){
        super(level);
    }

    public Double value(){
        return level + nilai;
    }

    public void printInfo(){
        System.out.print("Agility Hero (Lvl ");
        System.out.print(level);
        System.out.println(")");
    }
}

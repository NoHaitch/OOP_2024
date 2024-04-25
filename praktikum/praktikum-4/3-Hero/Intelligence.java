public class Intelligence extends Hero {
    private double nilai = 0.1;

    public Intelligence(){
        super();
    }

    public Intelligence(int level){
        super(level);
    }

    public Double value(){
        return level + nilai;
    }

    public void printInfo(){
        System.out.print("Intelligence Hero (Lvl ");
        System.out.print(level);
        System.out.println(")");
    }
}

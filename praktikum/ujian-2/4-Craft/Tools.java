public abstract class Tools {
    protected int durability;

    public Tools(int durability) {
        this.durability = durability;
    }

    /**
     * Print dengan format "Durability menjadi {durability}"
     */
    public void use(){
        System.out.println("Durability menjadi " + durability);
    }
}
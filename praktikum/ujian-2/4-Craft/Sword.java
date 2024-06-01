public class Sword extends Weapon {
    
    public Sword(int damage) {
        super(damage);
    }

    /**
     * Print dengan format "Mengayun sword", panggil method parent setelahnya
     */
    public void attack() {
        System.out.println("Mengayun sword");
        super.attack();
    }
}
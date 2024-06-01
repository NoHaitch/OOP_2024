public class Axe extends Weapon{

    public Axe(int damage) {
        super(damage);
    }

    /**
     * Print dengan format "Mengayun axe", panggil method parent setelahnya
     */
    public void attack() {
        System.out.println("Mengayun axe");
        super.attack();
    }
}

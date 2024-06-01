public abstract class Weapon {
    private int damage;

    public Weapon(int damage) {
        this.damage = damage;
    }

    /**
     * Print dengan format "Damage yang dilakukan sebesar {damage}"
     */
    public void attack() {
        System.out.println("Damage yang dilakukan sebesar " + damage);
    }
}


/**
 * Exception yang dilempar ketika kontak tidak ditemukan.
 */
public class ContactNotFoundException extends Exception {
    /**
     * Konstruktor untuk ContactNotFoundException.
     * Menciptakan objek ContactNotFoundException dengan pesan default "Kontak tidak ditemukan".
     */
    public ContactNotFoundException() {
        super("Kontak tidak ditemukan");
    }
}

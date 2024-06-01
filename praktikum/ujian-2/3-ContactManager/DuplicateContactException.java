

/**
 * Exception yang dilempar ketika terjadi duplikasi kontak.
 */
public class DuplicateContactException extends Exception {
    /**
     * Konstruktor untuk membuat objek DuplicateContactException.
     * Pesan kesalahan default yang ditampilkan adalah "Kontak sudah ada".
     */
    public DuplicateContactException() {
        super("Kontak sudah ada");
    }
}



/**
 * Exception yang akan dilempar ketika daftar kontak kosong.
 */
public class EmptyContactListException extends Exception {
    /**
     * Konstruktor untuk EmptyContactListException.
     * Menciptakan objek exception dengan pesan "Daftar kontak kosong".
     */
    public EmptyContactListException() {
        super("Daftar kontak kosong");
    }
}

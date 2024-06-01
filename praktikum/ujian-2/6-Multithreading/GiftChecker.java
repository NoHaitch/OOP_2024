

/**
 * Kelas GiftChecker digunakan untuk memeriksa apakah nomor hadiah yang diberikan
 * sesuai dengan nomor hadiah yang diharapkan.
 */
public class GiftChecker {
    private int x;
    private int time;

    /**
     * Konstruktor untuk kelas GiftChecker.
     * 
     * @param x    nomor hadiah yang diharapkan
     * @param time waktu yang diperlukan untuk memeriksa hadiah
     */
    public GiftChecker(int x, int time) {
        this.x = x;
        this.time = time;
    }

    /**
     * Memeriksa apakah nomor hadiah yang diberikan sesuai dengan nomor hadiah yang diharapkan.
     * 
     * @param number nomor hadiah yang diberikan
     * @return true jika nomor hadiah sesuai, false jika tidak
     */
    public boolean checkGift(int number) {
        try {
            Thread.sleep(time);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        if (number == x) {
            return true;
        } else {
            return false;
        }
    }
}
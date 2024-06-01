

/**
 * Kelas MultithreadProgram adalah kelas yang digunakan untuk mencari angka yang sesuai dengan kondisi yang diberikan.
 * Kelas ini menggunakan multithreading untuk melakukan pencarian angka secara paralel.
 * Setelah angka yang sesuai ditemukan, kelas ini akan mencetak angka tersebut ke layar.
 * 
 * Modifikasi kelas ini agar dapat berjalan dengan benar sesuai dengan materi Multithreading.
 * Anda boleh menambahkan atribut dan method lain jika perlu
 * Anda juga boleh memodifikasi method ini jika diperlukan, tetapi jangan mengubah nama method, parameter, dan return value-nya.
 */
public class MultithreadProgram {
    private GiftChecker checker;
    private static final int MAX_THREADS = 8;
    private static final int MAX_NUMBER = 240;
    private volatile boolean found = false;
    public volatile int foundNumber = -1; 


    public MultithreadProgram(GiftChecker checker) {
        this.checker = checker;
    }

    public void setFoundNumber(int number) {
        if (!found && number != -1) {
            found = true;
            this.foundNumber = number;
        }
    }

    public void findCorrectNumber() {
        for (int i = 0; i <= MAX_NUMBER && !found; i += 1) {
            Computer computer = new Computer(checker, i, this);
            computer.run();
            if (found) {
                break;
            }
        }

    }
}
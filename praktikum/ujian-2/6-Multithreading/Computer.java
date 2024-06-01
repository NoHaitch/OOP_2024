/**
 * Kelas Computer mewakili sebuah komputer yang memeriksa apakah sebuah angka tertentu adalah hadiah.
 * Kelas ini mengimplementasikan interface Runnable untuk mendukung multithreading.
 */
class Computer implements Runnable {
    private GiftChecker checker;
    private int numberToCheck;
    private MultithreadProgram controller;
    private int totalThreadNumber = 0;

    /**
     * Membangun objek Computer dengan parameter yang ditentukan.
     *
     * @param checker        objek GiftChecker yang digunakan untuk memeriksa apakah sebuah angka adalah hadiah
     * @param numberToCheck  angka yang akan diperiksa
     * @param controller     objek MultithreadProgram yang mengontrol eksekusi thread
     */
    public Computer(GiftChecker checker, int numberToCheck, MultithreadProgram controller) {
        this.checker = checker;
        this.numberToCheck = numberToCheck;
        this.controller = controller;
    }

    /**
     * Menjalankan thread dan memeriksa apakah angka yang diberikan adalah hadiah.
     * Jika angka adalah hadiah, maka mengatur angka yang ditemukan di dalam controller.
     * Jika angka bukan hadiah, maka mengatur -1 di dalam controller.
     */
    @Override
    public void run() {
        this.totalThreadNumber += 1;
        if (this.totalThreadNumber > 8) {
            System.out.println("Computer error!!!!");
            controller.setFoundNumber(-2);
        } else {
            if (checker.checkGift(numberToCheck)) {
                controller.setFoundNumber(numberToCheck);
            } else {
                controller.setFoundNumber(-1);
            }
            this.totalThreadNumber -= 1;
        }
    }
}
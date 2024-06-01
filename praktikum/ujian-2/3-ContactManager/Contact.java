
/**
 * Mewakili sebuah kontak dengan nama dan nomor telepon.
 */
public class Contact implements Comparable<Contact> {
    private String name;
    private String phoneNumber;

    /**
     * Membangun objek Contact dengan nama dan nomor telepon yang ditentukan.
     *
     * @param name        nama dari kontak
     * @param phoneNumber nomor telepon dari kontak
     */
    public Contact(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    /**
     * Mengembalikan nama dari kontak.
     *
     * @return nama dari kontak
     */
    public String getName() {
        return name;
    }

    /**
     * Mengembalikan nomor telepon dari kontak.
     *
     * @return nomor telepon dari kontak
     */
    public String getPhoneNumber() {
        return phoneNumber;
    }

    /**
     * Mengatur nomor telepon dari kontak.
     *
     * @param phoneNumber nomor telepon baru dari kontak
     */
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /**
     * Membandingkan kontak ini dengan kontak lain berdasarkan nama mereka.
     *
     * @param other kontak yang akan dibandingkan
     * @return bilangan bulat negatif, nol, atau bilangan bulat positif jika kontak ini kurang dari, sama dengan, atau lebih besar dari kontak lainnya
     */
    @Override
    public int compareTo(Contact other) {
        return this.name.compareTo(other.name);
    }
}

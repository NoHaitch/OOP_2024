
import java.util.TreeSet;

/**
 * Kelas ContactManager digunakan untuk mengelola daftar kontak.
 */
public class ContactManager {
    private TreeSet<Contact> contacts;

    /**
     * Konstruktor untuk membuat objek ContactManager baru.
     */
    public ContactManager() {
        this.contacts = new TreeSet<>();
    }

    /**
     * Menambahkan kontak baru ke dalam daftar kontak.
     * 
     * @param contact kontak yang akan ditambahkan
     * @throws DuplicateContactException jika kontak sudah ada dalam daftar kontak. Kontak disebut unik jika tidak ada nama yang sama pada list kontak. Phone number boleh sama.
     */
    public void addContact(Contact contact) throws DuplicateContactException {
        if(!contacts.add(contact)){
            throw new DuplicateContactException();
        }
    }

    /**
     * Menghapus kontak dari daftar berdasarkan nama.
     * 
     * @param name nama kontak yang akan dihapus
     * @throws ContactNotFoundException jika kontak tidak ditemukan dalam daftar kontak
     */
    public void removeContact(String name) throws ContactNotFoundException {
        boolean found = false;
        for(Contact elmt: contacts){
            if(elmt.getName() == name){
                contacts.remove(elmt);
                found = true;
                break;
            }
        }

        if(!found){
            throw new ContactNotFoundException();
        }
    }

    /**
     * Memeriksa apakah daftar kontak kosong.
     * 
     * @return true jika daftar kontak kosong, false jika tidak
     */
    public boolean isEmpty() {
        return contacts.isEmpty();
    }

    /**
     * Mengambil kontak pertama dalam daftar kontak.
     * 
     * @return kontak pertama dalam daftar kontak
     * @throws EmptyContactListException jika daftar kontak kosong
     */
    public Contact getFirstContact() throws EmptyContactListException {
        if(isEmpty()){
            throw new EmptyContactListException();
        }

        return contacts.first();
    }

    /**
     * Menghapus kontak pertama dari daftar kontak dan mengembalikan kontak.
     * 
     * @throws EmptyContactListException jika daftar kontak kosong
     */
    public Contact removeFirstContact() throws EmptyContactListException {
        if(isEmpty()){
            throw new EmptyContactListException();
        }

        Contact firstContact = getFirstContact();

        contacts.remove(firstContact);

        return firstContact;
    }

    /**
     * Menampilkan daftar kontak secara terurut menurun berdasarkan nama (descending).
     * 
     * @throws EmptyContactListException jika daftar kontak kosong.
     * Format print berupa nama: phone_number, jangan lupa akhiri dengan newline
     * Contoh: 
     * Bob: 67890
     * Alice: 67890
     */
    public void displayContactsDescending() throws EmptyContactListException {
        if(isEmpty()){
            throw new EmptyContactListException();
        }

        for(Contact contact : contacts.descendingSet()){
            System.out.println(contact.getName() + ": " + contact.getPhoneNumber());
        }
    }

    /**
     * Menampilkan daftar kontak secara terurut naik berdasarkan nama (ascending).
     * 
     * @throws EmptyContactListException jika daftar kontak kosong
     * Format print berupa nama: phone_number, jangan lupa akhiri dengan newline
     * Contoh: 
     * Alice: 12345
     * Bob: 67890
     */
    public void displayContactsAscending() throws EmptyContactListException {
        if(isEmpty()){
            throw new EmptyContactListException();
        }

        for(Contact contact : contacts){
            System.out.println(contact.getName() + ": " + contact.getPhoneNumber());
        }
    }

    /**
     * Mengembalikan jumlah kontak dalam daftar kontak.
     * 
     * @return jumlah kontak dalam daftar kontak
     */
    public int size() {
        return contacts.size();
    }
}

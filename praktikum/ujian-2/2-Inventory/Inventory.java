import java.util.ArrayList;
import java.util.List;

/**
 * Pastikan kalian menggunakan type parameter yang benar
 */
public class Inventory<T>{
    private List<Box<T>> boxes;

    // Constructor, inisiasi dengan list of boxes
    public Inventory(List<Box<T>> boxes) {
        this.boxes = new ArrayList<>(boxes);
    }

    // Method untuk membuka semua box
    public void openAll() {
        for(Box<T> box : boxes){
            box.open();
        }
    }

    // Method untuk menambahkan box
    public void addBox(Box<T> box) {
        boxes.add(box);
    }

    // Method untuk menghapus box
    public void removeBox(Box<T> box) {
        boxes.remove(box);
    }

    // Getter dan setter
    public List<Box<T>> getBoxes() {
        return boxes;
    }
    
    public void setBoxes(List<Box<T>> boxes) {
        this.boxes = boxes;
    }
    
}
public class Hoe extends Tools {

    public Hoe(int durability){
        super(durability);
    }

    /**
     * Print dengan format "Menggunakan hoe", panggil method parent setelahnya apabila durability cukup. Print "Hoe sudah rusak" apabila durability habis
     */
    public void use(){
        System.out.println("Menggunakan hoe ");
        durability--;
        if(durability != 0){
            super.use();
        } else{
            System.out.println("Hoe sudah rusak");
        }
    }
}

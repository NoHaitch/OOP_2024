public class KoleksiKendaraanMain {
    public static void main(String[] args) {
        KoleksiKendaraan A = new KoleksiKendaraan(5);
        Bus a = new Bus(1, 2000, "ABC", 10);
        Mobil b = new Mobil(2, 2007, "BMW", "budi");
        Minibus c = new Minibus(3, 1998, "MRD");

        A.insert(a);
        A.insert(b);
        A.insert(c);
        
        A.printAll();
        System.out.println();
        
        KoleksiKendaraan B = new KoleksiKendaraan(5);
        B.insert(new Minibus(4, 2011, "AVZ"));
        B.insert(new Mobil(5, 2004, "TYT", "rayhan"));
        B.insert(new Mobil(6, 2005, "HND", "rifki"));
        
        A.insert(B);
        A.printAll();

        System.out.println();
        System.out.println("Biaya sewa 5 bulan: ");
        System.out.println("Bus : " + a.biayaSewa(5));
        System.out.println("Mobil : " + b.biayaSewa(5));
        System.out.println("Minibus : " + c.biayaSewa(5));
        
        System.out.println();
        System.out.println("Biaya sewa 12 bulan: ");
        System.out.println("Bus : " + a.biayaSewa(12));
        System.out.println("Mobil : " + b.biayaSewa(12));
        System.out.println("Minibus : " + c.biayaSewa(12));
        System.out.println("Diskon Minibus : " + c.diskon(12));
    }
}

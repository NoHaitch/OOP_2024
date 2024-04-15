public class Mobil extends Kendaraan {
    private String supir = "XXXX";

    /* CTOR */
    public Mobil(){
        super();
    }

    /* CTOR - User defined */
    public Mobil(String _supir){
        super();
        supir = _supir;
    }

    /* CTOR - User defined */
    public Mobil(int _nomor, int _tahunKeluaran, String _merk, String _supir){
        super(_nomor, _tahunKeluaran, _merk, "mobil");
        supir = _supir;
    }

    /* CCTOR */
    public Mobil(Mobil other){
        this(other.nomor, other.tahunKeluaran, other.merk, other.supir);
    }

    public void printInfo(){
        System.out.println("Nomor: " + nomor);
        System.out.println("Merk: " + merk);
        System.out.println("Kategori: " + kategori);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
        System.out.println("Supir: " + supir);
    }

    public int biayaSewa(int lamaSewa){
        return 500000 * lamaSewa;
    }
}
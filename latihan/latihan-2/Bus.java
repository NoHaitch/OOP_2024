public class Bus extends Kendaraan {
    private int kapasitas = 0;

    /* CTOR */
    public Bus(){
        super();
    }

    /* CTOR - User defined */
    public Bus(int _kapasitas){
        super();
        kapasitas = _kapasitas;
    }

    /* CTOR - User defined */
    public Bus(int _nomor, int _tahunKeluaran, String _merk, int _kapasitas){
        super(_nomor, _tahunKeluaran, _merk, "bus");
        kapasitas = _kapasitas;
    }

    /* CCTOR */
    public Bus(Bus other){
        this(other.nomor, other.tahunKeluaran, other.merk, other.kapasitas);
    }

    public void printInfo(){
        System.out.println("Nomor: " + nomor);
        System.out.println("Merk: " + merk);
        System.out.println("Kategori: " + kategori);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
        System.out.println("Kapasitas: " + kapasitas);
    }

    public int biayaSewa(int lamaSewa){
        return 1000000 * lamaSewa;
    }
}
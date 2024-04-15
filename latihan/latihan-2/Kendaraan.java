public abstract class Kendaraan {
    protected int nomor;
    protected int tahunKeluaran;
    protected String kategori;
    protected String merk;

    /* CTOR */
    public Kendaraan(){
        nomor = 0;
        tahunKeluaran = 0;
        merk = "XXX";
        kategori = "mobil";
    }

    /* CTOR User Defined */
    public Kendaraan(int _nomor, int _tahunKeluaran, String _merk, String _kategori){
        nomor = _nomor;
        tahunKeluaran = _tahunKeluaran;
        merk = _merk;
        kategori = _kategori;
    }

    /* CCTOR */
    public Kendaraan(Kendaraan other){
        this(other.nomor, other.tahunKeluaran, other.merk, other.kategori);
    }

    public void printInfo(){
        System.out.println("Nomor: " + nomor);
        System.out.println("Merk: " + merk);
        System.out.println("Kategori: " + kategori);
        System.out.println("Tahun Keluaran: " + tahunKeluaran);
    }

    abstract int biayaSewa(int lamaSewa);
}
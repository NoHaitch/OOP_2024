public class Minibus extends Kendaraan {
    /* CTOR */
    public Minibus(){
        super();
    }

    /* CTOR - User defined */
    public Minibus(int _nomor, int _tahunKeluaran, String _merk){
        super(_nomor, _tahunKeluaran, _merk, "minibus");
    }

    /* CCTOR */
    public Minibus(Minibus other){
        this(other.nomor, other.tahunKeluaran, other.merk);
    }

    public int biayaSewa(int lamaSewa){
        if(lamaSewa <= 5){
            return 5000000;
        } else{
            return 5000000 + 500000*(lamaSewa-5);
        }
    }

    public int diskon(int lamaSewa){
        if(lamaSewa > 10){
            return biayaSewa(lamaSewa) / 10;
        } else{
            return biayaSewa(lamaSewa);
        }
    }
}
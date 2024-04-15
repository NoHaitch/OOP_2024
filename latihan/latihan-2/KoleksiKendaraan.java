public class KoleksiKendaraan {
    private int size;
    private int nEff;
    private Kendaraan[] koleksi;

    /* CTOR */
    public KoleksiKendaraan(){
        size = 100;
        nEff = 0;
        koleksi = new Kendaraan[size];
    }

    /* CTOR - User Defined */
    public KoleksiKendaraan(int _size){
        size = _size;
        nEff = 0;
        koleksi = new Kendaraan[_size];
    }

    /* CCTOR */
    public KoleksiKendaraan(KoleksiKendaraan other){
        koleksi = new Kendaraan[other.size];
        size = other.size;
        nEff = other.nEff;
        for(int i = 0; i < other.nEff; i++){    
            koleksi[i] = other.koleksi[i];
        }
    }

    public void printAll(){
        for(int i = 0; i < nEff; i++){
            System.out.println("Kendaraan " + (i+1) + ": ");
            koleksi[i].printInfo();
        }
    }

    /* Operator << */
    public void insert(Kendaraan K){
        if(nEff < size){
            koleksi[nEff] = K;
            nEff++;
        } else{
            System.out.println("Koleksi Penuh");
        }
    }

    /* Operator << */
    public void insert(KoleksiKendaraan other){
        for(int i = 0; i < other.nEff; i++){
            if(nEff < size){
                koleksi[nEff] = other.koleksi[i];
                nEff++;
            } else{
                System.out.println("Koleksi sudah Penuh");
                break;
            }
        }
    }
}

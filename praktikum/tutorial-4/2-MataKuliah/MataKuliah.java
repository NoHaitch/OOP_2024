import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    private float rating;

    public MataKuliah(String _nama, int _kodeJurusan, int _tahunPengambilan, float _rating){
        nama = _nama;
        kodeJurusan = _kodeJurusan;
        tahunPengambilan = _tahunPengambilan;
        rating = _rating;
    }

    public String getNama(){
        return nama;
    }

    public int getKodeJurusan(){
        return kodeJurusan;
    }

    public int getTahunPengambilan(){
        return tahunPengambilan;
    }

    public float getRating(){
        return rating;
    }

    public int compareTo(MataKuliah m) {
        // kode jurusan MataKuliah A lebih kecil dari MataKuliah B
        // kode jurusan MataKuliah A sama dengan MataKuliah B, tapi tahun pengambilannya lebih kecil
        // kode jurusan dan tahun pengambilan MataKuliah A sama dengan MataKuliah B, tapi rating nya lebih kecil
        if(kodeJurusan < m.kodeJurusan){
            return -1;

        } else if(kodeJurusan > m.kodeJurusan){
            return 1;

        } else {
            if(tahunPengambilan < m.tahunPengambilan){
                return -1;

            } else if(tahunPengambilan > m.tahunPengambilan){
                return 1;

            } else {
                if(rating < m.rating){
                    return -1;

                } else if(rating > m.rating){
                    return 1;

                } else {
                    return 0;
                }
            }
        }
    }
}
class TempatTinggal{
    private int luas;
    private double hargaBahanBangunan;

    public void setLuas(int _luas){
        luas = _luas;
    }

    public int getLuas(){
        return luas;
    }

    public void setHargaBahanBangunan(double _hargaBahanBangunan){
        hargaBahanBangunan = _hargaBahanBangunan;
    }

    public double getHargaBahanBangunan(){
        return hargaBahanBangunan;
    }

    public double hitungBiayaBangun(){
        return luas * hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal{
    public Rumah(int _luas, double _hargaBahanBangunan){
        super();
        setLuas(_luas);
        setHargaBahanBangunan(_hargaBahanBangunan);
    }

    public Rumah(int lebar, int panjang, double _hargaBahanBangunan){
        super();
        setLuas(lebar * panjang);
        setHargaBahanBangunan(_hargaBahanBangunan);
    }

    public void setLuas(int lebar, int panjang){
        super.setLuas(lebar * panjang);
    }

    public double hitungBiayaBangun(double biayaOrmas){
        return hitungBiayaBangun() + biayaOrmas;
    }
}

interface Kendaraan{
    double hitungJarakTempuh();
}

class Karavan extends Rumah implements Kendaraan{
    private float bensin;
    private float pemakaianBensin;

    public Karavan(){
        super(0,0);
        bensin = 0;
        pemakaianBensin = 0;
    }
    
    public float getBensin(){
        return this.bensin;
    }
    
    public float getPemakaianBensin(){
        return this.pemakaianBensin;
    }
    
    public void setBensin(float _bensin){
        bensin = _bensin;
    }
    
    public void setPemakaianBensin(float _pemakaianBensin){
        pemakaianBensin = _pemakaianBensin;
    }

    public double hitungBiayaBangun(){
        return super.hitungBiayaBangun() * 3;
    }

    public double hitungJarakTempuh(){
        return bensin * pemakaianBensin;
    }
}
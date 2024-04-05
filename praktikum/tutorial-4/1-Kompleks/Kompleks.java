class Kompleks{
    private static int n_kompleks = 0;
    private int real; 
    private int imaginer;

    // ctor tanpa parameter
    // inisialisasi seluruh koefisien dengan nilai 0
    public Kompleks(){
        real = 0;
        imaginer = 0;
        n_kompleks++;
    }

    // ctor dengan parameter
    public Kompleks(int _real, int _imaginer){
        real = _real;
        imaginer = _imaginer;
        n_kompleks++;
    }

    //mengembalikan bagian riil
    public int getReal(){
        return real;
    }
    // mengembalikan bagian imaginer
    public int getImaginer(){
        return imaginer;
    }
    
    // mengisi bagian riil
    public void setReal(int _real){
        real = _real;
    }

    // mengisi bagian imaginer
    public void setImaginer(int _imaginer){
        imaginer = _imaginer;
    }

    // operator+ untuk melakukan penjumlahan dengan rumus berikut
    public Kompleks plus(Kompleks b){
        return new Kompleks(real + b.getReal(), imaginer + b.getImaginer());
    }

    // operator- untuk melakukan pengurangan dengan rumus berikut
    public Kompleks minus(Kompleks b){
        return new Kompleks(real - b.getReal(), imaginer - b.getImaginer());
    }

    // operator* untuk melakukan perkalian dengan rumus berikut
    public Kompleks multiply(Kompleks b){
        return new Kompleks(real * b.getReal() - imaginer * b.getImaginer(), imaginer * b.getReal() + real * b.getImaginer());
    }

    // operator* untuk mengkalikan bilangan kompleks dengan konstanta
    public Kompleks multiply(int k){
        return new Kompleks(real * k, imaginer * k);
    }

    public static int countKompleksInstance(){
        return n_kompleks;
    }

    // mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
    public void print() {
        if (real != 0) {
            System.out.print(real);
        }
    
        if (imaginer > 0 && real != 0) {
            System.out.print("+");
        }
    
        if (imaginer != 0) {
            System.out.print(imaginer + "i");
        }
    
        if (real == 0 && imaginer == 0) {
            System.out.print("0");
        }
    
        System.out.println();
    }
}
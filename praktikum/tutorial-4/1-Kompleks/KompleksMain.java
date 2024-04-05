public class KompleksMain {
    public static void main(String[] args) {
        Kompleks a = new Kompleks(3, 2);
        Kompleks b = new Kompleks(1, -1);
        
        Kompleks sum = a.plus(b);
        System.out.println("Addition result: " + sum.getReal() + " + " + sum.getImaginer() + "i");
        
        Kompleks difference = a.minus(b);
        System.out.println("Subtraction result: " + difference.getReal() + " + " + difference.getImaginer() + "i");
        
        Kompleks product = a.multiply(b);
        System.out.println("Multiplication result: " + product.getReal() + " + " + product.getImaginer() + "i");
        
        Kompleks multiplied = a.multiply(2);
        System.out.println("Multiplication with constant result: " + multiplied.getReal() + " + " + multiplied.getImaginer() + "i");
        
        System.out.println("Total Kompleks instances: " + Kompleks.countKompleksInstance());
        
        System.out.println("Complex numbers:");
        a.print();
        b.print();
        sum.print();
        difference.print();
        product.print();
        multiplied.print();
    }
}

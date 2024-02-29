public class Productor extends Thread {
 
    public Buffer buffer;
    public final String Lasletras = "abcdefghijklmnopqrstuvxyz";
 
    public Productor(Buffer buffer) {
        this.buffer = buffer;
    }
 
    public void run() {
        while (true) {
            char c = Lasletras.charAt((int) (Math.random() * Lasletras.length()));
            buffer.producir(c);
            System.out.println("Depositado el caracter " + c + " del buffer");
            try {
                
                sleep((int) (Math.random() * 4000));
            } catch (InterruptedException e) { }
        }
    }
}
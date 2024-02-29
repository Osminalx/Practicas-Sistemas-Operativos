public class Consumidor extends Thread {
 
    private Buffer buffer;
 
    public Consumidor(Buffer buffer) {
        this.buffer = buffer;
    }
 
    public void run() {
 
        while (true) {
            char valor = buffer.consumir();
            System.out.println("Recogido el caracter " + valor + " del buffer");
            try {
                sleep((int) (Math.random() * 4000));
            } catch (InterruptedException e) { }
        }
    }
}
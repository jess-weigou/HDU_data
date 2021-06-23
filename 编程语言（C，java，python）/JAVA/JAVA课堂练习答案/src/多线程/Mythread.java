package 多线程;

class MyThread extends Thread{
    public void run(){
        System.out.println("MyThread run()");
    }
    public void start(){
        System.out.println("My Thread start(");
    }
}
class MyRunnable implements Runnable{


    public void run() {
        System.out.println("MyRunnable:run()");
    }
    public void start(){
        System.out.println("MyRunnable:start()");
    }
}
public class Mythread {
}

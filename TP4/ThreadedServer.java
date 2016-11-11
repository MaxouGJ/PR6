import java.net.*;
import java.io.*;
import java.util.Random;

public class ThreadedServer {

    static int port = 10201;

    public static void main(String[] args){
        try{
            ServerSocket server=new ServerSocket(port);
            Random rand = new Random();
            int number = rand.nextInt(100) + 1;
            while(true){
                Socket socket=server.accept();
                PlayerService serv=new PlayerService(socket, number);
                Thread t=new Thread(serv);
                t.start();
            }
        } catch(Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
}

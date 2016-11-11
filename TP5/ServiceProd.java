import java.net.*;
import java.io.*;

public class ServiceProd implements Runnable{

    BufferConcurrent bc;
    int port;
    
    public ServiceProd(BufferConcurrent b, int p){
	bc = b;
	port = p;
    }

    public void run(){
	try{
	    ServerSocket server = new ServerSocket(port);
	    Socket socket = server.accept();
	    while(true){
		BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		String m = br.readLine();
		bc.ajouter(m);
		System.out.println("Ajout de : "+m);
	    }
	}catch(Exception e){
	    System.err.println(e);
	    e.printStackTrace();
	}
    }
}

import java.net.*;
import java.io.*;

public class ServiceConso implements Runnable{

    BufferConcurrent bc;
    int port;
    
    public ServiceConso(BufferConcurrent b, int p){
	bc = b;
	port = p;
    }

    public void run(){
	try{
	    ServerSocket server = new ServerSocket(port);
	    Socket socket = server.accept();
	    while(true){
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
		pw.println(bc.retirer());
		pw.flush();
	    }
	}catch(Exception e){
	    System.err.println(e);
	    e.printStackTrace();
	}
    }
}

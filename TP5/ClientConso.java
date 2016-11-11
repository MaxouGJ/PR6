import java.net.*;
import java.io.*;

public class ClientConso{

    public static void main(String[] args){
	try{
	    Socket socket = new Socket("0.0.0.0", 10201);
	    System.out.println("Connexion de consommateur");
	    BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	    while(true){
		System.out.println("Lecture de "+br.readLine());
	    }
	}catch(Exception e){
	    System.err.println("oran");
	    e.printStackTrace();
	}
    }
}

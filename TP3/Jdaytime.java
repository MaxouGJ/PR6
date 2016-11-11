import java.net.Socket;
import java.io.*;

public class Jdaytime{

    public static void main(String argv[]){
	String machine = argv[0];
	int port = 13;
	try {
	    Socket socket = new Socket(machine, port);
	    System.out.println("Port "+port+" ouvert.");
	    BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	    String retour = br.readLine();
	    System.out.println(retour);
	    br.close();
	    socket.close();
	}catch(Exception e){
	    System.out.println("Port "+port+" fermé.");
	    System.err.println(e);
	}
    }
}

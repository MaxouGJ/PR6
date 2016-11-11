import java.net.Socket;
import java.io.*;
import java.util.Scanner;

public class ClientMystere{

    public static void main(String argv[]){
	String machine = argv[0];
	int port = Integer.parseInt(argv[1]);
	Scanner sc = new Scanner(System.in);
	try {
	    Socket socket = new Socket(machine, port);
	    System.out.println("Port "+port+" ouvert.");
	    BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	    PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
	    String retour = br.readLine();
	    System.out.println(retour);
	    boolean trouve = false;
	    while(!trouve){
		pw.println(sc.nextInt());
		pw.flush();
		retour = br.readLine();
		System.out.println(retour);
		if(retour.equals("="))
		    trouve = true;
	    }
	    sc.close();
	    br.close();
	    socket.close();
	}catch(Exception e){
	    System.out.println("Port "+port+" fermé.");
	    System.err.println(e);
	}
    }
}

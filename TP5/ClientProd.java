import java.net.*;
import java.io.*;
import java.util.*;

public class ClientProd{
    
    public static void main(String[] args){
	try{
	    Socket socket = new Socket("0.0.0.0", 10202);
	    System.out.println("Connexion de producteur");
	    Scanner sc = new Scanner(System.in);
	    PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
	    while(true){
		pw.println(sc.nextLine());
		pw.flush();
	    }
	}catch(Exception e){
	    System.err.println("pome");
	    e.printStackTrace();
	}	
    }
}

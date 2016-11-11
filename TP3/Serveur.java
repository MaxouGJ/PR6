import java.net.*;
import java.io.*;

public class Serveur{

    public static void main(String[] args){
	int mystere = (int) (Math.random()*99+1);
	try{
	    ServerSocket serveur = new ServerSocket(4243);
	    while(true){
		Socket socket = serveur.accept();
		BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
		pw.println("Un nombre a été tiré aléatoirement entre 1 et 100. Devinez le !");
		pw.flush();
		boolean trouve = false;
		while(!trouve){
		    String rep = br.readLine();
		    if(Integer.parseInt(rep)>mystere){
			pw.println("-");
			pw.flush();
		    }else if(Integer.parseInt(rep)<mystere){
			pw.println("+");
			pw.flush();
		    }else{
			pw.println("=");
			pw.flush();
			trouve = true;
		    }
		}
		br.close();
		pw.close();
		socket.close();
	    }
	}catch(Exception e){
	    System.err.println(e);
	}
    }
}

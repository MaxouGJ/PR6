import java.net.Socket;

public class Ports{

    public static void main(String argv[]){
	String machine = argv[2];
	int portD = Integer.parseInt(argv[0]);
	int portF = Integer.parseInt(argv[1]);
	Socket s;
	for(int port=portD; port<=portF; port++){
	    try {
		s = new Socket(machine, port);
		System.out.println("Port "+port+" ouvert.");
		s.close();
	    }catch(Exception e){
		System.err.println(e);
		//e.printStackTrace();
	    }
	}
    }
}

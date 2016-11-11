import java.net.*;
import java.io.*;

public class ServerThread{

    static int portConso = 10201;
    static int portProd = 10202;

    public static void main(String[] args){
	try{
	    BufferConcurrent bc = new BufferConcurrent();
	    ServiceConso conso = new ServiceConso(bc, portConso);
	    ServiceProd prod = new ServiceProd(bc, portProd);
	    Thread tconso = new Thread(conso);
	    Thread tprod = new Thread(prod);
	    tconso.start();
	    tprod.start();
	}catch(Exception e){
	    System.err.println(e);
	    e.printStackTrace();
	}
    }
}

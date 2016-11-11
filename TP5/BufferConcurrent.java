import java.util.*;

public class BufferConcurrent{

    public LinkedList<String> list = new LinkedList<String>();

    public synchronized void ajouter(String s){
	list.add(s);
	notifyAll();
    }

    public synchronized String retirer(){
	String s;
	while(list.size() == 0){
	    try {
		wait();
	    }catch(Exception e) {
		System.err.println(e);
		e.printStackTrace();
	    }
	}
	s = list.remove();
	notifyAll();
	return s;
    }
}

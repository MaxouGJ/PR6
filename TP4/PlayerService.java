import java.net.*;
import java.io.*;

public class PlayerService implements Runnable {

    public Socket sock;
    public int number;

    public PlayerService(Socket s, int n){
        this.sock = s;
        this.number = n;
    }

    public void run(){
        try {
            System.out.println("New connection stablished with " +
                    sock.getInetAddress().getHostName() +
                    " (port " + sock.getPort() +
                    "), trying to communicate...");
            BufferedReader comBR = new BufferedReader(
                    new InputStreamReader(
                            sock.getInputStream()));
            PrintWriter comPW = new PrintWriter(
                    new OutputStreamWriter(
                            sock.getOutputStream()));
            int guess = -1;
            System.out.println("The number chosen is " + number + ".");
            String str = "";
            comPW.println("!");
            comPW.flush();
            while (true) {
                System.out.print("Waiting for a guess...");
                str = comBR.readLine();
                System.out.println(" " + str + ".");
                if (str.equals("quit")) break;
                try {
                    guess = Integer.parseInt(str);
                } catch (NumberFormatException nfe) {
                    comPW.println("?");
                    comPW.flush();
                    continue;
                }
                if (guess < number) {
                    comPW.println("+");
                }
                else if (guess > number)
                    comPW.println("-");
                else if (guess == number)
                    break;
                comPW.flush();
            }
            if (guess == number) {
                System.out.println("The guess was correct.");
                comPW.println("=");
            } else if (str.toUpperCase().equals("QUIT")) {
                comPW.println(".");
                comPW.println(number);
                comPW.println("someone");
            } else {
                System.out.println("Bad input.");
                comPW.println("*");
            }
            comPW.flush();
            System.out.println("Closing connection...");
            comBR.close();
            comPW.close();
            sock.close();
            System.out.println("Connection closed.\n");
        } catch (Exception e) {
            System.out.println("Problem with client.\n");
        }
    }
}

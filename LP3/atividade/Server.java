import java.net.*;
import java.io.*;

public class Server{

  public static void main(String[] args) {

      int port = 20001;

      try{
         ServerSocket servSocket = new ServerSocket(port);
         while(true) {
            try {
               Socket server = servSocket.accept();
               //receiving data
               DataInputStream in = new DataInputStream(server.getInputStream());
               //saving data
               String name = in.readUTF();
               String lastname = in.readUTF();
               String inclusionyear = in.readUTF();
               String password = name+"."+lastname+"."+inclusionyear;
               //answer back the password
               DataOutputStream out = new DataOutputStream(server.getOutputStream());
               out.writeUTF(password);
               System.out.println("pass: "+password);
               server.close();

            }catch(SocketTimeoutException s) {
               System.out.println("Socket timed out!");
               break;
            }catch(IOException e) {
               e.printStackTrace();
               break;
            }
         }
      }catch(IOException e){}
  }
}

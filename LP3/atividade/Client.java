import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;

public class Client{

  public static void main(String[] args) {

        String host = "localhost";
        int port = 20001;
        try {
           Socket client = new Socket(host, port);
           //write to server
           OutputStream outToServer = client.getOutputStream();
           DataOutputStream out = new DataOutputStream(outToServer);
           //get information
           String name = JOptionPane.showInputDialog("Tell your name: ");
           String lastname = JOptionPane.showInputDialog("Tell your last name: ");
           String inclusionyear = JOptionPane.showInputDialog("Tell your inclusion year: ");
           //send to server
           out.writeUTF(name);
           out.writeUTF(lastname);
           out.writeUTF(inclusionyear);
           //read from server
           InputStream inFromServer = client.getInputStream();
           DataInputStream in = new DataInputStream(inFromServer);
           JOptionPane.showMessageDialog(null, "Your password: " + in.readUTF());
           client.close();

        }catch(IOException e) {
           e.printStackTrace();
        }
  }
}

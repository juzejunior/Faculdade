package controller;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

import javax.swing.JOptionPane;

public class Client {

	
	public static void main(String[] args) throws Exception
	{	
		//int number1, number2, totalPairs;
        String question;
            
		Socket clientSocket = new Socket("localhost",12345);
		
		while(true)
		{
			DataOutputStream outToServer =new DataOutputStream(clientSocket.getOutputStream());
			DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());
			//get the user input
			question = JOptionPane.showInputDialog("Type your Question below: ");
			//send to the server the numbers
			outToServer.writeUTF(question);
			//get the response fom server
		        String answerFromServer = inFromServer.readUTF();
			//show the answer
		    JOptionPane.showMessageDialog(null, "Bot Says: "+ answerFromServer);
		    //while the user digit a positive number continue to process
			if(question.equals("") || question == null) break;
		}
		
		clientSocket.close();
	}
	
}

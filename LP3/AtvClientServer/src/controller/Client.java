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
		int number1, number2, totalPairs;
		//BufferedReader inFromUser =	new BufferedReader(new InputStreamReader(System.in));
		
		Socket clientSocket = new Socket("localhost",2027);
		
		while(true)
		{
			DataOutputStream outToServer =new DataOutputStream(clientSocket.getOutputStream());
			DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());
			//get the user input
			number1 = Integer.parseInt(JOptionPane.showInputDialog("Type a number: "));
			number2 = Integer.parseInt(JOptionPane.showInputDialog("Type another number: "));
			//send to the server the numbers
			outToServer.writeInt(number1);
			outToServer.writeInt(number2);
			//get the total of pairs from server response
		    totalPairs = inFromServer.readInt();
			//show the answer
		    JOptionPane.showMessageDialog(null, "Pairs total: "+totalPairs);
		    //while the user digit a positive number continue to process
			if(number1 < 0 && number2 < 0) break;
		}
		
		clientSocket.close();
	}
	
}

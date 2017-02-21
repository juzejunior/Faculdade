package controller;

import java.awt.PageAttributes;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.SocketException;

import javax.swing.JOptionPane;

public class Answer {

	String serverAnswer;
	//input
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	 
	//answer back
	synchronized public boolean giveAnswer(Socket client) throws IOException
	{
		try
		{
			//prepare the input and output streams
			DataInputStream inFromClient = new DataInputStream(client.getInputStream());
			DataOutputStream outToClient = new DataOutputStream(client.getOutputStream());
			//get client numbers
			int numberA = inFromClient.readInt();
			int numberB = inFromClient.readInt();
			//show waht you got
			JOptionPane.showMessageDialog(null, "Client Says: "+ numberA + " "+numberB);
			// if client wants to out type a negative number 
			if (numberA < 0 || numberB < 0) return false;
			//verify the biggest and lowest number
			int biggerNumber, lowerNumber, pairsNumber, cont;
			if(numberA > numberB){
				biggerNumber = numberA;
				lowerNumber = numberB;
			} else{
				biggerNumber = numberB;
				lowerNumber = numberA;
			}
			
			cont = 1;
			pairsNumber = 0;
			//count the number of pairs between the numbers
			for(int i = lowerNumber+1; i < biggerNumber; i++, cont++)
			{
				if(cont % 2 == 0){
					pairsNumber += 1;			
				}
			}
			//write back the total of pairs between to the server
			outToClient.writeInt(pairsNumber);
			return true;
		}
		catch(SocketException ex)
		{
			System.out.println("desconnected");
			return false;
		}
		
	}
}

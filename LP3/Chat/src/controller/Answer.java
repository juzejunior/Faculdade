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
			//get client question
			String clientQuestion = inFromClient.readUTF();
			//System.out.println("Client says:" + clientQuestion);
                        //client question 
                        JOptionPane.showMessageDialog(null, "Client says: "+ clientQuestion);
			// if client send a null message or empty 
			if (clientQuestion.equals("") || clientQuestion == null) return false;
			//get the answer
                        String answerToClient = JOptionPane.showInputDialog("Answer: ");
			//write back the answer to the client
			outToClient.writeUTF(answerToClient);
			return true;
		}
		catch(SocketException ex)
		{
			System.out.println("desconnected");
			return false;
		}
		
	}
}

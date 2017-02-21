package controller;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server extends Thread{

	public static void main(String[] args) {
		try
		{
			int port = 2027;
			System.out.println("Init the server...");
			//init our server
			ServerSocket server = new ServerSocket(port);
			System.out.println("Waiting for connections...");
			//class to answer back the client
			Answer ans = new Answer();
			//wait connections
			while(true){
				Socket client = server.accept();
				//create a new thread to the new client
				Thread t = new Thread(new ServerThread(ans, client));
				//start the thread
				t.start();
			}
		}
		catch(Exception io)
		{
			System.out.println("Exception: "+ io);
		}
	}
}

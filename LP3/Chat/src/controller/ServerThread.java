package controller;

import java.io.IOException;
import java.net.Socket;

public class ServerThread implements Runnable {

	Answer answer;
	Socket client;
	
	public ServerThread(Answer ans, Socket client) {
		// TODO Auto-generated constructor stub
		this.answer = ans;
		this.client = client;
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			while(answer.giveAnswer(client))
			{
				try{
					Thread.sleep(5000);
				}
				catch(InterruptedException it)
				{
					
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try{
			this.client.close();
		}catch(IOException ex){
			
		}
	}	
	
}

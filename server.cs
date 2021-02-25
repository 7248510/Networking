//https://docs.microsoft.com/en-us/dotnet/framework/network-programming/synchronous-server-socket-example
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
//csc server.cs && server
public class server {
    //Incoming data from client
    public static string data = null; //empty by default
    public static void Listen() { 
        byte[] bytes = new Byte[1024]; //Declaring a new array and allocating 1024 bytes for the incoming data
        //Establish the local endpoint
        //DNS.GetHostName return the name of teh host running the application.
        IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
        Console.WriteLine("Listing host's IP addresses:"); 
        for (int i = 0; i < ipHostInfo.AddressList.Length; i++) { 
            Console.WriteLine(ipHostInfo.AddressList[i]); 
        }
        
    }



public static int Main(String[] args) {  
        Listen();  
        return 0;  
    } 






}
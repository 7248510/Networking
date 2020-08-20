//I guess you need a ; after imports, different from Python and C++ :(
//import java.net;
import java.net.*;
import java.io.*;
//There's no point in echo as the variable name, I think it's more confusing since the tutorial doesn't come with an echo server(You probably build one)
//Removed from system variables "C:\Program Files (x86)\Common Files\Oracle\Java\javapath" To get Java 14 to work
//So far I haven't had any luck with Java's socket tutorial, I'll continue with the Client Server model, or go to another tutorial/read the JDK 14 docs...
//java echo echoserver.example.com 7 succesfully passes the cli, but I don't think example.com has a sub domain :(
//javac echo.java
//import java.net.ServerSocket; //Getting the serversocket class from java.net
public class echo {
    public static void main(String args[]) {
    String hostName = args[0];
    int portNumber = Integer.parseInt(args[1]);
    try {
        Socket testSocket = new Socket(hostName, portNumber);
        PrintWriter out = new PrintWriter(testSocket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(testSocket.getInputStream()));
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        System.out.print(testSocket); //Displays Socket[addr=/10.0.1.4,port=80,localport=25826]
        System.out.print(out);
        }
    catch (Exception e) { //e is from W3 schools, I'm not sure what it means yet.
            System.out.print("Socket failed\nPrinting Exception\n");
            System.out.print(e);
        }
    }
}
/*
Running the program repededly against my IIS server relayed no results in the logs even though I entered 80 as my port number.
However analyzing traffic in Wireshark revealed that the program was indeed working!
The TCP Src Port: 25948 was the same as localport(Loopback adapter) value which was different every time(Wireshark)
The PrintWriter value @378bf509 was exactly the same everytime, I couldn't find this value in Wireshark
*/
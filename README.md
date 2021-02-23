# Networking
Computer networking programs. This repository is unorganized. I was troubleshooting Boost's libraries on Windows 
# Compiling and using boost asio
launch an elevated command prompt(I did this it is not in the documentation)

bootstrap
b2
b2 runtime-link=static (to get Asio and Regex to generate) The following may be redundant I do not know if the first statement is necessary(I compiled the files multiple times)
output:
The Boost C++ Libraries were successfully built!

The following directory should be added to compiler include paths:

    C:\boost_1_75_0

The following directory should be added to linker library paths:

    C:\boost_1_75_0\stage\lib
/*
cl /EHsc -D_WIN32_WINNT=0x0601 /I C:\boost_1_75_0\ client.cpp /link /LIBPATH:C:\boost_1_75_0\stage\lib
cl /EHsc /I C:\boost_1_75_0\ client.cpp /link /LIBPATH:C:\boost_1_75_0\stage\lib

cl /EHsc /I C:\boost_1_75_0 client.cpp   ^
     /link /LIBPATH:C:\boost_1_75_0\stage\lib
https://stackoverflow.com/questions/20077059/missing-boost-library
https://stackoverflow.com/questions/9751271/how-to-build-boost-static-libs
https://stackoverflow.com/questions/6014517/whats-the-difference-between-mt-gd-and-mt-s-library
libboost_regex-vc142-mt-s-x32-1_75.lib The library missing is static
cl /EHsc /I C:\boost_1_75_0 client.cpp /link /LIBPATH:C:\boost_1_75_0\stage\lib

https://stackoverflow.com/questions/6014517/whats-the-difference-between-mt-gd-and-mt-s-library
Soma Holiday "b2 runtime-link=static"
cl /EHsc /I C:\boost_1_75_0\ client.cpp /link /LIBPATH:C:\boost_1_75_0\stage\lib
*/
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    //std::string line;
    //boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );
    boost::asio::io_context io;
      boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
        t.wait();
        std::cout << "Hello, world!" << std::endl;

  return 0;
/*
    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
    */
}
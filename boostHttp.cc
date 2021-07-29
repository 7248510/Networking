//A simple example sending some data to a tcp server(python example)
#include <boost/asio.hpp>
#include <iostream>
#include <typeinfo>
//cl /EHsc /I C:\boost_1_75_0\ -D _WIN32_WINNT=0x0601 boostHttp.cc /link /LIBPATH:C:\boost_1_75_0\stage\lib
//https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/reference/basic_stream_socket/write_some/overload1.html
//https://stackoverflow.com/questions/40525615/sending-data-from-a-boost-asio-client
int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context };
  boost::asio::ip::tcp::socket socket{ io_context };
  std::string response;
  try {
    auto endpoints = resolver.resolve("127.0.0.1", "3000"); //Node server
    const auto connected_endpoint = boost::asio::connect(socket, endpoints);
    socket.write_some(boost::asio::buffer("GET / HTTP/1.0\r\n\r\n", 50));
    std::cout <<"Connected to: " << connected_endpoint << '\n';
    boost::system::error_code errorCode;
    boost::asio::read(socket, boost::asio::dynamic_buffer(response), errorCode);
    std::cout << response;
  } catch(boost::system::system_error& se) {
    std::cerr << "Error: " << se.what() << std::endl;
  }
}

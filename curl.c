#include <stdio.h>
#include <curl/curl.h>
//https://curl.se/libcurl/c/http3.html
//LibCurl on windows
//Download the library with vcpkg
//copy the library located in packages
//place the folder in a convenient location
//compile the program
//Place the neccessary dll's in the project location
//In my case I need the libcurl.dll It's located in the libcurl bin
//cl /W4 /sdl /EHsc /I curl/include curl.c /link curl/lib/libcurl.lib && curl.exe
int main(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
 
    /* Forcing HTTP/3 will make the connection fail if the server isn't
       accessible over QUIC + HTTP/3 on the given host and port.
       Consider using CURLOPT_ALTSVC instead! */
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_3);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

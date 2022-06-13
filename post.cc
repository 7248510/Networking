// Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <curl/curl.h>

//https://curl.se/libcurl/c/http-post.html

class postRequest {
    private:
        int track{ 0 };


    public:
        CURL* curl;
        CURLcode res;


        int post(std::string url, std::string port = "") {
            std::string complete = url;
            if (port.empty()) {
               
            }
            else {
                complete = url + ":" + port + "/";
            }
            std::cout << complete;
            auto passURL = complete.c_str();
            //CURL* curl;
            //CURLcode res;
            curl_global_init(CURL_GLOBAL_ALL); //init winsock

            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, passURL);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=ImplantTest");

                /* Perform the request, res will get the return code */
                res = curl_easy_perform(curl);
                /* Check for errors */
                if (res != CURLE_OK) {
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                    track=  -1;                   
                }
                else
                    track = 1;
            }
            //curl_easy_cleanup(curl);
            return track;
        }
        ~postRequest() {
            curl_easy_cleanup(curl);
        }
};

class CurlError : public std::exception {
    public:
        std::string negativeVal() {
            std::string possibleSolutions{ "Please check the url/ip\nIs the port valid?" };
            return possibleSolutions;
        }
};



int main()
{
    try {
        postRequest testMe;
        if (testMe.post("http://localhost", "805") == -1) {
            throw CurlError();
        };
    }
    catch (CurlError e) {
        std::cout << "Exception occured\n";
        std::cout << e.negativeVal();
    }
}

/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: reisen
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstddef>
//#include <curl/curl.h>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/format.hpp>
#include <regex>
// main shit
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "usage: " << argv[0] << " <input url>" " <input file> <output file>" "<output format>" << std::endl;
		return (1);
	}


#ifdef __linux__
	char* url = argv[1];
	char* filename = argv[2];
	char* output = argv[3];
	char* format = argv[4];
	char ffmpeg[4096];
	std::string url2 = url;
	char urlString[256];

	if (url2.rfind("https://",0) == 0){
		std::cout << "valid url" << std::endl;
		strcpy(urlString,url); //no need to concat a good url
	}
	else {
		std::cout << "Invalid url concating https://" << std::endl;
		std::string url = "https://" + url2;
		strcpy(urlString,url.c_str());
	}

//TODO fucking add an if else to this shit

		snprintf(ffmpeg, 4096, "ffmpeg -i %s -i %s -c:v copy -c:a copy -y %s.%s", urlString, filename, output, format);
		system(ffmpeg);

	return (0);


//TODO: we aint gonna target windows any time soon
//windows shit
#elif _WIN32
	char* url = argv[1];
	char* filename = argv[2];
	char* output = argv[3];
	char* format = argv[4];
	char ffmpeg[256];
	snprintf(ffmpeg, 256, "ffmpeg.exe -i %s -i %s %s.%s", url, filename, output, format);
	system(weed);
	return 0;
#endif

}




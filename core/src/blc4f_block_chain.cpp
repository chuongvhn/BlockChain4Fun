#include "blc4f_block_chain.h"

#include <curl/curl.h>
#include <openssl/sha.h>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>


#include <iostream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <iosfwd>
#include <fstream>
#include <ostream>
#include <memory>
#include <utility>

//using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

std::string TestSha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
	return ss.str();
}


void TestCppRest() {
	auto fileStream = std::make_shared<ostream>();

	// Open stream to output file.
	pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
	{
		*fileStream = outFile;

		// Create http_client to send the request.
		http_client client(U("http://www.bing.com/"));

		// Build request URI and start the request.
		uri_builder builder(U("/search"));
		builder.append_query(U("q"), U("cpprestsdk github"));
		return client.request(methods::GET, builder.to_string());
	})

		// Handle response headers arriving.
		.then([=](http_response response)
	{
		printf("Received response status code:%u\n", response.status_code());

		// Write response body into the file.
		return response.body().read_to_end(fileStream->streambuf());
	})

		// Close the file stream.
		.then([=](size_t)
	{
		return fileStream->close();
	});

	// Wait for all the outstanding I/O to complete and handle any exceptions
	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

}

void TestCurl() {

	std::string hash;
	std::cout << "Hello World- BlockChain4Fun\n";
	CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

}


blc4f::Blc4fBlockChain::Blc4fBlockChain()
{
}

blc4f::Blc4fBlockChain::~Blc4fBlockChain()
{
}

void blc4f::Blc4fBlockChain::CreateBlock(std::string previous_hash, std::string proof)
{
}

std::string blc4f::Blc4fBlockChain::Hashing(Blc4fBlockChain block)
{
	return std::string();
}

#include "blc4f_block_chain.h"

#include <curl/curl.h>
#include <openssl/sha.h>


#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string sha256Test(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void CurlTest() {

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

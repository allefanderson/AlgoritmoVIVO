#include <iostream>
#include <string>
#include <curl/curl.h>
#include <stdio.h>
#include<json-c/json.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    	((std::string*)userp)->append((char*)contents, size * nmemb);
    	return size * nmemb;
}

void type(std::string rec){

    	struct json_object *parsed_json;
    	struct json_object *Type;
		parsed_json = json_tokener_parse(rec.c_str());
		json_object_object_get_ex(parsed_json, "Type", &Type);
		printf("Type: %s\n", json_object_get_string(Type));

}

void parse( std::string reciver) {

        //std::cout << reciver;

        struct json_object *parsed_json;
        struct json_object *Title;
        struct json_object *Year;
        struct json_object *Rated;
        struct json_object *Released;
        struct json_object *Runtime;
        struct json_object *Genre;
        struct json_object *Director;
        struct json_object *Writer;
        struct json_object *Actors;
        struct json_object *Plot;
        struct json_object *Language;
        struct json_object *Country;
        struct json_object *Awards;
        struct json_object *Poster;
        struct json_object *Ratings;
        struct json_object *Type;
        struct json_object *DVD;
        struct json_object *BoxOffice;
        struct json_object *Production;
        struct json_object *Website;

        parsed_json = json_tokener_parse(reciver.c_str());

        json_object_object_get_ex(parsed_json, "Title", &Title);
        json_object_object_get_ex(parsed_json, "Year", &Year);
        json_object_object_get_ex(parsed_json, "Rated", &Rated);
        json_object_object_get_ex(parsed_json, "Released", &Released);
        json_object_object_get_ex(parsed_json, "Runtime", &Runtime);
        json_object_object_get_ex(parsed_json, "Genre", &Genre);
        json_object_object_get_ex(parsed_json, "Director", &Director);
        json_object_object_get_ex(parsed_json, "Writer", &Writer);
        json_object_object_get_ex(parsed_json, "Actors", &Actors);
        json_object_object_get_ex(parsed_json, "Plot", &Plot);
        json_object_object_get_ex(parsed_json, "Language", &Language);
        json_object_object_get_ex(parsed_json, "Country", &Country);
        json_object_object_get_ex(parsed_json, "Awards", &Awards);
        json_object_object_get_ex(parsed_json, "Poster", &Poster);
        json_object_object_get_ex(parsed_json, "Ratings", &Ratings);
        json_object_object_get_ex(parsed_json, "Type", &Type);
        json_object_object_get_ex(parsed_json, "DVD", &DVD);
        json_object_object_get_ex(parsed_json, "BoxOffice", &BoxOffice);
        json_object_object_get_ex(parsed_json, "Production", &Production);
        json_object_object_get_ex(parsed_json, "Website", &Website);

        printf("Title: %s\n", json_object_get_string(Title));
        printf("Year: %s\n", json_object_get_string(Year));
        printf("Rated: %s\n", json_object_get_string(Rated));
        printf("Released: %s\n", json_object_get_string(Released));
        printf("Runtime: %s\n", json_object_get_string(Runtime));
        printf("Genre: %s\n", json_object_get_string(Genre));
        printf("Director: %s\n", json_object_get_string(Director));
        printf("Writer: %s\n", json_object_get_string(Writer));
        printf("Actors: %s\n", json_object_get_string(Actors));
        printf("Plot: %s\n", json_object_get_string(Plot));
        printf("Language: %s\n", json_object_get_string(Language));
        printf("Country: %s\n", json_object_get_string(Country));
        printf("Awards: %s\n", json_object_get_string(Awards));
        printf("Poster: %s\n", json_object_get_string(Poster));
        printf("Ratings: %s\n", json_object_get_string(Ratings));
        printf("Type: %s\n", json_object_get_string(Type));
        printf("DVD: %s\n", json_object_get_string(DVD));
        printf("BoxOffice: %s\n", json_object_get_string(BoxOffice));
        printf("Production: %s\n", json_object_get_string(Production));
        printf("Website: %s\n", json_object_get_string(Website));
}

int movie(int aux) {

     using namespace std;
     string s1;
     cout << "Nome do Filme: ";
     getline (cin, s1);
     int k = 0;

        for(k=0; k<50; k++){
        if(s1[k] == ' '){
        s1[k] = '+';
        }
          }
    std::string url;
    url = "http://www.omdbapi.com/?t="+s1+"&apikey=f1614455";

  	CURL *curl;
  	CURLcode res;
  	std::string readBuffer;
  	curl = curl_easy_init();
  	if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

//  std::cout << readBuffer;
        if(aux == 1){
        type(readBuffer);
        }else{
        parse(readBuffer);
        }
  }

    return 0;
}

int main(int argc, char* argv[]){

for(int i=0; i<argc; i++){
//      std:: cout<<"\nAgumento "<<i<<" :"<<argv[i];
        	if(std::string(argv[i]) == "--help"){
        	std::cout<<"\n--type: Retorna o tipo media selecionado\n--search: Busca pelo título da media\n\n ";
        	}
        
        	if(std::string(argv[i]) == "--search"){
        	movie(0);
        	}

        	if(std::string(argv[i]) == "--type"){
        	movie(1);
        	}
	}
}


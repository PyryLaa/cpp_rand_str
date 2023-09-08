#include <iostream>
#include <string>
#include <fstream>

#define MAX_STR_LENGTH 20

std::string create_str();

int main(){
  srand(time(0));
  std::ifstream str_file_in;
  std::ofstream str_file_out;
  std::string rand_str = create_str();
  
  str_file_in.open("str_file.txt", std::ifstream::in);
  
  
  if (str_file_in){
    std::string check_string;
    while(!str_file_in.eof()){
      str_file_in >> check_string;
      while(check_string == rand_str){
	rand_str = create_str();
      }
    }

  }else{
    std::cout << "File cannot be opened" << std::endl;
  }
  str_file_in.close();

  str_file_out.open("str_file.txt", std::ofstream::app);

  if(str_file_out){

    str_file_out << rand_str << std::endl;
    std::cout << rand_str << std::endl;  
  }
  str_file_out.close();
  
  return EXIT_SUCCESS;
}

std::string create_str(){
 
  std::string str = "";
  char characters [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0'};
  for (int i = 0; i < MAX_STR_LENGTH; i++){
    int j = rand() % std::size(characters) - 1;
    str.push_back(characters[j]);
  }
  return str;
  
}

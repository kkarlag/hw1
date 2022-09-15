/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"
#include <string>


int main(int argc, char* argv[])
{
  //empty list--> call push back and call pop back 
  //after call push front and call pop front. 
  //^^^ show that those functions work with empty lists
  //now fill in with push back, push front and pop back. to show normal scenario
  //do scenario with more than 10 elements and do push back and front
  //lastly do edge cases for pop back and pop front. 
  ULListStr dat;

  dat.push_back("7");

  string x= dat.get(0);
  cout<< "Expected:7"<< endl;
  cout << x << endl;
  cout<< "Expected:7,7"<< endl;
  cout<< dat.front()<<","<< dat.back()<< endl; 
  dat.pop_back(); 
  dat.push_front("8");
  string y= dat.get(0);
  cout<< "Expected:8" << endl;
  cout << y << endl; 
  cout<< "Expected:8,8"<< endl;
  cout<< dat.front()<< ","<< dat.back()<< endl;
  dat.pop_front(); 
  cout<< "Expected size: 0"<< endl;
  cout<< dat.size()<< endl;
  //^^^^show that the four functions work with empty lists
  cout<<"Expected:";
  for(int i=1; i<10; i++)
  {
    cout<< " "<< i <<" ";
  }
  cout<<" "<< "1"<< " ";
  cout<< endl; 

  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("1"); //shows it can handle more then 9 elements because makes another node
  
  for(int i=0; i<10; i++)
  {
    string z=dat.get(i);
    cout<< " "<<z<< " ";
  }
  
  cout<< endl; 
  dat.pop_back(); //edge case--> deleting a last element--> deleting node
  dat.pop_front(); 

  cout<<"Expected:";
  cout<<" "<< 1<< " ";
  for(int i=9; i>0; i--)
  {
    cout<< " "<< i<<" ";
  }
  cout<< endl;

  dat.push_front("1");
  dat.push_front("2");
  dat.push_front("3");
  dat.push_front("4");
  dat.push_front("5");
  dat.push_front("6");
  dat.push_front("7");
  dat.push_front("8");
  dat.push_front("9");
  dat.push_front("1");
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  dat.pop_back();
  for(int i=0; i<10; i++)
  {
    string n=dat.get(i);
    cout<< " "<<n<<" ";
  }
  cout<< endl; 
  cout<< "Expected size: 10"<< endl;
  cout<< dat.size()<< endl;
  
    return 0;
}

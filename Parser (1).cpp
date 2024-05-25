#include <iostream>
#include <vector>
#include "Parser.h"
using namespace std;

Parser::Parser(string f_name){
file.open(f_name);
if (file.is_open()){
  string s;   
  getline(file,s,' '); 
  Vertex=stoi(s);
  getline(file,s,'\n'); 
  Edges=stoi(s);
  for(int j=0;j<Edges;j++){
   A.push_back(vector<int>());
   getline(file,s,' '); 
   A.back().push_back(stoi(s));
   getline(file,s,'\n'); 
   A.back().push_back(stoi(s));
}
}
else 
  cout<<"Error:file is close"<<endl;
 
 /* for(int j=0;j<Edges;j++){
    for(int i=0;i<2;i++)
      cout<<A[j][i]<<" ";
      cout<<endl;
  }
  */
}

Parser::~Parser(){
file.close();
A.clear();
}

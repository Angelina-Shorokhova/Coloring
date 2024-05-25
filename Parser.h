#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
using namespace std;

class Parser{
protected:
ifstream file;
public:   
int Vertex, Edges;
vector <vector <int>> A;
Parser(string f_name);

~Parser();
 
};

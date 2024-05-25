#include "Parser.h"
#include <iostream>
#include <ctime>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solver: public  Parser{
    vector <int> color;
    vector <vector <int>> degree;
    vector <int> color_vec;
    public:
    void set_degree();
    void set_color();
    int end();
    int neighbour(int i,int j);
    int neighbour_all(int i);
    Solver(string f_name);
    
    
};
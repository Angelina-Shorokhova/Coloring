#include "Solver.h"
#include <iostream>
using namespace std;


   
    
      void Solver::set_degree(){
        for(int j=0;j<Vertex;j++){
        degree.push_back(vector<int>());
        degree.back().push_back(j);
        degree.back().push_back(0);
        }
        int i=0;
        for(int j=0;j<Edges;j++){
            degree[A[j][0]][1]+=1;
            degree[A[j][1]][1]+=1;
        }
        return;
    }
    void Solver::set_color(){
        for(int j=0;j<Vertex;j++){
        color.push_back(0);
        }
        return;
    }
    
    int Solver::end(){
        for(int t=0;t<Vertex;t++){
          if(color[t]==0) return 0;}
        return 1;
    }
    int Solver::neighbour(int i,int j){
        for(int t=0;t<Edges;t++){
          if(((A[t][1]==j)&&(A[t][0]==i))||((A[t][1]==i)&&(A[t][0]==j))) return 1;}
        return 0;
    }
    
    int Solver::neighbour_all(int j){
        for(int i=0; i<color_vec.size();i++)
         if (neighbour(j,color_vec[i])) return 1;
        return 0;
    }
    
    
    Solver::Solver(string f_name): Parser(f_name){
    set_degree();
    
  /*  for(int j=0;j<Edges;j++){
    for(int i=0;i<2;i++)
      cout<<A[j][i]<<" ";
      cout<<endl;
    }
     for(int j=0;j<Vertex;j++){
      cout<<degree[j][0]<<" "<<degree[j][1];
      cout<<endl;
     } 
     */
    sort(degree.begin(), degree.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
  return a[1] > b[1];
});

/*  cout<<"After sorting"<<endl;
  for(int j=0;j<Vertex;j++){
      cout<<degree[j][0]<<" "<<degree[j][1];
      cout<<endl;
     }
  */
    set_color();
  //  cout<<neighbour(2,11)<<" "<<neighbour(0,2)<<" "<<neighbour(16,0)<<endl;
    int K=1;
    int q;
    while (!end()){
    for(int y=0;y<Vertex;y++){
     q=degree[y][0];
    // cout<<"q "<<q<<endl;
      if((color[q]==0)&&(neighbour_all(q)==0)){
     //  cout<<color[q]<<" "<<neighbour_all(q)<<" param1"<<endl;
       color[q]=K;
       color_vec.push_back(q);
    //   cout<<color[q]<<" "<<neighbour_all(q)<<" param2"<<endl;
     /*  for(int i=0; i<color_vec.size();i++)
       cout<<color_vec[i]<<" ";
       cout<<endl;
       cout<<"end"<<endl; */
      }
      //else cout<<color[q]<<" "<<neighbour_all(q)<<" param"<<endl;
      
      }
    K++;
    color_vec.clear();
   // cout<<"K= "<<K<<endl;
    }
    
    for(int j=0;j<Vertex;j++)
    cout<<color[j]<<" ";
    cout<<endl;
    
    }

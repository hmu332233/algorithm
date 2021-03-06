﻿#include <iostream>
#include <list> 
     
using namespace std;
     
     
int matrix[101][101];
int visited[101];
int weight[101][101];
int tree[101];
    
int deleteMin(int Q[] , int d[], int n);
     
     
int main()
{
    int n, m;
        
    cin >> n >> m;
        
    //초기화 
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            matrix[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    int x,y,w;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y >> w;
            
        matrix[x-1][y-1] = 1;
        //matrix[y-1][x-1] = 1;
            
        weight[x-1][y-1] = w;
        //weight[y-1][x-1] = w;
                      
    } 
     
    /*
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        
    cout << endl;
        
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }*/
       
    int s ,e;
       
    cin >> s >> e;
        
    int Q[n];// set에 포함되지 못한 아이들 
        
    for( int i = 0 ; i < n ; i++)
        Q[i] = 1;
        
        
    int d[n];
    for(int i = 0 ; i < n ; i++) 
        d[i] = 99999;
            
    d[s-1] = 0;
   
    //나는 어디에서 왔어 
    int prev[n];
    int u;
       
    for(int i = 0 ; i < n ; i++)
        prev[i] = 0;
       
       
    while( 1 )
    {
        int sw = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if( Q[i] == 1 ) sw = 1;
        }
        if( sw == 0 ) break;
                
                
        u = deleteMin(Q,d,n);
            
        //cout << u + 1 << " ";
           
        if( u == -1 )
            break;
           
           
        for( int i = 0 ; i < n ; i++)
            if( matrix[u][i] == 1  )
            {
                if( Q[i] == 1 && d[u] + weight[u][i] < d[i] )
                {
                    d[i] = d[u] + weight[u][i];
                    prev[i] = u+1;
                }
            }
    }
   /*
    for( int i = 0 ; i < n ; i++)
    {
        cout<<d[i]<< " ";
    }
      
   cout << endl;*/
       
       /*
    for( int i = 0 ; i < n ; i++)
    {
        cout<<prev[i]<< " ";
    }
       
    if( u == -1 ) cout << "Impossible";
    else cout << d[e-1];*/
    
     for(int i=0;i<n;i++) cout << prev[i] << " ";
	 if(d[e-1]!=99999) cout << d[e-1];
	 else cout<<"Impossible";
     
}
//최소 가중치 리 턴  
int deleteMin(int Q[] , int d[], int n)
{
    int min = 999;
    int x = -1;
    //최소값  
    for( int i = 0 ; i <= n ; i++ )
    {
        if( Q[i] == 1)
            if( d[i] < min )
            {
                min = d[i];
                x = i;
            } 
    }
    //Q에서 삭제 
    Q[x] = 0;
        
    return x; 
}

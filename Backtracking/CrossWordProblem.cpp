#include<iostream>
using namespace std;
#define n 10
int findempty(char **board,int &row,int &col,int &rowE,int &colE,vector<int> &occupied,bool &rowOriented)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='-')
            {
                row=i;
                col=j;
                int len=getLength(board,row,col,rowE,colE,occupied,rowOriented);
                return len;
            }
        }
    }
    return 0;
}
int getLength(char **board,int &row,int &col,int &rowE,int &colE,vector<int> &occupied,bool &rowOriented)
{
    //search in row;


    if(board[row][col-1]!='+')
    {
        occupied.push_back(col-1);
        col--;
    }
    colE=col;
    for(int i=col+1;i<n;i++)
    {
        if(board[row][i]!='+')
        {
            if(board[row][i]!='-')
            {
                occupied.push_back(i);
            }
            colE++;
        }
        else
        {
            break;
        }
    }

    if(colE>col)
    {
        rowOriented=true;
        return colE-col+1;
    }
    if(board[row-1][col]!='+')
    {
        occupied.push_back(row-1);
        row--;
    }
    rowE=row;
    for(int i=row+1;i<n;i++)
    {
        if(board[i][col]!='+')
        {
            if(board[i][col]!='-')
            {
                occupied.push_back(i);
            }
            rowE++;
        }
        else
        {
            break;
        }
    }

    rowOriented=false;
    return rowE-row+1;


}
bool crossWord(char **board,string * arr)
{
      int row=-1,col=-1;
      int rowE,colE;
      bool rowOriented;
      vector<int> occupied;
      int len=findempty(board,row,col,rowE,colE,occupied,rowOriented);
      if(len==0)
      {
          return true;
      }
      for(int i=0;i<arr.size();i++)
      {
          if(arr[i]==len)
          {
              //search if any word is filled or not
              if(rowOriented)
              {
                  for(int j=0;j<occupied.size();j++)
                  {
                      if(board[row][occupied[j]]!=arr[i][occupied[j]-col])
                      {
                          goto next_iter:
                      }
                  }

                  for(int j=col;j<=colE;j++)
                  {
                      board[row][j]=arr[i][j-col];

                  }

              }
              else
              {
                  for(int j=0;j<occupied.size();j++)
                  {
                      if(board[occupied[j]][col]!=arr[i][occupied[j]-row])
                      {
                          goto next_iter:
                      }
                  }

                  for(int j=row;j<=rowE;j++)
                  {
                      board[j][col]=arr[i][j-row];

                  }
              }
              if(crossWord(board,arr))
              {
                  return true;
              }
              if(rowOriented)
              {

              }
              else
              {

              }

          }
          next_iter:
              continue;
      }


      return false;
}
int main()
{
    char **board=new char*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new char[n];
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }
    string arr[6]={""};
    string k;
    int i=0;
    cin>>k;
    for(int j=0;j<k.size();j++)
    {
        if(k[i]==';')
        {
            i++;
            continue;
        }
        arr[i]+=k[j];

    }
    crossWord(board,arr);
}

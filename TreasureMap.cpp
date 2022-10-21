//Treasure MAp Game 
#include <iostream>
using namespace std;

bool limit(const int mapsize, int row, int column)
{
bool status=true;
if(row<1||row>mapsize||column>mapsize||column<1)
{
  status=false;
}
else
return status;
}

void treasure(int mapsize,int& row, int& column)
{
  while(row>mapsize||column>mapsize||row<1||column<1)
  {
    if(row<1||row>mapsize||column<1||column>mapsize)
      {
      cout<<"Coordinates must be between 1 and "<<mapsize<<".\n";
      cout<<"Update location of treasure: ";
      cin>>row>>column;
      }
    }
}

bool treasure_direction(char direction, const int mapsize,int& row, int& column, int unit_number)
{
  bool status=true;
  do{
    int north=row-unit_number;
    int south=row+unit_number;
    int east=column+unit_number;
    int west=column-unit_number;

     if(direction=='N'&&north>=1)
   {
   row=north;
   return status;
   }
   else if (direction=='S'&&south<=mapsize)
   {
    row=south;
    return status;
   }
   else if (direction=='E'&&east<=mapsize)
   {
     column=east;
     return status;
   }
   else if(direction=='W'&&west>=1)
   {
     column=west;
     return status;
   }
   else
   {
   cout<<"Treasure cannot go beyond limit\n";
   cout<<"2) Shift X (N,S,E,W) and unit number\n";
   cin>>direction>>unit_number;
   status=false;
  }
}
  while(limit(mapsize, row, column)==true);
}

void drawmap( int mapsize, int row, int column)
{
for(int k=1;k<mapsize+1;k++)
{
cout<<"  "<<k;
}
cout<<endl;
for(int i=1;i<mapsize+1;i++)
  {
    cout<<i;
    for(int j=1;j<mapsize+1;j++)
    {
    if(i==row&&j==column)
    {
      cout<<" x ";
    }
    else
    {
      cout<<" - ";
    }
  }
  cout<<endl;
  }
}

int main()
{
 int option_input;
 int mapsize;
 int row;
 int column;

cout<<"Treasure Map"<<endl<<"-----------"<<endl;

do{
cout<<"Enter a number between 5 and 9 inclusive: ";
cin>>mapsize;

if(mapsize<5||mapsize>9)
  {
    cout<<"Invalid map size\n";
  }
}
while(mapsize<5||mapsize>9);
cout<<endl;

cout<<"Map size set to "<<mapsize<<". "<<endl<<"\n";
cout<<"Initial location of treasure (row/column): ";
cin>>row>>column;
cout<<endl;

treasure(mapsize,row,column);
drawmap(mapsize,row,column);
cout<<endl;

int unit_number=0;
char direction;

do
{
  cout<<"1) Update treasure coordinates (row/column)\n";
  cout<<"2) Shift X (N,S,E,W) and unit number\n";
  cout<<"3) Exit program'\n";
  cout<<"Select Option 1, 2 or 3: ";
  cin>>option_input;

switch(option_input)
{
  case 1:
  cout<<"1) Update treasure coordinates (row/column)\n";
  cin>>row>>column;
  treasure(mapsize,row,column);
  drawmap(mapsize,row,column);
  break;

  case 2:
  cout<<"2) Shift X (N,S,E,W) and unit number\n";
  cin>>direction>>unit_number;
  limit(mapsize,row,column);
  treasure_direction(direction,mapsize,row,column,unit_number);
  drawmap(mapsize,row,column);
  break;

  case 3:
  cout<<"Exiting program";
  break;
  }
}
while(option_input!=3);

  return 0;
}

#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <string>
#include <items.h>

//enum containerIndex {no_container,body,chest,container_size};

struct container : public item
{
  invItem* inv[3][3];
   
  void InitialiseInv();

  invItem* GetInv();

  int AddItem(item* i);
  void ReplaceItem(int x, int y,item* i);
  
  item* RemoveItem(int x, int y);
 
  item* GetItem(int x,int y);
 
  container() : item (99,"None"," ",0,0,false)
    {
      InitialiseInv();
    };
  
  container(int i, std::string n, const char* s, int col, int val,bool lootable) : item(99,n,s,col,val,lootable)
    {
      InitialiseInv();
    };

};

struct area : public container
{
  item* inv[3][3];
  
  void InitialiseInv();

  item* GetInv();

  int AddItem(item* i);
  void ReplaceItem(int x, int y,item* i);
  
  item* RemoveItem(int x, int y);
 
  item* GetItem();
  item* GetItem(int x, int y);

  area(int i, std::string n, const char* s, int col, int val,bool lootable) : container(i,n,s,col,val,lootable)
    {
      InitialiseInv();
    };  
};

item* ToItem(invItem* i);
invItem* ToInvItem(item* i);

/*
  const container container_library[container_size]=
  {
  // {id}{Name(12 cha)}{Symbol}{Col}{Val}{Lootable}
  {0,  "None"      , " ",    0,   0,   false},
  {1,  "Dead Body" , "X",    1,   0,   true}, 
  {2,  "Chest"     , "C",    2,   0,   true}, 
  };
*/

#endif

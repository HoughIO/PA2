#include <cstdlib>
#include <iostream>
#include <ctime>
#include "hougheditor.h"

using namespace std;

//----------------------------------------------
//              Editor Members
//----------------------------------------------

Editor::~Editor() {
	link *current,*temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

struct Editor::link* Editor::initLink(string s, int i) {
	struct link *ptr = new link;
 
	if( ptr == NULL )                         
		return static_cast<struct link *>(NULL);  
	else {  
		ptr->name = s ;  
		ptr->id = i;                        
		return ptr;                         
	}
}

void Editor::addLink( struct link *newLink )  {
	if( head == NULL ) {
		head = newLink;  
		tail = newLink;
	}

	tail->next = newLink;       
	newLink->next = NULL;       
	tail = newLink;               
}

void Editor::insertLink( struct link *newlink ) {
   struct link *temp, *prev;                

   if( head == NULL ) {         
       head = newlink;                        
       tail = newlink;
       head->next = NULL;                        
       return;                                             
   }

   temp = head;                             
					    
   while( temp->name < newlink->name) {	    
          temp = temp->next;                
          if( temp == NULL )                
              break;
   }					    
					    
					             
   if( temp == head ) {		    	    
      newlink->next = head;                 
      head = newlink;                       
   }
   else {				    
      prev = head;		    	    
      while( prev->next != temp ) {	
          prev = prev->next;	    	    
      }
      prev->next = newlink;                 
      newlink->next = temp;
      if( tail == prev )		    
         tail = newlink;		    
   }
}

struct Editor::link* Editor::searchId(struct link* ptr, int id) {
    while( id != ptr->id ) {    
       ptr = ptr->next;                          
       if( ptr == NULL )                          
          break;                                  
    }
    return ptr; 	
}

void Editor::deleteLink( struct Editor::link *ptr )
{
  struct link *temp, *prev;
   temp = ptr;    
   prev = head;       

   if( temp == prev ) {                   
       head = head->next;                 
       if( tail == temp )                 
          tail = tail->next;              
       delete temp ;                      
   }
   else {                                 
       while( prev->next != temp ) {      
           prev = prev->next;             
       }
       prev->next = temp->next;           
       if( tail == temp )                 
           tail = prev;                   
      delete temp;                         
   }
}

void Editor::menuHelp(){
	cout << "-----------------------------------------------------------";
	cout << "	Welcome to my text editor.";
	cout << "	To insert text at the end of the file, type a line and press enter.";
	cout << "	To insert text at a certain line number, type \'I\'";
	cout << "	followed by a space and the desired line number.";
	cout << "	To delete a line, type \'D\' followed by a space and the line number.";
	cout << "	To print all the lines, type \'L\' and press enter.";
	cout << "	To exit, type \'E\' and press enter.";
	cout << "	To display this introduction, type \'H\' and press enter.";
	cout << "-----------------------------------------------------------";
	return;
}

void Editor::deleteList( struct link *ptr )
{
   struct link *temp;

   if( head == NULL ) return;   	

   if( ptr == head ) {			
       head = NULL;			
       tail = NULL;			        
   }
   else {
       temp = head;			   
       while( temp->next != ptr )       
           temp = temp->next;
       tail = temp;                     
   }

   while( ptr != NULL ) {		   
      temp = ptr->next;			   
      delete ptr;			  
      ptr = temp;			  
   }
}

void Editor::displayLink( struct Editor::link *ptr ) const
{
	cout << ptr->id << ": " << ptr->name << endl;
}

bool Editor::checkFile(string fname){
	std::ifstream infile(fname);
	return infile.good();	
}

void Editor::fileOpen(string fname){
	

}

void Editor::insertText(int number){

}

void Editor::delLine(int number){

}

void Editor::listLine(int number){

}

void Editor::menuList(){

}

void Editor::quitSave(){

}
int main(int argc, char *argv[]){
	cout << argc <<endl;
	menuHelp();
}

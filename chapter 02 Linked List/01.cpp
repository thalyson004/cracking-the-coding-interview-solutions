/*
   Question: Write code to remove duplicates from an unsorted linked list.

   FOLLOW UP
   How would you solve this problem if a temporary buffer is not allowed?

   My approach:
      Using a extra unordered_map as hash map to store the uniques values
      Iterate though the linked list and delete node with repetitive values.
*/

#include <iostream>
#include <time.h>
#include <unordered_set>

struct simple_node{
   simple_node *next;
   int val;

   simple_node(){
      next=nullptr;
      val=0;
   }

   simple_node(int _val){
      next=nullptr;
      val=_val;
   }

};


void print(simple_node *actual){
   if(actual==nullptr){
      printf("\n");
      return ;
   }
   printf("%d->", actual->val);
   print(actual->next);
}

void remove_duplicates(simple_node *head){
   if(head==nullptr)return ;

   std::unordered_set<int> uniques;
   simple_node *last = head;
   uniques.insert(last->val);
   head = head->next;
   while(head!=nullptr){
      bool need_delete = true;
      if(uniques.count(head->val)==0){
         last->next = head;
         last=head;
         uniques.insert(head->val);
         false;
      }
      if(need_delete){
         simple_node *cur = head;
         head = head->next;
         delete cur;
      }
   }

   last->next = nullptr;
}

int main(){
   srand( time(NULL) );
   simple_node *head;

   head = new simple_node(0);
   simple_node *cur = head;
   for(int i = 0; i < 5; i++){
      cur -> next = new simple_node( rand()%3 );
      cur = cur->next;
   }

   print(head);

   remove_duplicates(head);

   print(head);
}

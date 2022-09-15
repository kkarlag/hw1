#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
  if(head_==NULL)
  {
    head_= new Item();
    head_->val[0]=val;
    head_->prev=NULL;
    head_->next=NULL;
    head_-> first=0; 
    head_-> last= 1; 
    tail_=head_;
  }
  else if(tail_->last == 10) //if box is full and making new one
  {
    Item* box= new Item();// new Item() box; 
    box->val[0]=val;
    tail_->next=box;
    box->prev= tail_; //connect to tail
    box->next= NULL; //nothing behind
    tail_=box; //tail points to new item now
    //need to give last and first values (so they can be updated later )
    tail_->first=0; 
    tail_->last=1;
  }
  else if(tail_->last<10) //theres space 
  {
     tail_->val[tail_->last]=val;
     tail_->last++;
  }
    //empty--> front of new node //only one node?
  
  size_++; 
}

void ULListStr::push_front(const std::string& val){
  if(head_==NULL) //empty
  {
    head_=new Item();
    head_->val[9]=val;
    head_->prev=NULL;
    head_->next=NULL; 
    head_->first=9; 
    head_->last=10;  
    tail_=head_;
  }
  else if(head_->first !=0) //normal insertion, theres space for val
  {
    head_->val[head_->first-1]=val;
    head_->first--;
  }
  else if(head_->first ==0 && size_>0)
  {
    Item* box= new Item();
    box->val[9]=val;
    head_->prev=box; 
    box->next=head_; //connect to head
    box->prev= NULL; //nothing in front
    head_= box; //head now points to new item

    //need to give last and first values
    head_->first=9; 
    head_->last=10;  
  }
  size_++; 
}

void ULListStr::pop_back()
{
  //removing last item from tail
  if(size_==0)//empty list
  {
    return;
  }
  if((tail_->last)-(tail_->first)<=1)
  {
    if(head_==tail_)//only one left in the node--> delete the whole node
    {  
      head_=nullptr;
      delete tail_;
      tail_=NULL;
    }
    else //just deleting tail and moving to prev
    {
      Item* temp= tail_;
      tail_=tail_->prev;
      delete temp;
      tail_->next=NULL;
    }
  }
  else if((tail_->last)-(tail_->first)>1)//normal case 
  { 
    tail_->last--; 
  }
  size_--;
}

void ULListStr::pop_front() 
{
  if(size_==0) //empty list
  {
    return;
  }
  if((head_->last)-(head_->first)<=1)//last element in node, need to delete node and reconnect
  {
    if(head_==tail_)//only one node, delete node
    {
      head_=NULL;
      delete tail_;
      tail_=NULL;
     
    }
    else //deleting head and making next the head
    {
      Item* temp=head_;
      head_=head_->next;
      delete temp; 
      head_->prev=NULL;
    }
  }
  else if((head_->last)-(head_->first)>1)
  {
     head_->first++;
  }
  size_--;
}
/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const//????no idea if thsi is right
{
  return tail_->val[tail_->last-1]; 
}
/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}
/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(head_== NULL)
  {
    return NULL;
  }
  if(size_==0) //empty list
  {
    return NULL;
  }
  if(loc>size_) //index not in the size if its bigger
  {
    return NULL;
  }
  Item* temp_ =head_;
  while((temp_->last)-(temp_->first)<=loc)
  {
    loc-= temp_->last-temp_->first;
    temp_=temp_->next;
  }
  return &temp_->val[temp_->first+loc]; 
  }


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
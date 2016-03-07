#include<iostream>
#include<iomanip>

using namespace std; 

template<class s>                                
class stackType
{
   public:
          stackType(int length);

          void push(const s& newItem);

          void pop();
          
          void dispTop();
          
          void disp();

          bool isEmpty() const;

          void ifEmpty();

      private:
          int top;
          int lengthOfArray;
          s *array;

     
};
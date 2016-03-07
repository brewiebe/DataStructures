//stack using template to create generic structure
#include <iostream>
#include <iomanip>

using namespace std; 

template<class s>                                
class stackType
{
      private:
          int top;
          int lengthOfArray;
          s *array;

      public:
          stackType(int length)
          {
              if (length <= 0) 
                lengthOfArray = 50;
              else 
                lengthOfArray = length;
              top=-1;
              array = new s[lengthOfArray];
          }

          void push(const s& newItem)
          {
              if(top==lengthOfArray)
                  cout<<"overflow"<<endl;
              else
              {
                  top++;
                  array[top] = newItem;
              }
          }

          void pop()
          {                
            top--;
          }
          
          void dispTop()
          {
            cout << "top of array: " << array[top] << endl;
          }
          
          void disp()
          {
               for(int i=top; i>=0; i--)
               {
                     cout<<array[i]<<'\t';
               }
                cout<<endl;
          }

          bool isEmpty() const {
            return (top == -1);
          }

          void ifEmpty() {
            if(isEmpty())
              cout << "Array is empty now." << endl;
            else
              cout << "There is still an element in the array" << endl;
          }
};
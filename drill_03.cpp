#include "std_lib_facilities.h" 
  int main() 
  {
      cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
      string first_name;
      cin >> first_name; 
      cout << "Dear " << first_name << ",\n";
      cout << "\tHow are you?\n";
      cout << "I'm fine.\n";
      cout << "This is letter.\n";
      string friend_name;
      cout << "Enter your friends name: ";
      cin >> friend_name;
      cout << "Have you seen " << friend_name << " lately?" << endl;
      char friend_sex = 0;
      cout << "Enter your friends gender (m = male | f = female) :";
      cin >> friend_sex;
      if(friend_sex=='m')
      {
        cout << "If you see " << friend_name <<" please ask him to call me." << endl;
      }
      else if(friend_sex=='f')
      {
        cout << "If you see " << friend_name <<" please ask her to call me." << endl;
      }
      int age;
      cout << "Enter your friend age: ";
      cin >> age;
      if(age>=110 || age<=0)
      {
        simple_error("you're kidding!");
      }
      else
      {
        cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
      }
      if(age<12)
      {
        cout << "Next year you will be " << age+1 << "." << endl;
      }
      else if(age==17)
      {
        cout << "Next year you will be able to vote."<< endl;
      }
      else if(age>70)
      {
        cout << "I hope you are enjoying retirement."<< endl;
      }
      cout <<"Yours sincerely"<< endl;
      cout << endl;
      cout <<"justoneguy01"<< endl;
    
    return 0;
    
    }

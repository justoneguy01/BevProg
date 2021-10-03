//part 1
#include "std_lib_facilities.h" 
	
	int main()
	{
		char s;
		while(s!='|')
		{
			double a;
			double b;
		
			cout <<"Type the value of a = ";
			
			cin >> a;
			
			cout << "Type the value of b = ";
			
			cin >> b;
			
			cout << endl;
			
			if(a>b)
			{
				cout << "the smaller value is: "<< b << endl;
				
				cout << "the larger value is: "<< a << endl;
			}
			
			else if(b>a)
			{
				cout << "the smaller value is: "<< a << endl;
				
				cout << "the larger value is: "<< b << endl;
			}
			
			else if(b==a)
			{
				cout << "the numbers are equal"<< endl;
			}
			
			if((b-a)<=100 && (b-a)>0 || (a-b)<=100 && (a-b)>0)
			{
				cout << "the numbers are almost equal"<< endl;
			}
			
			cout << endl;
			
			cout << "Will you exit? Type '|' this to exit." << endl;
			
			cin >> s;
		}
		
		return 0;
	}
//end

//part 2

#include "std_lib_facilities.h" 
	
	int main()
	{
		char s;
		
		vector<double> v;

        vector<double> v_meter;

		double value;

        string unit;

		double sum=0;

		int i =0;

		while(s!='|')
		{
			bool logic=false;

			int trying = 0;
			
			cout << "Type a number: ";

			cin >> value;
        	do 
        	{
				if(trying > 0)
				{
					cout << "Try again" << endl;
				}

				cout << "Type an acceptable unit: (m/cm/in/ft): \t";

				cin >> unit;

				if(unit== "cm" ||unit == "m" ||unit == "in" ||unit == "ft")
				{
				logic = true;
				}
				else
				{
				logic = false;
				} 

				trying=trying+1;

        	}while(logic != true);
		    
			if(unit=="cm")
			{
				double temp = value/100;

				v_meter.push_back(temp);
			}
			else if(unit=="m")
			{
				v_meter.push_back(value);
			}
			else if(unit=="in")
			{
				double temp = (value*2.54)/100;

				v_meter.push_back(temp);
			}
			else if(unit=="ft")
			{
				double temp = ((value*12)*2.54)/100;

				v_meter.push_back(temp);
			}

			v.push_back(value); 

            int max=0;

			for(int i = 0; i < v.size(); i++)
			{
				if(max<v[i])
				{
					max=v[i];
				}
			}

			int min=max;

			for(int i = 0; i < v.size(); i++)
			{
				if(min>v[i])
				{
					min=v[i];
				}
			}

			cout << min <<" The smallest so far"<< endl;

			cout << max <<" The largest so far"<< endl;
				
			sum = sum + v_meter[i];

			i++;
			
            cout << "Summed values in meter: " << sum << " m"<< endl;

			cout << "Will you exit? Type '|' this to exit." << endl;
			
			cin >> s;
		
		}
    	sort(v_meter);
			
		for(int i = 0; i < v_meter.size(); i++)
		{
		cout << "Sorted Vector: " << v_meter[i] << " m" << endl;
		}

		return 0;
    }	
//end

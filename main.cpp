#include<iostream>
using namespace std;

class angle //angle class definition.
{
	private:
    int *degrees;//pointer to store data mebers of class dynamically.
    float *minutes;
    char *direction;
    
    public:
    angle(): degrees(NULL), minutes(NULL), direction(NULL){}//default constructor setting data members to NULL as they are pointers.
        
	angle(int deg, float min, char dir)//Parametrized constructor which will accept argument from object.
	   {
		       degrees = new int (deg);//dynamically allocating degree.
               minutes = new float (min);//dynamically allocating minute.
               direction = new char (dir);//dynamically allocating char.
		}
				
	angle(const angle& obj)//copy constructor creates a deep copy of an angle object by dynamically allocating memory for 
	                       //each member variable and copying the values from the original object to the new object.
	   {
		       degrees = new int (*obj.degrees);// copy obj data members are also dynamically allocated.
               minutes = new float (*obj.minutes);
               direction = new char (*obj.direction);
		}
			
	~angle() //Destructor will call when dynamically allocated data members are deleted.
	{
                delete degrees;
                delete minutes;
                delete direction;
        }	
        
                               
    void display() const 
	{     //-90° represent the South Pole and +90° degrees represents the North Pole.
	  if (*degrees >= -90 && *degrees <= 90)//Any Valid angle in (degree) fall within this range-> -90°≤latitude≤+90°.   
	  {
        cout<< "Angle: " << *degrees <<"\xF8 " << *minutes << "' ";//display degree and minutes.
        
        if (*direction =='N'|| *direction =='n' ||*direction =='S' || *direction == 's')//further check for directions.
		{
            cout<< *direction <<" Latitude";//above both condition true display latitude.
        } 
		else //else case will be executed.
		{
            cout<<"Invalid direction!";
        }
    } 
        //-180 degrees represents the Prime Meridian, a reference line passing through Greenwich, England.
        //+180 degrees represents the International Date Line, a line of longitude on the opposite side of the Earth 
		//from the Prime Meridian.
	  else if (*degrees >= -180 && *degrees <= 180)//therfore any valid angle value falls within this range: -180° ≤ longitude ≤ +180°.
	  { 
        cout<< "Angle: " << *degrees <<"\xF8 " << *minutes <<"' ";//display degree and minutes.
        
        if (*direction =='E'|| *direction == 'e' ||*direction =='W' ||*direction == 'w')//further check for directions.
		{
            cout<<*direction<<" Longitude";//above both condition true display longitude.
        } 
		else //else case will be executed.
		{
            cout<<"Invalid direction!";
        }
    } 
	  else // Why Invalid angle occurs ?
	  { 
        cout<<"Invalid angle! ";
        
        if (*direction == 'E' ||*direction == 'e' ||*direction == 'W' ||*direction == 'w') 
		{
            cout<<"Longitude must between -180° and 180° degrees.";
        } 
		else if (*direction == 'N' ||*direction == 'n' ||*direction == 'S' ||*direction == 's') 
		{
            cout<<"Latitude must between -90° and 90° degrees.";
        } 
		else 
		{
            cout<<"Invalid direction!";
        }
    }
    cout<<endl;
}

};

    angle *dynamicalling_allocating(int deg, float min, char dir)//Function will allocate the object of class dynamically.
   {
	return new angle(deg,min,dir);// return obj dynamically allocated.
    }

int main(){
    int degr;
	float mint;
	char direct, choice;

	do //within a loop allow user to enter.
	{
        cout<<"Enter the degree: ";//Prompt user to enter degree.
        cin >> degr;
        cout<<"Enter the minutes: ";//Prompt user to enter minute.
        cin >> mint;
        cout << "Enter the directions ( N, S, E, W ) : ";//Prompt user to enter direction. N for 'North',S for 'South', E for 'East',W for 'West'
        cin >> direct;

        if (degr >= -180 && degr <= +180)//the degree must between 0 and 180 if condition correct then check nested conditions 
		  {
		  	if(mint >= 0 && mint < 60)//now minutes enter must be between 0 and 60
		  	  	{// condition check for directions.
		  	    if(direct =='N'||direct =='n'|| direct =='S' ||direct =='s'|| direct == 'E'||direct== 'e'||direct =='W'|| direct=='w')
			     	{
		          // if all conditions are true then
                   angle *A1 = dynamicalling_allocating(degr, mint, direct);//pass all 3 value to parametrized constructor. 
                   
                      A1->display();//call display function
                      delete A1;//deleted dynamically allocated object.
			       	}
             else //else of direction.
			 {
                  cout<<"Invalid direction! Please enter valid Direction (N, S, E, W)."<<endl;
             }
            } 
			else //else of minutes.
			{
                  cout<<"Invalid minutes! Please enter valid Minutes (0-59)."<<endl;
              }
         } 
		   else //else of degree.
		   {
             cout<<"Invalid degree! Please enter valid Degree (-180° to 180°)."<<endl;
         }

        cout<<"\nDo you want to enter another angle for navigation (Y, N): ";//prompt user if he want to enter another angle or not.
        cin>>choice;

    } while (choice == 'Y' || choice == 'y');//loop will iterate til user enter 'Y' or 'y'.

    cout<<endl;
    return 0;
}

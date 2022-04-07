#include <bits/stdc++.h>
using namespace std;

class flight
{
  private:
      int date;
      int month;
      int flight_capacity;
      int already_booked;
  public:
    /*
    Note: the flight price will be judged on the basis of end location
    */
    // locations
    vector<string> loc = {"HYD","DEL","MAA","BOM","CAA","AMD"};
    // relevant prices
    vector<int> price =  {7000,2000,4000,3000,4500,6000};
    // user status
    bool logged_in = true;
    // departure location
    string departure;
    // arrival location
    string arrival;
    // user bill
    int bill=0;

    // spacing function

    void spacing();
    void smol_spacing();
    /*
    Note: Below section contains food list
    */

    vector<string> veg={"Maggi","Sandwich","Burger"};
    vector<string> veg_codes = {"VM","VS","VB"};
    vector<int> veg_price={140,120,200};

    vector<string> non_veg={"Chicken Maggi","Chicken Sandwich","Chicken burger"};
    vector<string> non_veg_codes = {"CKM","CKS","CKB"};
    vector<int> non_veg_price ={200,240,350};

    vector<string> refreshments = {"Tea","Coffee","lemonade"};
    vector<string> refreshments_codes ={"TEE","CFF","LIM"};
    vector<int> refreshments_price = {70,90,50};
    map<string,int> food_item_qty;

    void display_veg();
    void display_non_veg();
    void display_refreshments();


    bool flag=true;

    bool exit_condition( bool flag);
    void choice();


    /*
    Note: this section is for the available capacity
    */

     // set flight capacity
     void setcap()
     {
         cout<<"Please set capacity of flight\n";
         int cap;
         cin >> cap;
         flight_capacity = cap;
     }

     // set number of seats booked
     void setbooked()
     {
         cout<<"Enter number of seats already booked\n";
         int b;
         cin >> b;
         // enter value till it's not less than or equal to total capacity
         while(!(b<flight_capacity))
         {
             cout<<"Enter value smaller than flight capacity\n";
             cin >> b;
         }
         flight_capacity -= b;
     }



    // date & month
    void settime()
    {
       cout<<"Please enter the date of your travel\n";
       cout<<"Format is Month : date\n";
       cout<<"Enter a month\n";
       int Month;
       cin >> Month;
       while(Month>12 || Month<1)
       {
           cout<<"Please enter valid month\n";
           cin >> Month;
           month = Month;
       }
       month = Month;

       cout<<"Enter a date\n";
       int Date;
       cin >> Date;
       while(Date >31 || Date<1)
       {
           cout<<"Please enter valid date\n";
           cin >> Date;
       }

          if(Month==2 || Month==4 || Month==6  || Month==9 || Month==11)
          {
              if(Month==2)
              {
                  if(Date>29)
                  {
                      cout<<"Please enter valid date less than 29/28\n";
                      while(Date>29 || Date<1)
                      {
                      cin >> Date;
                      date = Date;
                      }
                  }
                  else
                  {
                      date = Date;
                  }
              }
              else
              {
                  if(Date>30)
                  {
                      cout<<"Please enter valid date less than 31\n";
                      while(Date>30 || Date<1)
                      {
                      cin >> Date;
                      date = Date;
                      }
                  }
                  else
                  {
                      date = Date;
                  }
              }
          }

          date = Date;

    }
    // displaying user selected date and month
    void gettime()
    {
        cout<< "Booking date selected is: " << date <<" " << month <<"\n";
    }


     void check_seats();
     void fare_increase(int flight_capacity);


     /*
     Note: Below section contains display informations
     */

     // button for user to traverse
     void button();
     // condition to exit window
     bool exit();
     // display all available locations
     void check_available_locations();
     void display_locations();


     /*
     Note: This section contains functions relevant to booking
     */
     bool validity(string s);
     int price_checker(string s);
     void booking();

     /*
     Note: This section deals with the meals and other on flight luxuries
     */

     void button_commodities();

     /*
     Note: Final billing
     */
     void payment();
     void final_bill();
};

void flight:: spacing()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
}

void flight:: smol_spacing()
{
    cout<<"\n";
    cout<<"\n";
}

bool flight::exit_condition( bool flag)
{
        if(flag==true)
        {
            return true;
        }
        return false;
}

void flight::choice()
{
        cout<<"Please enter code of item you wish to purchase: \n";
        string chc;
        cin >> chc;
        int n = veg.size();
        for(int i=0 ; i<n ; i++)
        {
            if(veg_codes[i]==chc)
            {
                bill += veg_price[i];
                food_item_qty[veg_codes[i]]++;
            }
        }

        for(int i=0 ; i<n ; i++)
        {
            if(non_veg_codes[i]==chc)
            {
                bill += non_veg_price[i];
                food_item_qty[non_veg_codes[i]]++;
            }
        }

        for(int i=0 ; i<n ; i++)
        {
            if(refreshments_codes[i]==chc)
            {
                bill += refreshments_price[i];
                food_item_qty[refreshments_codes[i]]++;
            }
        }
}

void flight::display_veg()
{
        int  n= veg.size();
        for(int i=0 ; i<n ; i++)
        {
            cout<<"code: "<<veg_codes[i]<<" " <<veg[i] <<" price: " << veg_price[i] <<"INR \n";
        }
}

void flight::display_non_veg()
{
        int  n= non_veg.size();
        for(int i=0 ; i<n ; i++)
        {
            cout<<"code: "<<non_veg_codes[i]<<" "<<non_veg[i] <<" price: " << non_veg_price[i] <<"INR \n";
        }
}

void flight::display_refreshments()
{
        int n = refreshments.size();
        for(int i=0 ; i<n ; i++)
        {
            cout<<"code: "<<refreshments_codes[i]<<" "<< refreshments[i] <<" price: "<< refreshments_price[i] <<"INR \n";
        }
}

void flight::fare_increase(int flight_capacity)
{
         if(flight_capacity<=5)
         {
             bill += (0.05)*(bill/100) + bill;
         }
}

void flight::check_seats()
{
         smol_spacing();
         if(flight_capacity==0)
         {
             cout<<"Sorry no seats available  :-(\n";
         }
         else
         {
             cout<<"Total seats available are: "<< flight_capacity<<"\n";
         }
         smol_spacing();
}

void flight:: booking()
{
         cout<<"Enter Departure location\n";
         string dep;
         cin >> dep;
         while(!validity(dep))
         {
             cout<<"Please enter 3 digit valid code for departure location\n";
             cout<<"refer codes here:\n";
             check_available_locations();
             cin >> dep;
         }
         departure = dep;

         cout<<"Enter Arrival location\n";
         string arr;
         cin >> arr;
         while(!validity(arr) || (arr==departure))
         {
             smol_spacing();
             cout<<"Please enter 3 digit valid code for arrival location\n";
             cout<<"Please do not set arrival and departure locations same for a one way flight\n";
             cout<<"refer codes here:\n";
             check_available_locations();
             cin >> arr;
         }
         arrival = arr;
         bill += price_checker(arr);
         // this section works if number of seats is 5 or less
         fare_increase(flight_capacity);
         cout<<"You have selected a flight on: "<< date <<" "<< month <<" 2022 from: "<<departure <<" to "<<arrival <<"\n";

}

void flight:: final_bill()
{
         cout<<"Transaction summary\n";
         cout<<"Number seats booked:\n";
         cout<<"You have selected a flight on: "<< date <<" "<< month <<" 2022 from: "<<departure <<" to "<<arrival <<"\n";
         cout<<"Extra commodities selected: \n";
         for(auto it : food_item_qty)
         {
             cout<< it.first <<" Quantity: " <<it.second<<"\n";
         }
         cout<<"Your bill is: "<< bill <<" INR only\n";
         smol_spacing();
         cout<<"Proceed to payment ?\n";
         cout<<"Press 1 to proceed\n";
         int bttn;
         bool flag1=true;
         while(flag1)
         {
             cin >> bttn;
             if(bttn==1)
             {
                 flag1=false;
             }
         }
         smol_spacing();
         payment();
}

void flight:: payment()
{
    int pay;
    cout<<"Enter payment amount: \n";
    while(pay<bill)
    {
        cout<<"Enter amount correctly\n";
        cin >> pay;
    }
    if(pay==bill)
    {
        smol_spacing();
        cout<<"Thank you for choosing our airlines\n";
        cout<<"Your booking details will be sent to you via mail shortly\n";
    }
    else
    {
         smol_spacing();
         cout<<"Thank you for choosing our airlines\n";
         cout<<"extra amount"<< pay-bill <<" INR " <<"will be stored in our shell account for future bookings\n";
         cout<<"Your booking details will be sent to you via mail shortly\n";
    }

}
bool flight:: validity(string s)
{
    for(auto it : loc)
    {
        if(it==s)
        {
            return true;
            break;
        }
    }
    return false;
}

int flight::price_checker(string s)
{
    int idx=0;
    int cost=0;
    for(auto it : loc)
    {
        if(it!=s)
        {
            idx++;
        }
        else
        {
            break;
        }
    }
    cost = price[idx];
    return cost;
}

bool flight::exit()
{
    if(logged_in==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void flight::button_commodities()
{
    smol_spacing();
    cout<<"Welcome to our air shop press following buttons to get commodity of your choice :-)\n";
    cout<<"Enter 0 for Veg\n";
    cout<<"Enter 1 for Non Veg\n";
    cout<<"Enter 2 for refreshments\n";
    cout<<"Enter 3 to exit\n";
    smol_spacing();
    int press;
    cin >> press;
    if(press==0)
    {
         display_veg();
         choice();
    }
    else if(press==1)
    {
         display_non_veg();
         choice();
    }
    else if(press==2)
    {
         display_refreshments();
         choice();
    }
    else if(press==3)
    {
        flag=false;
    }
}

void flight::button()
{
    spacing();
    cout<<"Enter 0 to exit window\n";
    cout<<"Enter 1 for flight list\n";
    cout<<"Enter 2 for booking\n";
    cout<<"Enter 3 for meals and other services\n";
    cout<<"Enter 4 for final billing\n";
    cout<<"Enter 5 for checking available seats\n";
    smol_spacing();
    int a;
    cin >> a;
    int press = a;
    if(press==0)
    {
        logged_in=false;

    }
    else if(press==1)
    {
        check_available_locations();
    }
    else if(press==2)
    {
        booking();
    }
    else if(press==3)
    {
        while(exit_condition(flag))
        {
          button_commodities();
        }
    }
    else if(press==4)
    {
      final_bill();
      logged_in=false;
    }
    else if(press==5)
    {
        check_seats();
    }
    else
    {
    cout<<"Press a number from the following numbers\n";
    cout<<"Enter 0 to exit window\n";
    cout<<"Enter 1 for flight list\n";
    cout<<"Enter 2 for booking\n";
    cout<<"Enter 3 for meals and other services\n";
    cout<<"Enter 4 for final billing\n";
    cout<<"Enter 5 for checking available seats\n";
    }
}

void flight::check_available_locations()
{
    cout<<"Please check for your flight here: \n";
    display_locations();
}

void flight::display_locations()
{
  int n = loc.size();
  for(int i=0 ; i<n ; i++)
  {
      cout<< loc[i] <<" price:"<< price[i] <<"\n";
  }
}

int main()
{
    // object named flight created
    flight flight1;

    // setting flight capacity, no.of seats booked already  and setting date and time
    flight1.setcap();
    flight1.setbooked();
    flight1.settime();
    // button condition
    while(flight1.exit())
    {
     flight1.button();
    }
    return 0;
}

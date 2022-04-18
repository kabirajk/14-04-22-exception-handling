#include <iostream>

class Time_error:public std::exception
{   public:
    
    void print_error()
    {
        std::cout<<"Invalid time::";
    }
};
class TIME
{   public:
    int Time=0;
    TIME(int HH,int MM,int SS)
    {
        try
        {   
            if(HH>24||MM>60||SS>60)
            {
                Time_error timer;
                throw timer;
            }
        }
        catch(Time_error& timer)
        {
            timer.print_error();
        }
        Time+=HH<<6;
        Time+=MM;
        Time=(Time<<6)+SS;
    }
    void show_time()
    {
        std::cout<<(Time>>12)<<"HH:"<<((Time>>6)%64)<<"MM:"<<Time%64<<"SS"<<std::endl;
    }
};
int main()
{
    TIME t(17,48,16);
    t.show_time();
    return 0;
}

/*
ss 60 value can be stored in 6 bits of value 32 16 8 4 2 1
mm 60 value can be stored in 6 bits of value 32 16 8 4 2 1
hh 24 value can be stored in 5  bits of value 16 8 4 2 1
time=0
time+=HH<<6 means 6 is reserved for hh and it is shifted
24->1536;
time+=MM
60
now time|1536+60
now its 1596
to store next five bit we need to safe gaurd this 6 so <<6
1596<<6 ->102144
then add the seconds
102144+ss=102144+60=>102204

#to revert back

no_of_mm bits +no_of_ss bits =12
so right shit >>12
it gives HH=24
thent the mm is far from 6 bits
(shift>>6)%64 means 1596%64=60
we added secodns after minutes so wee need to clear secdodns bit so right shift>> 6 so we have the hh and ss enscripted 
as bit to get tme minute we moduls with 64 beacuse we need the value which is after 64 or 2^6 bit sequence

we added the ss last so we need the value after 64 in the bit sequence not of shifting

*/

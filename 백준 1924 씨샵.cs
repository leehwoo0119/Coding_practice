using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] days = new int[12] {31,28,31,30,31,30,31,31,30,31,30,31};
            string inputday = Console.ReadLine();
            string[] monthDay = inputday.Split();
            int Month = int.Parse(monthDay[0]);
            int day = int.Parse(monthDay[1]);

            int temp = 0;
            for(int i=0;i<Month - 1;i++)
            {
                temp += days[i];
            }
            temp += day;

            int daysNum = temp % 7;

            switch(daysNum)
            {
                case 0:Console.WriteLine("SUN"); break;
                case 1: Console.WriteLine("MON"); break;
                case 2: Console.WriteLine("TUE"); break;
                case 3: Console.WriteLine("WED"); break;
                case 4: Console.WriteLine("THU"); break;
                case 5: Console.WriteLine("FRI"); break;
                case 6: Console.WriteLine("SAT"); break;
                default: break;
            }
        }
    }
}

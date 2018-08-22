using System;

namespace SharpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            calc( Console.Read() );
        }

        static void calc(int n)
        {
            int i = 0;

            while(true)
            {
                //Console.WriteLine((int)Math.Sqrt(n));

                n -= (int)Math.Pow((int)Math.Sqrt(n), 2);
                i++;

                if (n == 0)
                    break;
            }

            Console.WriteLine(i);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestTask_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Write string:");
            string str = Console.ReadLine();

            var builder = new StringBuilder();

            str = str.ToLower();

            for (int i = 0; i<str.Length; i++)
            {
                if(str.LastIndexOf(str[i]) != str.IndexOf(str[i]))
                {
                    builder.Append(")");
                }
                else
                {
                    builder.Append("(");
                }
            }

            Console.WriteLine(builder);
            Console.ReadKey();
        }
    }
}

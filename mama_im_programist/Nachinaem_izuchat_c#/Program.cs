using System.Diagnostics.CodeAnalysis;
using System.Runtime.Intrinsics.Arm;

class My
{
    public  static  int sum(int a, int b)
    {
        return a + b;
    }
};

namespace Nachinaem_izuchat_c_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 200, b = 700, c = 400;
            Console.WriteLine(a);              //cw+tab = Console.Writelien();
            b = c;
            Console.WriteLine(b + c);
            Console.WriteLine("Hello, World!");
            string str = " ";
            str = Console.ReadLine();
            System.Console.WriteLine(str + " " + "!!!");
            My.sum(a, b);23
        }
    }
}

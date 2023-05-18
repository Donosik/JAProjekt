using System;
using System.Runtime.InteropServices;

namespace JAProjekt
{
    class Program
    {
        [DllImport(@"C:\Programming Projects\JAProjekt\JAProjekt\x64\Debug\JAAsm.dll")]
        static extern int dilatation(int a, int b,int c,int d,int e,int f,int g,int h);
        [DllImport(@"C:\Programming Projects\JAProjekt\JAProjekt\x64\Debug\JAAsm.dll")]
        static extern int erosion(int a, int b, int c, int d, int e, int f, int g, int h);
        static void Main(string[] args)
        {
            int retVal = erosion(1,1,1,1,0,1,1,1);
            Console.Write("Test: ");
            Console.WriteLine(retVal);
            Console.ReadLine();
        }

    }
}

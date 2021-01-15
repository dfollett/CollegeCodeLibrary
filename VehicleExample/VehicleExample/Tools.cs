using System;
using System.Text;

namespace Cars
{
    public static class Tools
    {
        public static string GenerateLicensePlate()
        {
            const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

            //initalize
            var sb = new StringBuilder();
            Random temp = new Random();

            //loops 6 times picking a new char from alphabet and appending it to stringbuilder sb.
            for (int i = 0; i <= 5; i++)
            {
                char c = alphabet[temp.Next(0, 36)]; //Next(x,y) uses type random to pick between x and y. neat trick.
                sb.Append(c);
            }
            return sb.ToString();
        }
    }
}
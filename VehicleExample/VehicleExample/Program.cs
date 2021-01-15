using System;
using System.Linq;
using System.Collections.Generic;

namespace Cars
{
    class Program
    {
        static void Main(string[] args)
        {
            //server = localhost; user id = root; persistsecurityinfo = True; database = world
            //initilizes 2 sedan's
            Sedan s1 = new Sedan(120,"automatic");
            Sedan s2 = new Sedan(85,"manual");

            //initilizes 2 semi's
            Semi t1 = new Semi(80, "manual", 300);
            Semi t2 = new Semi(100, "automatic", 1000);

            //initilizes a bike
            StreetBike b1 = new StreetBike(210, "paddle shifter");



            //prints out formatted information about vehicles
            s1.Describe();
            s1.Honk();
            Console.WriteLine("\n\n\n");

            s2.Describe();
            s2.Honk();
            Console.WriteLine("\n\n\n");

            t1.Describe();
            t1.Honk();
            Console.WriteLine("\n\n\n");

            t2.Describe();
            t2.Honk();
            Console.WriteLine("\n\n\n");

            b1.Describe();
            b1.Honk();



        }
    }
}
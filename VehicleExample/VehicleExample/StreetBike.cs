using System;

namespace Cars
{
    class StreetBike : Vehicle, IAutomobile
    {
        //properties
        public int Wheels
        { get; protected set; }

        //constructor
        public StreetBike(int speed, string transmission) : base(speed, transmission)
        {
            Wheels = 2;
        }


        //methods
        //ASCII thanks to Jergen Grener at https://ascii.co.uk/art/motorcycles
        public override void Describe()
        {
            string bike = @"
            r==
        _  //
       |_)//(''''':
         //  \_____:_____.-----.P
        //   | ===  |   /        \
    .:'//.   \ \=|   \ /  .:'':.
   :' // ':   \ \ ''..'--:'-.. ':
   '. '' .'    \:.....:--'.-'' .'
    ':..:'                ':..:'
 ";
            Console.WriteLine(bike);
            Console.WriteLine($"a StreetBike was created with the license plate:  {LicensePlate}\n It has {Wheels} wheels.\n it's max speed is: {MaxSpeed} mph\n");
        }

        public override void Honk()
        {
            Console.WriteLine("\tBikes sound like this: meep!!\n\n\n");
        }

    }
}
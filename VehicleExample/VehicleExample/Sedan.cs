using System;

namespace Cars
{
    class Sedan : Vehicle, IAutomobile //implements automobiles interface
    {
        //most properties are handled through inheritance of Vehicle

        public int Wheels
        { get; protected set; }

        //constructor
        public Sedan(int speed, string transmission) : base(speed, transmission)
        {
            this.Wheels = 4;
    }

        //methods

        public override void Describe()
        {
            //ascii cars thanks to Colin Douthwaite at https://www.asciiart.eu/vehicles/cars
            if (Transmission == "automatic")
            {
                string autoCar = @"
        _______
       // A||\ \
 _____//___||_\ \___
 )  _          _    \
 |_/-\________/-\___|
___\-/________\-/______
 ";
                Console.WriteLine(autoCar);
            }

            if (Transmission == "manual")
            {
                string manualCar = @"                 
                 
        _______
       // M||\ \
 _____//___||_\ \___
 )  _          _    \
 |_/ \________/ \___|
___\_/________\_/______
";
                Console.WriteLine(manualCar);
            }

            Console.WriteLine($"A sedan was created with a license plate of : {LicensePlate}\n It's max speed is: {MaxSpeed}mph\n It has {Wheels} wheels and {Doors} doors.\n Lastly, It has a {Transmission} transmission. \n");
        }
    }
}
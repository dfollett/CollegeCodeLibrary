using System;

namespace Cars
{
    class Semi : Vehicle, IAutomobile //implements automobiles interface
    {
        //most properties are handled through inheritance

        public int Weight
        { get; private set; }

        public int Wheels
        { get; protected set; }

        //constructor
        public Semi(int speed, string transmission, int weight) : base(speed, transmission)
        {
            this.Wheels = 4;
            this.Weight = weight;

            if (weight < 500)
            {
                Wheels = 6;
            }
            else
            {
                Wheels = 10;
            }
        }

        //methods
        public override void Honk()
        {
            Console.WriteLine("\t Semi's sound like this:  HONK!!\n\n\n");
        }

        //prints out vehicle info ASCII is thanks to unknown artist at https://www.asciiart.eu/vehicles/trucks
        public override void Describe()
        {
            if (Wheels == 10) {
                string bigTruck = @"                       
                       _____________________________________________________
                      |                                                     |
             _______  |                                                     |
            / _____ | |                       ACME MOO-VERS                 |
           / /(__) || |                                                     |
  ________/ / |OO| || |                                                     |
 |         |-------|| |                                                     |
(|         |     -.|| |_______________________                              |
 |  ____   \       ||_________||____________  |             ____      ____  |
/| / __ \   |______||     / __ \   / __ \   | |            / __ \    / __ \ |\
\|| /  \ |_______________| /  \ |_| /  \ |__| |___________| /  \ |__| /  \|_|/
   | () |                 | () |   | () |                  | () |    | () |
    \__/                   \__/     \__/                    \__/      \__/ ";
                Console.WriteLine(bigTruck);
            }

            if (Wheels == 6) {
                string littleTruck = @"                         
             _______ 
            / _____ | 
           / /(__) || 
  ________/ / |OO| || 
 |         |-------|| 
(|         |     -.|| 
 |  ____   \       ||_________||____________ 
/| / __ \   |______||     / __ \   / __ \   | 
\|| /  \ |_______________| /  \ |_| /  \ |__| 
   | () |                 | () |   | () |     
    \__/                   \__/     \__/       ";
                Console.WriteLine(littleTruck);
            }
            Console.WriteLine($"A Semi was created with a license plate of : {LicensePlate}\n It's max speed is: {MaxSpeed}mph\n It has {Wheels} wheels and {Doors} doors.\n It has a {Transmission} transmission.\n Lastly, it weights {Weight}lbs! \n");
        }

    }
}
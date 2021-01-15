using System;

namespace Cars
{
    abstract class Vehicle
    {
        public string LicensePlate
        { get; protected set; }

        public int MaxSpeed
        { get; protected set; }

        public int Doors
        { get; protected set; }

        public string Transmission
        { get; protected set; }

        public Vehicle(int speed, string transmission)
        {
            MaxSpeed = speed;
            LicensePlate = Tools.GenerateLicensePlate();

            this.MaxSpeed = speed;
            Transmission = transmission;
            LicensePlate = Tools.GenerateLicensePlate();
            this.Doors = 4;
        }

        public virtual void Honk()
        {
            Console.WriteLine(" This vehicle sounds like this: honk!");
        }

        public abstract void Describe();

    }
}
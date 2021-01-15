using System;

namespace Cars
{
    interface IAutomobile
    {
        string LicensePlate { get; }
        int MaxSpeed { get; }
        int Wheels { get; }
        int Doors { get; }
        string Transmission { get; }
        void Honk();
    }
}

using System;
using System.Collections.Generic;

namespace variancesample
{
    class Program
    {
        static void Main(string[] args)
        {
            Base b = new Base();
            //Derived d = (Derived)b;         // casting is needed (fails at runtime)

            Derived d1 = new Derived();
            Base b1 = d1;                   // no casting is needed


            List<Derived> derivedList=  new List<Derived>();
            // List<Base> baseList = derivedList;      // won't work as List<Derived> is not derived from List<Base>
            IEnumerable<Base> baseList = derivedList;      // Works because IEnumerable<out T> , as IEnumerable is marked as Covariance

            Func<Base> func;
            func = () => GetDerived();  // can do this because Func was defined as Func<out TResult>
            func();

            Action<Base> bb = Do2;
            Action<Derived> dd = Do;
            bb(new Base());
            dd(new Derived());

            //Action<Base> bb1 = Do;          // not possible
            Action<Derived> dd2= Do2;         // Can pass Derived object as Action<In> was defined contravariance
            dd2(new Derived());
        }

        static Derived GetDerived()
        {
            return new Derived();
        }

        static void Do(Derived d)
        {
            Console.WriteLine(d.ToString());
        }

        static void Do2(Base b)
        {
            Console.WriteLine(b.ToString());
        }

    }
}

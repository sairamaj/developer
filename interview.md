* [Displaying Technical Skill Is Only Half the Battle](https://msdn.microsoft.com/en-us/magazine/mt808497)
* [Age Before Beauty: Success and the Older Developer](https://msdn.microsoft.com/en-us/magazine/mt793266)

### OOPs
* Encaptulation
    * Hiding state and packging related stuff.
    * Methods used and state is hidden.
    * Help us in develop and maintain a big code base
    * Also known as data hiding
    * Full control on data by using the code
* Abstraction
    * Process of hidiing the implementation details from the user
    * The user will have the information on what the object does instead of ohow it does it.
    * Exposing high level of mechanism for using it
    * Interface is the best example of abstraction
    * Hiding internal implementation of details and reveal operations relevant for other objects
    * Help us in develop and maintain a big code base
    * Deals with the outside view of an object ( hide specific details)
* Inheritance
    * One of way of Reuse 
* Polymorphism
    * Means many shapes in greek
    * Gives a way to use a class exactly like its parent so there is no confusion with mixing types. But each child class keeps its own methods    as they are.
    * Perform a signle action in different ways.
[OOPs](https://medium.com/from-the-scratch/oop-everything-you-need-to-know-about-object-oriented-programming-aee3c18e281b)

### Covariant and Contravariance
[Covariance and Contravariance in C#](https://blogs.msdn.microsoft.com/ericlippert/2007/10/16/covariance-and-contravariance-in-c-part-one/)
* Covariance
    * Enables you to use a more derived type than originally specified
    * You can assign an instance of IEnumerable<Derived> to a vairable of IEnumerable<Base>
    ```csharp
            List<Derived> derivedList=  new List<Derived>();
            // List<Base> baseList = derivedList;      // won't work as List<Derived> is not derived from List<Base>
            IEnumerable<Base> baseList = derivedList;      // Works because IEnumerable<out T> , as IEnumerable is marked as Covariance
    ```
* Contravariance
    * Enables you to use a more generic (less derived) type than originally specified.
    * You can assign an instance of Action<Base> to a variable of type Action<Derived>.
    ```csharp
          static void Do2(Base b)
        {
            Console.WriteLine(b.ToString());
        }

         Action<Derived> dd2= Do2;   // Can pass Derived object as Action<In> was defined contravariance
    ```
* Invariance
    * Means that you can use only the type originally specified; so an invariant generic type parameter is neither covariant nor contravariant.
    * You cannot assign an instance of List<Base> to a variable of type List<Derived> or vice versa.

[TOGAF](https://pubs.opengroup.org/architecture/togaf9-doc/arch/?ref=wellarchitected-wp)
[Zacman Framework](https://www.zachman.com/about-the-zachman-framework?ref=wellarchitected-wp)
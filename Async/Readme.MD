* Concurrency
* Multi threading
* Parallel programming
* Asynchronous programming

Task<>.Fatctory.Run is not asynchronous program (they are thread base tasks). This is  parallel programming as you are running in different thread

![taskvsolderasync](https://github.com/sairamaj/developer/blob/master/images/taskvsolderasync.png)

[There is no thread for pure async](https://blog.stephencleary.com/2013/11/there-is-no-thread.html)

[IOCompletioninC#](https://github.com/dschenkelman/async-io-talk)


## Best practices

| Name               |  Description                                      | Exceptions                       |
|------------------- |------------------------------------------------   |-------------------------------   |
| Avoid async void   | Prefer async Task methods over async void methods |  Event handlers                  |
| Async all the way  | Don’t mix blocking and async code                 |  Console main method             |
| Async all the way  | Use ConfigureAwait(false) when you can            |  Methods that require con­text    |
		

* sync void methods have different error-handling semantics. When an exception is thrown out of an async Task or async Task<T> method, that exception is captured and placed on the Task object. With async void methods, there is no Task object, so any exceptions thrown out of an async void method will be raised directly on the SynchronizationContext that was active when the async void method started. 
*  Async methods returning void don’t provide an easy way to notify the calling code that they’ve completed. It’s easy to start several async void methods, but it’s not easy to determine when they’ve finished. Async void methods will notify their SynchronizationContext when they start and finish

[Best Practice](https://msdn.microsoft.com/en-us/magazine/jj991977.aspx)
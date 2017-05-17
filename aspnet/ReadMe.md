# Katana
* Katana is based on OWIN specification
* Lightweight
* Portable

# Developing a webserver console
* Create console app
* Install-Package -IncludePreRelease Microsoft.Owin.Hosting
* Install-Package -IncludePreRelease Microsoft.Owin.Hosting.HttpListener
* Additional
    * Install-Package -IncludePrerelease Microsoft.Owin.Diagnostics
* AppFunc
    * Func<IDictionary<string,object>, Task    
* Pipeline model


# Writing component ( also called Middleware)
```csharp
    using AppFunc = Func<IDictionary<string,object>,Task>;
	public class Startup
	{
		public void Configuration(IAppBuilder app)
		{
			app.Use<HelloComponent>();
		}
	}
	public class HelloComponent
	{
		private readonly AppFunc _next;

		public HelloComponent(AppFunc next)
		{
			_next = next;
		}

		public async Task Invoke(IDictionary<string, object> environment)
		{
			await _next(environment);
		}
	}
```

### Writing custom extension method to make it easy (optional)
```csharp
	/// <summary>
	/// With this extension it will be easy for others to use with app.UseHelloWorld();
	/// </summary>
	public static class AppBuilderExtensions
	{
		public static void UseHelloWorld(this IAppBuilder app)
		{
			app.Use<HelloComponent>();
		}
	}
```
### Run method
* No need to write separate class
```csharp
    app.Run(ctx => ctx.Response.WriteAsync("Hello World!"));
```
* Katana adds this


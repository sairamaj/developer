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

Host -> Server -> Katana -> Application(WebAPI/MVC)

### Authentications in MVC
* No Authentication
* Individual User Accounts(password based, Google,Microsoft,Facebook identities)
* Organizational Accounts (Azure active directory , federated)
* Windows Authentication

### Enabling SSL in ASP.NET Core in Visual studio

```csharp
        public void ConfigureServices(IServiceCollection services)
        {
            services.Configure<MvcOptions>(options =>
            {
                options.Filters.Add(new RequireHttpsAttribute());
            });
            // Add framework services.
            services.AddMvc();
        }
```
* Install package Microsoft.AspnetCore.Rewrite
  * dotnet add package Microsoft.AspnetCore.Rewrite
* In Configure method
```csharp
            var options = new RewriteOptions()
               .AddRedirectToHttps();

            app.UseRewriter(options);
```
* Install package Microsoft.AspNetCore.Server.Kestrel.Https
  * dotnet add package Microsoft.AspNetCore.Server.Kestrel.Https
```csharp
   public static void Main(string[] args)
        {
            var host = new WebHostBuilder()
                .UseKestrel(options=> {
                    options.UseHttps("localhost.pfx","password");
                })
                .UseContentRoot(Directory.GetCurrentDirectory())
                .UseIISIntegration()
                .UseUrls("https://*:4430")
                .UseStartup<Startup>()
                .Build();

            host.Run();
        }
```
* make certificate
  * makecert" -sv localhost.pvk -n "CN=localhost" localhost.cer -r
  * pvk2pfx.exe" -pvk localhost.pvk -spc localhost.cer -pfx localhost.pfx -pi password
* dotnet run

At this time application will run https://localhost:4430

[Source](http://www.blinkingcaret.com/2017/03/01/https-asp-net-core/)

[Source](https://wildermuth.com/2016/10/26/Testing-SSL-in-ASP-NET-Core)





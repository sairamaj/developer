using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
using Microsoft.Owin.Hosting;
using Owin;


namespace WebConsoleUsingKatana
{
	using AppFunc = Func<IDictionary<string,object>,Task>;
	class Program
	{
		static void Main(string[] args)
		{
			var uri = "http://localhost:8080";

			using (WebApp.Start<Startup>(uri))
			{
				Console.WriteLine("Started!");
				Console.ReadLine();
				Console.WriteLine("done");
			}
		}
	}

	public class Startup
	{
		public void Configuration(IAppBuilder app)
		{
			app.Use(async (env, next) =>
			{
				foreach (var pair in env.Environment)
				{
					Console.WriteLine("{0}-{1}", pair.Key, pair.Value);
				}

				await next();
			});
			//app.UseWelcomePage();
			//app.Run(ctx => ctx.Response.WriteAsync("Hello World!"));

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

		//public async Task Invoke(IDictionary<string, object> environment)
		//{
		//	await _next(environment);
		//}

		public Task Invoke(IDictionary<string, object> environment)
		{

			var response = environment["owin.ResponseBody"] as Stream;
			using (var writer = new StreamWriter(response))
			{
				return writer.WriteAsync("!Hello");
			}
		}

	}

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
}

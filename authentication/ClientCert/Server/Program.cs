using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Security.Cryptography.X509Certificates;
using System.Threading.Tasks;
using idunno.Authentication.Certificate;
using Microsoft.AspNetCore;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Server.Kestrel.Https;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Logging;

namespace Server
{
    public class Program
    {
        public static void Main(string[] args)
        {
            CreateWebHostBuilder(args)
            .UseUrls("https://localhost:5001")
            .Build().Run();
        }

        public static IWebHostBuilder CreateWebHostBuilder(string[] args) =>
            WebHost.CreateDefaultBuilder(args)
                .UseStartup<Startup>()
                .UseKestrel(options =>
           {
               options.Listen(IPAddress.Loopback, 5001, listenOptions =>
               {
                   listenOptions.UseHttps(new HttpsConnectionAdapterOptions
                   {
                        ServerCertificate = GetCert("44CB3F821C21666745DDACA9F7F27B35DE537DC5"),
                        ClientCertificateMode = ClientCertificateMode.RequireCertificate,
                        ClientCertificateValidation = CertificateValidator.DisableChannelValidation,

                   });
               });
           });
        public static X509Certificate2 GetCert(string thumbprint)
        {
            System.Console.WriteLine($"Get certificate: {thumbprint}");
            using (var certStore = new X509Store(StoreName.My, StoreLocation.LocalMachine))
            {
                certStore.Open(OpenFlags.ReadOnly);
                var certCollection = certStore.Certificates.Find(
                                           X509FindType.FindByThumbprint,
                                            thumbprint,
                                           false);
                System.Console.WriteLine($"cert collection: {certCollection.Count}");
                // Get the first cert with the thumbprint
                if (certCollection.Count > 0)
                {
                    X509Certificate2 cert = certCollection[0];
                    // Use certificate
                    Console.WriteLine(cert.FriendlyName);
                    return cert;
                }
            }
            throw new ArgumentException($"Certificate :{thumbprint} not found");
        }
    }
}

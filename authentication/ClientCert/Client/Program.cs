using System;
using Pathoschild.Http.Client.Formatters;
using Pathoschild.Http.Client;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.IO;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            var handler = new System.Net.Http.HttpClientHandler();
            using (var httpClient = new System.Net.Http.HttpClient(handler))
            {
                var clientCert = GetClientCert();
                handler.ClientCertificates.Add(clientCert);
                handler.ServerCertificateCustomValidationCallback = (request, cert, chain, errors) =>
                {
                    // Log it, then use the same answer it would have had if we didn't make a callback.
                    Console.WriteLine(cert);
                    return errors == SslPolicyErrors.None;
                };

                var client = new Pathoschild.Http.Client.FluentClient("https://localhost:5001/", httpClient);
                var response = client.GetAsync("Home")
                .AsResponse()
                .Result;
                System.Console.WriteLine(response.Status);
                System.Console.WriteLine(response.Message);
            }
        }

        static X509Certificate GetClientCert(){
            //return new X509Certificate("clientauthcert.pfx","123456");
            
            var x509 = new X509Certificate2(File.ReadAllBytes("clientauthcert.pfx"),"123456");
            return x509;
        }
    }
}

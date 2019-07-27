create mvc
show the page
add authorize attribute
browse-> error
add app registration
	-https://localhost:5000/signout-oidc
edit
	- enable id tokens
in project
	edit appsettings.json
		- update tenantid, client id, url
	adding package
		dotnet add package Microsoft.AspNetCore.All --version 2.2.6
	add 2 extension class
	add middleware in startup.cs
	app.UseAuthentication();	
	
viewing claims
	add class ProfileController

        public IActionResult Index()
        {
            return View(User.Claims);
        }

	add view
	@{
    ViewData["Title"] = "Home Page";
}


@model IEnumerable<System.Security.Claims.Claim>

<dv>
<table border="1" cellpadding="10">
                    <th>Type</th>
                    <th>Value</th>
                                    
            @foreach(var claim in Model.OrderBy(c=> c.Type)){
                 <tr>
                    <td>@claim.Type </td>
                    <td>@claim.Value </td>
                </tr>
            }
</table>
</dv>

   upade _layout.cshtml 
	edit privacy to profile
	<a class="nav-link text-dark" asp-area="" asp-controller="Profile" asp-action="Index">Profile</a>
	
[source](https://github.com/Azure-Samples/active-directory-dotnet-webapp-openidconnect-aspnetcore)

# enabling without code (Easy Auth)
  - comment out startup (middleware and also di)
  - remove authorize attribute.
  - checkin
  - see the authorization removed and no claims
  - enable authorization
  - use existing app
  - browse
  - get error
  - add reply url
	https://saiauthtest.azurewebsites.net/.auth/login/aad/callback
[source](https://docs.microsoft.com/en-us/azure/app-service/overview-authentication-authorization)

[claims(https://www.benday.com/2018/05/21/walkthrough-part-5-asp-net-core-claims-based-security-using-azure-app-authentication-the-auth-me-service-endpoint/)
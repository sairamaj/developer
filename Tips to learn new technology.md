## Tips to learn new technology
* You tube videos
* Blogs
* Offical documentation
* Hands on through Quick tutorial if any
* Sometimes you may not understand in the begining but as you keep reading/listening the same material you will get slowly. Some times the same material through different media(blogs/videos) will give different perspective.
* If you find new jargons and don't understand them, then jump and quickly get overview of those jargons/acrynysm/technoligies.

## Tips to learn existing application
* Understanding the application as user.
* Get the code from appropriate and just browsing
* Correlate the Application interface if it is UI or Application functionality(if it is backend) to the Code.
* If appication is using any well known frameworks , jump to online and understand the framework. Example: React , Angular or any other framework.
* Initially it will be overwhelming by looking at the code but you don't have to understand entire code base at once. As you keep working on application understanding all connected application code is essential (at least integration layers)

## Lets apply this to Octa
Before learning Octa one needs to understand the OAuth2.0 and [here is the simplified version of it](https://aaronparecki.com/oauth-2-simplified/)

Start from here: [How Octa works](https://developer.okta.com/docs/concepts/how-okta-works/#what-you-can-do-with-okta)

[Read this various entities - Don't worry if you don't understand. Just read and can come back to this again](https://developer.okta.com/docs/concepts/okta-data-model/)

[Get quick overview of Octa](https://support.okta.com/help/s/article/what-is-okta?language=en_US#:~:text=Okta%20is%20an%20enterprise%2Dgrade,Jun%2028%2C%202022)

[Not much info, but you may get something with this short funny video](https://www.youtube.com/watch?v=11SL-NnGp4E)


[Developer documentation](https://developer.okta.com/)

## Okta Quick tutorial
* Registering
  * [Signup](developer.okta.com/signup)
  * You can use your google account.
* Using CLI
  * Download CLI
  * Okta commands
  ```cmd
    okta login
    give URI as: https://dev-43263525.okta.com  (replace the number)
    It will ask for API token and at this time go to Okta admin portal and create token
    
  ```
[Sample App React](https://github.com/okta/samples-js-react/tree/master/custom-login)
[Using Octa from React app - client side](https://developer.okta.com/docs/guides/sign-into-spa-redirect/react/main/)

[Using Octa from Java app - server side](https://developer.okta.com/docs/guides/sign-into-web-app-redirect/spring-boot/main/)

[Trying Octa in ASP.NET application - Skip this as this is for](https://support.okta.com/help/s/article/what-is-okta?language=en_US#:~:text=Okta%20is%20an%20enterprise%2Dgrade,Jun%2028%2C%202022)

## Dont use this for now
[Overview](https://www.youtube.com/watch?v=V5M9zaxE1mc)
* Skip 5:30 to 15:00 
* 15:00 shows Octa in action
* Watch for 2mins 
* New acrynyms found
  * B2C, B2E, B2B
  * MFA, SSO
  * Identity management

____
base64 encode and decode
use wsl
at command
```cmd
  echo -n "123456" | base64
  echo "MTIzNDU2Cg==" | base64 -d
```

____
* az extension list-available
* [tutorial](https://www.youtube.com/watch?v=WOxjyJgw-ZY)
* [sample](https://microsoft.github.io/AzureTipsAndTricks/blog/tip200.html)
* [Authoring command modules](https://github.com/Azure/azure-cli/blob/master/doc/authoring_command_modules/README.md)
* To get access token from portal
  * ```python
    from azure.cli.command_modules.profile.custom import get_access_token
    access_token = get_access_token(cmd, resource=PORTAL_API_RESOURCE)
    ```
* Call API
  * ```python

    from azure.cli.core.commands.client_factory import get_subscription_id
    from azure.cli.command_modules.profile.custom import get_access_token
    from msrest.service_client import ServiceClient
    from msrest import Configuration
    from msrest.universal_http import ClientRequest
    from msrest.exceptions import (
        ClientException,
        ClientRequestError,
        AuthenticationError,
    )
    from azure.cli.core.commands import LongRunningOperation
    from azure.cli.core.util import sdk_no_wait

    def api_get(path, access_token):
        config = Configuration(base_url=None)
        client = ServiceClient(creds=None, config=config)
        request = ClientRequest(method='GET',
                                url=f'{PORTA_URL}/{path}')
        request.Verify = False

        headers = {'Authorization': f'Bearer {access_token}'}
        response = client.send(request=request, headers=headers)
        if response.status_code != 200:
            raise ClientRequestError(f'status {response.status}')
        return response.json()

    def api_post(path, access_token, data=None):
        config = Configuration(base_url=None)
        client = ServiceClient(creds=None, config=config)
        request = ClientRequest(method='POST',
                                url=f'{PORTA_URL}/{path}')
        request.Verify = False
        headers = {'Authorization': f'Bearer {access_token}'}
        response = client.send(request=request, headers=headers)
        if response.status_code != 200:
            raise ClientRequestError(f'status {response.status}')
        if len(response.content) > 0:
            try:
                return response.json()
            except ValueError:
                return None
        return None
    ```
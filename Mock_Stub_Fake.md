## SUT
   * System Under Test (primary object)
## Collaborators
   * (secondary objects)

## state verification
   * which means that we determine whether the exercised method worked correctly by examining the state of the SUT and its collaborators after the method was exercised ( for ex: check numberofMessagesSent==4 for mail service collaborator.)
## behavior verification
   *  where we instead check to see if the order made the correct calls on the warehouse. We do this check by telling the mock what to expect during setup and asking the mock to verify itself during verification  ( ex: is method Sent has been called on collaborator) 
## Test Double 
   * generic term for any kind of pretend object used in place of a real object for testing purposes   

### Dummy 
   * objects are passed around but never actually used. Usually they are just used to fill parameter lists.

### Fake 
   * objects actually have working implementations, but usually take some shortcut which makes them not suitable for production (an in memory database is a good example).
### Stubs 
   * provide canned answers to calls made during the test, usually not responding at all to anything outside what's programmed in for the test.
### Spies 
   * are stubs that also record some information based on how they were called. One form of this might be an email service that records how many messages it was sent.
### Mocks 
   * objects pre-programmed with expectations which form a specification of the calls they are expected to receive

__stub__ uses state verification while the __mock__ uses behavior verification

The __classical TDD__ style is to use real objects if possible and a double if it's awkward to use the real thing. So a classical TDDer would use a real warehouse and a double for the mail service. The kind of double doesn't really matter that much.

A __mockist TDD__ practitioner, however, will always use a mock for any object with interesting behavior. In this case for both the warehouse and the mail 
service.
__Source__ [Mocks Aren't Stubs](https://www.martinfowler.com/articles/mocksArentStubs.html)
